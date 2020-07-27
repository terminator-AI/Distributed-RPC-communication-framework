#pragma once
#include <semaphore.h>
#include <zookeeper/zookeeper.h>
#include <string>

class ZKClient
{
public:
    ZKClient();
    ~ZKClient();
    //启动连接zkserver
    void Start();
    //根据指定的路径添加节点
    void Create(const char *path, const char *data, int datalen, int state = 0);
    std::string GetData(const char *path);

private:
    //zk的客户端句柄
    zhandle_t *m_zhandle;
};