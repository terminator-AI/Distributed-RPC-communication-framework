#pragma once
#include "mprpcconfig.h"
#include "mprpcchannel.h"
#include "mprpccontroller.h"
#include "logger.h"
#include "zookeeperutil.h"
//mprpc框架的基础类;负责rpc初始化
class MprpcApplication
{
public:
    static void Init(int argc, char **argv);
    static MprpcApplication &getInstance()
    {
        static MprpcApplication app;
        return app;
    }
    static MprpcConfig &getConfig();

private:
    MprpcApplication(){};
    MprpcApplication(const MprpcApplication &) = delete;
    MprpcApplication &operator=(const MprpcApplication &) = delete;

    static MprpcConfig m_config;
};