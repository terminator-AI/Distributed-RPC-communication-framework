#pragma once

#include "logqueue.h"
#include <string>

//日志系统
enum LogLevel
{
    INFO, //普通信息
    ERROR //错误信息
};

#define LOG_INF(LOGMSGFORMAT, ...)                            \
    do                                                        \
    {                                                         \
        Logger &logger = Logger::getLoggerInstance();         \
        logger.setLogLevel(INFO);                             \
        char log_buf[1024] = {0};                             \
        snprintf(log_buf, 1024, LOGMSGFORMAT, ##__VA_ARGS__); \
        logger.Log(log_buf);                                  \
    } while (0);

#define LOG_ERRO(LOGMSGFORMAT, ...)                           \
    do                                                        \
    {                                                         \
        Logger &logger = Logger::getLoggerInstance();         \
        logger.setLogLevel(ERROR);                            \
        char log_buf[1024] = {0};                             \
        snprintf(log_buf, 1024, LOGMSGFORMAT, ##__VA_ARGS__); \
        logger.Log(log_buf);                                  \
    } while (0);

class Logger
{
public:
    static Logger &getLoggerInstance();
    //设置日志级别
    void setLogLevel(LogLevel level);
    //写日志
    void Log(const std::string &msg);

private:
    Logger();
    Logger(const Logger &) = delete;
    Logger &operator=(const Logger &) = delete;
    int m_logLevel; //记录日志级别
    LockQueue<std::string> m_lckQue;
};
