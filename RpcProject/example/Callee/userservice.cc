#include <iostream>
#include <string>
#include "user.pb.h"
#include "mprpcapplication.h"
#include "rpcprovider.h"
using namespace fixbug;

class UserService : public UserServiceRpc
{
public:
    bool Login(std::string name, std::string pwd)
    {
        std::cout << "\nDoing local service:Login" << std::endl;
        std::cout << "\nName:" << name << " pwd:" << pwd << std::endl;
        return true;
    }
    void Login(::google::protobuf::RpcController *controller,
               const ::fixbug::LoginRequest *request,
               ::fixbug::LoginResponse *response,
               ::google::protobuf::Closure *done)
    {
        //获取请求消息
        std::string name = request->name();
        std::string pwd = request->pwd();
        //调用本地服务
        bool Login_result = Login(name, pwd);
        //设置返回消息
        fixbug::ResultCode *code = response->mutable_result();
        code->set_errcode(0);
        code->set_errmsg("");
        response->set_sucess(Login_result);
        //执行回调
        done->Run();
    }
};

int main(int argc, char **argv)
{
    MprpcApplication::Init(argc, argv);

    RpcProvider rpcProvider;
    rpcProvider.NotifyService(new UserService());
    rpcProvider.Run();
    return 0;
}