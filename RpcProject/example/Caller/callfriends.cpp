#include "mprpcapplication.h"
#include "friend.pb.h"
#include <iostream>

int main(int argc, char **argv)
{
    MprpcApplication::Init(argc, argv);

    myfriend::FriendServiceRpc_Stub stub(new MprpcChannel());

    myfriend::FriendRequest req;
    req.set_name("w");
    req.set_pws("666");
    myfriend::FriendResponse response;
    MprpcController rpcContruller;
    stub.getFriendlist(&rpcContruller, &req, &response, nullptr);
    if (!rpcContruller.Failed())
    {
        if (response.result().errcode() == 0)
        {
            int size = response.friends_size();
            for (int i = 0; i < size; ++i)
            {
                std::cout << "name:" << response.friends(i) << std::endl;
            }
        }
        else
        {
            std::cout << "errno:" << errno << std::endl;
        }
    }

    return 0;
}