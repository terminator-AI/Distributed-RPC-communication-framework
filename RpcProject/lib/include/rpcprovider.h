#pragma once
#include <google/protobuf/service.h>
#include <google/protobuf/descriptor.h>
#include <muduo/net/TcpServer.h>
#include <muduo/net/EventLoop.h>
#include <muduo/net/InetAddress.h>
#include <muduo/net/TcpConnection.h>
#include <muduo/base/Timestamp.h>
#include <muduo/net/Buffer.h>
#include <muduo/base/Logging.h>
#include <memory>
#include <string>
#include <unordered_map>
class RpcProvider
{
public:
    //框架提供给外部使用，发布rpc方法函数接口
    void NotifyService(google::protobuf::Service *service);
    //启动rpc服务节点，开始提供rpc远程网络调用服务
    void Run();

private:
    //组合了tcpserver
    std::unique_ptr<muduo::net::TcpServer> m_tcpServer;
    //组合eventloop
    muduo::net::EventLoop m_eventLoop;

    void onConnection(const muduo::net::TcpConnectionPtr &);

    void onMessage(const muduo::net::TcpConnectionPtr &, muduo::net::Buffer *, muduo::Timestamp);
    //service服务类型信息
    struct ServiecInfo
    {
        google::protobuf::Service *m_service;                                                    //服务对象
        std::unordered_map<std::string, const google::protobuf::MethodDescriptor *> m_methodMap; //保存服务方法
    };
    //注册成功的服务对象及其方法的所有信息
    std::unordered_map<std::string, ServiecInfo> m_serviceMap;

    //Closure的回调操作
    void SendRpcSponse(const muduo::net::TcpConnectionPtr &, google::protobuf::Message *);
};