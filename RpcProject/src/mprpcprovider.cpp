#include "mprpcprovider.h"
#include "mprpcapplication.h"
#include <functional>
#include "rpcheader.pb.h"
#include "zookeeperutil.h"
//框架提供给外部使用，发布rpc方法函数接口
void RpcProvider::NotifyService(google::protobuf::Service *service)
{
    ServiecInfo serviceinfo;
    //获取服务对象的描述信息
    const google::protobuf::ServiceDescriptor *pserviceDesc = service->GetDescriptor();
    //获取服务的名字
    std::string service_name = pserviceDesc->name();
    //获取服务对象方法的数量
    int methodCnt = pserviceDesc->method_count();

    std::cout << "Service name:" << service_name << std::endl;
    LOG_INF("Service name:%s", service_name.c_str());
    for (int i = 0; i < methodCnt; ++i)
    {
        //获取服务对象下的服务方法描述
        const google::protobuf::MethodDescriptor *pmethodDesc = pserviceDesc->method(i);
        std::string method_name = pmethodDesc->name();
        serviceinfo.m_methodMap.insert({method_name, pmethodDesc});
        std::cout << "Method name:" << method_name << std::endl;
        LOG_INF("Method name:%s", method_name.c_str());
    }
    serviceinfo.m_service = service;
    m_serviceMap.insert({service_name, serviceinfo});
}
//启动rpc服务节点，开始提供rpc远程网络调用服务
void RpcProvider::Run()
{
    std::string ip = MprpcApplication::getInstance().getConfig().load("rpcserviceip");
    uint16_t port = atoi(MprpcApplication::getInstance().getConfig().load("rpcserviceport").c_str());
    muduo::net::InetAddress address(ip, port);

    //创建TcpServer对象
    muduo::net::TcpServer server(&m_eventLoop, address, "mprpc");
    //绑定连接回调 消息回写回调
    server.setConnectionCallback(std::bind(&RpcProvider::onConnection, this, std::placeholders::_1));
    server.setMessageCallback(std::bind(&RpcProvider::onMessage, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
    //设置线程数量
    server.setThreadNum(4);

    ZKClient zkclient;
    zkclient.Start();
    //向zk注册服务方法信息
    for (auto &sp : m_serviceMap)
    {
        std::string server_path = "/" + sp.first;
        zkclient.Create(server_path.c_str(), nullptr, 0);
        for (auto &m_method : sp.second.m_methodMap)
        {
            std::string method_path = server_path + "/" + m_method.first;
            /* std::string host_port = ip + ":" + MprpcApplication::getInstance().getConfig().load("rpcserviceport"); */
            char method_data[128] = {0};
            sprintf(method_data, "%s:%d", ip.c_str(), port);
            zkclient.Create(method_path.c_str(), method_data, strlen(method_data), ZOO_EPHEMERAL);
        }
    }

    std::cout << "Rpcprovider service start at ip:" << ip << " port:" << port << std::endl;
    LOG_INF("Rpcprovider service start at ip:%s port:%d", ip.c_str(), port);
    //启动网络服务
    server.start();
    m_eventLoop.loop();
}
//新连接回调
void RpcProvider::onConnection(const muduo::net::TcpConnectionPtr &conn)
{
    if (conn->connected())
    {
        std::cout << "Connectied..." << std::endl;
    }
    else
    {
        std::cout << "Disconnectied..." << std::endl;
        conn->shutdown();
    }
}
//Closure的回调操作
void RpcProvider::SendRpcSponse(const muduo::net::TcpConnectionPtr &conn, google::protobuf::Message *response)
{
    std::string response_str;
    if (response->SerializeToString(&response_str)) //序列化
    {
        conn->send(response_str);
    }
    else
    {
        LOG_ERRO("SerializeToString error.");
    }
    conn->shutdown(); //主动断开连接
}
/*
在框架内部，RpcProvider和RpcConsumer协商好通信用的protobuf数据类型 
 service_name method_name arg_name
 [header(4字节)]---[service_name,method_name]---[args_size+args_name]
 */
//已建立连接，读写事件回调
void RpcProvider::onMessage(const muduo::net::TcpConnectionPtr &conn, muduo::net::Buffer *buffer, muduo::Timestamp time)
{
    std::string recv_buf = buffer->retrieveAllAsString(); //接受rpc字符流
    //从字符流中读取前四个字节的内容
    uint32_t header_size = 0;
    recv_buf.copy(reinterpret_cast<char *>(&header_size), 4, 0);
    //读取数据头的原始字符流,反序列化数据，得到rpc请求的详细信息
    std::string rpc_header_str = recv_buf.substr(4, header_size);
    mprpc::RpcHeader rpcheader;
    std::string service_name;
    std::string method_name;
    uint32_t args_size;
    if (rpcheader.ParseFromString(rpc_header_str))
    {
        //反序列成功
        service_name = rpcheader.service_name();
        method_name = rpcheader.method_name();
        args_size = rpcheader.args_size();
    }
    else
    {
        //反序列失败
        LOG_ERRO("rpc_header_str:%s parse error.", rpc_header_str.c_str());
        return;
    }
    std::string args_str = recv_buf.substr(4 + header_size, args_size);
    //打印调试信息
    /* std::cout << "-----------------------------provider----------------------------" << std::endl;
    std::cout << "header_size:" << header_size << std::endl;
    std::cout << "rpc_header_str:" << rpc_header_str << std::endl;
    std::cout << "service_name:" << service_name << std::endl;
    std::cout << "method_name:" << method_name << std::endl;
    std::cout << "args_size:" << args_size << std::endl;
    std::cout << "args_str:" << args_str << std::endl;
    std::cout << "-----------------------------------------------------------------" << std::endl; */
    //获取service对象和method
    auto it = m_serviceMap.find(service_name);
    if (it == m_serviceMap.end())
    {
        LOG_ERRO("%s is not exist!", service_name.c_str());
        return;
    }
    auto mit = it->second.m_methodMap.find(method_name);
    if (mit == it->second.m_methodMap.end())
    {
        LOG_ERRO("%s is not exist!", method_name.c_str());
        return;
    }
    google::protobuf::Service *service = it->second.m_service;
    const google::protobuf::MethodDescriptor *method = mit->second;

    //生成rpc方法request和response参数
    google::protobuf::Message *request = service->GetRequestPrototype(method).New();
    if (!request->ParseFromString(args_str))
    {
        LOG_ERRO("Request parse err,content:%s", args_str.c_str());
        return;
    }
    google::protobuf::Message *response = service->GetResponsePrototype(method).New();

    //绑定一个closure回调
    google::protobuf::Closure *down = google::protobuf::NewCallback<RpcProvider, const muduo::net::TcpConnectionPtr &, google::protobuf::Message *>(this, &RpcProvider::SendRpcSponse, conn, response);
    //在框架上根据远端rpc请求，调用当前发布的方法
    service->CallMethod(method, nullptr, request, response, down);
}
