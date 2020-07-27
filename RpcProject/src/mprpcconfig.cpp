#include "mprpcconfig.h"
#include "logger.h"
#include <iostream>
//负责解析加载配置文件
void MprpcConfig::loadConfigFile(const char *config_file)
{
    FILE *pf = fopen(config_file, "r");
    if (nullptr == pf)
    {
        std::cout << "ConfigFile is not exist!" << std::endl;
        LOG_ERRO("ConfigFile is not exist!");
        exit(EXIT_FAILURE);
    }
    while (!feof(pf))
    {
        char buf[512] = {0};
        fgets(buf, 512, pf);
        std::string src_buf(buf);
        Trim(src_buf); //去掉字符串前面多余的空格
        if ('#' == src_buf[0] || src_buf.empty())
        {
            continue;
        }
        //解析配置项
        int idx = src_buf.find('=');
        if (-1 == idx)
        {
            continue;
        }
        std::string key = src_buf.substr(0, idx);
        Trim(key);
        int endidx = src_buf.find('\n');
        std::string value = src_buf.substr(idx + 1, endidx - idx - 1);
        Trim(value);
        m_configMap.insert({key, value});
    }
}
//查询配置项信息
std::string MprpcConfig::load(const std::string &key)
{
    auto it = m_configMap.find(key);
    if (it != m_configMap.end())
    {
        return it->second;
    }
    return "";
}

//去掉字符串空格
void MprpcConfig::Trim(std::string &src_buf)
{
    int idx = src_buf.find_first_not_of(' ');
    if (-1 != idx)
    { //说明字符串前面有空格
        src_buf = src_buf.substr(idx, src_buf.size() - idx);
    }
    //去除字符串后面空格
    idx = src_buf.find_last_not_of(' ');
    if (-1 != idx)
    {
        //说明字符串后面有空格
        src_buf = src_buf.substr(0, idx + 1);
    }
}