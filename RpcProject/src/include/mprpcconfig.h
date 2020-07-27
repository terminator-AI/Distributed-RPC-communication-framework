#pragma once

#include <unordered_map>
#include <string>

class MprpcConfig
{
public:
    //负责解析加载配置文件
    void loadConfigFile(const char *config_file);
    //查询配置项信息
    std::string load(const std::string &key);
    //去掉字符串空格
    void Trim(std::string &str_buf);

private:
    std::unordered_map<std::string, std::string> m_configMap;
};