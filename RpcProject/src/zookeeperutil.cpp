#include "zookeeperutil.h"
#include "mprpcapplication.h"

//zkserver通知zkclient
void global_watcher(zhandle_t *zh, int type, int state, const char *path, void *watcherCtx)
{
    if (type == ZOO_SESSION_EVENT) //回调的消息类型和会话相关的消息类型
    {
        if (state == ZOO_CONNECTED_STATE) //zkclient和zkserver连接成功
        {
            sem_t *sem = (sem_t *)zoo_get_context(zh);
            sem_post(sem);
        }
    }
}

ZKClient::ZKClient() : m_zhandle(nullptr)
{
}
ZKClient::~ZKClient()
{
    if (m_zhandle != nullptr)
    {
        zookeeper_close(m_zhandle);
    }
}
//启动连接zkserver
void ZKClient::Start()
{
    std::string host = MprpcApplication::getInstance().getConfig().load("zookeeperip");
    std::string port = MprpcApplication::getInstance().getConfig().load("zookeeperport");
    std::string connstr = host + ":" + port;
    /*
    zookeeper_mt:多线程版本
    API客户端提供了三个线程
    API调用线程
    网络I/O线程 ---->pthread_create---->poll
    watcher回调线程  pthread_create
     */
    m_zhandle = zookeeper_init(connstr.c_str(), global_watcher, 30000, nullptr, nullptr, 0);
    if (nullptr == m_zhandle)
    { //句柄内存是否开辟成功，不代表连接成功
        std::cout << "zookeeper_init error!" << std::endl;
        exit(EXIT_FAILURE);
    }
    sem_t sem;
    sem_init(&sem, 0, 0);
    zoo_set_context(m_zhandle, &sem);
    //等待连接成功
    sem_wait(&sem);
    std::cout << "zookeeper_init success!" << std::endl;
}
//根据指定的路径添加节点
void ZKClient::Create(const char *path, const char *data, int datalen, int state)
{
    char path_buffer[128];
    int bufferlen = sizeof(path_buffer);
    int flag;
    //判断节点是否存在
    flag = zoo_exists(m_zhandle, path, 0, nullptr);
    if (ZNONODE == flag) //节点不存在
    {
        //创建指定path的节点
        flag = zoo_create(m_zhandle, path, data, datalen, &ZOO_OPEN_ACL_UNSAFE, state, path_buffer, bufferlen);
        if (flag == ZOK)
        {
            std::cout << "znode create success... path:" << path << std::endl;
        }
        else
        {
            std::cout << "Flag:" << flag << std::endl;
            std::cout << "znode create err... paht:" << path << std::endl;
            exit(EXIT_FAILURE);
        }
    }
}
//获取节点上的值
std::string ZKClient::GetData(const char *path)
{
    char buffer[64];
    int bufferlen = sizeof(buffer);
    int flag = zoo_get(m_zhandle, path, 0, buffer, &bufferlen, nullptr);
    if (flag != ZOK)
    {
        std::cout << "Get znode data error... path:" << path << std::endl;
        return "";
    }
    else
    {
        return buffer;
    }
}
