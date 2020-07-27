#include <iostream>
#include "mprpcapplication.h"
#include "user.pb.h"

int main(int argc, char **argv)
{
    //整个程序启动后，使用mprpec框架，调用框架初始化函数（once）
    MprpcApplication::Init(argc, argv);
    //演示调用远程发布的rpc方法Login
    fixbug::UserServiceRpc_Stub stub(new MprpcChannel());
    //请求参数
    fixbug::LoginRequest request;
    request.set_name("david");
    request.set_pwd("123456");
    //rpc响应
    fixbug::LoginResponse response;
    stub.Login(nullptr, &request, &response, nullptr); //RpcChannel->RpcChannel::callMethod;
    if (0 == response.result().errcode())
    {
        std::cout << "rpc login response success-->" << response.sucess() << std::endl;
    }
    else
    {
        std::cout << "rpc login failed-->" << response.result().errmsg() << std::endl;
    }

    return 0;
}