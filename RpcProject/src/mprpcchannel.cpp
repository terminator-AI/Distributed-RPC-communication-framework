#include "mprpcchannel.h"
#include "rpcheader.pb.h"
#include "mprpccontroller.h"
#include "mprpcapplication.h"
#include "zookeeperutil.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

void MprpcChannel::CallMethod(const google::protobuf::MethodDescriptor *method,
                              google::protobuf::RpcController *controller, const google::protobuf::Message *request,
                              google::protobuf::Message *response, google::protobuf::Closure *done)
{
    const google::protobuf::ServiceDescriptor *sd = method->service();
    std::string service_name = sd->name();
    std::string method_name = method->name();

    //获取参数序列化字符串长度
    std::string args_str;
    uint32_t args_size = 0;
    if (request->SerializeToString(&args_str))
    {
        args_size = args_str.size();
    }
    else
    {
        controller->SetFailed("SerializeToString args_str error");
        LOG_ERRO("SerializeToString args_str error");
        return;
    }

    //定义rpc-header
    mprpc::RpcHeader rpcheader;
    rpcheader.set_service_name(service_name);
    rpcheader.set_method_name(method_name);
    rpcheader.set_args_size(args_size);

    uint32_t header_size = 0;
    std::string rpc_hander_str;
    if (rpcheader.SerializePartialToString(&rpc_hander_str))
    {
        header_size = rpc_hander_str.size();
    }
    else
    {
        controller->SetFailed("SerializePartialToString rpc_hander_str error");
        LOG_ERRO("SerializePartialToString rpc_hander_str error");
        return;
    }

    //打包rpc-请求字符串
    std::string send_rpc_str;
    send_rpc_str.insert(0, std::string(reinterpret_cast<char *>(&header_size), 4));
    send_rpc_str += rpc_hander_str;
    send_rpc_str += args_str;

    //打印调试信息
    /* std::cout << "--------------------------------------------------------------" << std::endl;
    std::cout << "header_size:" << header_size << std::endl;
    std::cout << "rpc_header_str:" << rpc_hander_str << std::endl;
    std::cout << "service_name:" << service_name << std::endl;
    std::cout << "method_name:" << method_name << std::endl;
    std::cout << "args_size:" << args_size << std::endl;
    std::cout << "args_str:" << args_str << std::endl;
    std::cout << "--------------------------------------------------------------" << std::endl; */

    //使用Tcp编程，完成远程调用
    int clientfd = socket(AF_INET, SOCK_STREAM, 0);
    if (-1 == clientfd)
    {
        char buf[512] = {0};
        sprintf(buf, "Create socket failed，errno:%d", errno);
        LOG_ERRO("Create socket failed，errno:%d", errno);
        controller->SetFailed(buf);
        return;
    }

    /* std::string ip = MprpcApplication::getInstance().getConfig().load("rpcserviceip");
    uint16_t port = atoi(MprpcApplication::getInstance().getConfig().load("rpcserviceport").c_str()); */
    ZKClient zkclient;
    zkclient.Start();
    std::string method_path = "/" + service_name + "/" + method_name;
    std::string zk_ip_port = zkclient.GetData(method_path.c_str());
    if (zk_ip_port == "")
    {
        controller->SetFailed(method_path + "Znode is not exist!");
        LOG_ERRO("Znode is not exist!");
        return;
    }

    int idx = zk_ip_port.find(':');
    if (idx == -1)
    {
        controller->SetFailed(zk_ip_port + " format error!");
        LOG_ERRO("ZK_IP_PORT format error!");
    }
    std::string ip = zk_ip_port.substr(0, idx);
    uint16_t port = atoi(zk_ip_port.substr(idx + 1, zk_ip_port.size() - idx).c_str());

    sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(ip.c_str());
    server_addr.sin_port = htons(port);

    //连接rpc服务节点
    if (-1 == connect(clientfd, reinterpret_cast<sockaddr *>(&server_addr), sizeof(server_addr)))
    {
        close(clientfd);
        char buf[512] = {0};
        sprintf(buf, "Connection failed，errno:%d", errno);
        LOG_ERRO("Connection failed，errno:%d", errno);
        controller->SetFailed(buf);
        return;
    }

    //发送调用请求
    if (0 == (send(clientfd, send_rpc_str.c_str(), send_rpc_str.size(), 0)))
    {
        close(clientfd);
        char buf[512] = {0};
        sprintf(buf, "Send failed，errno:%d", errno);
        LOG_ERRO("Send failed，errno:%d", errno);
        controller->SetFailed(buf);
        return;
    }

    char recv_buf[1024] = {0};
    int recv_size = 0;
    if (-1 == (recv_size = recv(clientfd, recv_buf, 1024, 0)))
    {
        close(clientfd);
        char buf[512] = {0};
        sprintf(buf, "Recv failed，errno:%d", errno);
        LOG_ERRO("Recv failed，errno:%d", errno);
        controller->SetFailed(buf);
        return;
    }

    //std::string response_str(recv_buf, 0, recv_size);
    if (!response->ParsePartialFromArray(recv_buf, recv_size))
    {
        close(clientfd);
        char buf[512] = {0};
        sprintf(buf, "ParseFromString failed，errno:%s", recv_buf);
        LOG_ERRO("ParseFromString failed，errno:%s", recv_buf);
        controller->SetFailed(buf);
        return;
    }
    close(clientfd);
}