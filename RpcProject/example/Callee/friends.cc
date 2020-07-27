#include <iostream>
#include "mprpcapplication.h"
#include "friend.pb.h"
#include <vector>
#include <string>
class FriendPrc : public myfriend::FriendServiceRpc
{
public:
    std::vector<std::string> getFriendlist(std::string &name, std::string &pws)
    {
        std::vector<std::string> vec;
        vec.push_back("zhang san");
        vec.push_back("li si");
        return vec;
    }
    void getFriendlist(::google::protobuf::RpcController *controller,
                       const ::myfriend::FriendRequest *request,
                       ::myfriend::FriendResponse *response,
                       ::google::protobuf::Closure *done)
    {
        std::string name = request->name();
        std::string pwd = request->pws();
        std::vector<std::string> vec = getFriendlist(name, pwd);
        response->mutable_result()->set_errcode(0);
        response->mutable_result()->set_errmsg("");
        for (std::string &name : vec)
        {
            std::string *p = response->add_friends();
            *p = name;
        }
        done->Run();
    }
};

int main(int argc, char **argv)
{
    LOG_INF("first log message!");
    LOG_ERRO("%s%s", __FILE__, __FUNCTION__);
    MprpcApplication::Init(argc, argv);
    RpcProvider provider;
    provider.NotifyService(new FriendPrc());
    provider.Run();
    return 0;
}