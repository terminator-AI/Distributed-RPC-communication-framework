#include "mprpcapplication.h"
#include <iostream>
#include <unistd.h>

MprpcConfig MprpcApplication::m_config;

static void
ShowArgHelp()
{
    std::cout << "Format:command -i <configfile>" << std::endl;
}

void MprpcApplication::Init(int argc, char **argv)
{
    if (argc < 2)
    {
        ShowArgHelp();
        exit(EXIT_FAILURE);
    }
    int c = 0;
    std::string config_file;
    while ((c = getopt(argc, argv, "i:")) != -1)
    {
        switch (c)
        {
        case 'i':
            config_file = optarg;
            break;
        case '?':
            exit(EXIT_FAILURE);
        case ':':
            ShowArgHelp();
            exit(EXIT_FAILURE);
        default:
            break;
        }
    }

     //开始加载配置文件
    m_config.loadConfigFile(config_file.c_str());
    /* std::cout << m_config.load("rpcserviceip") << std::endl;
    std::cout << m_config.load("rpcserviceport") << std::endl; */
}

MprpcConfig &MprpcApplication::getConfig()
{
    return m_config;
}