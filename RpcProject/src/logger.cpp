#include "logger.h"
#include <time.h>
#include <iostream>
Logger &Logger::getLoggerInstance()
{
    static Logger logger;
    return logger;
}
Logger::Logger()
{
    //启动专门的写日志线程
    std::thread writeLogTask([&]() {
        for (;;)
        {
            //获取当天的日志，取日志信息写入相应的文件当中-->a+
            time_t now = time(nullptr);
            tm *nowtm = localtime(&now);

            char file_name[128];
            sprintf(file_name, "%d-%d-%d-log.txt", nowtm->tm_year + 1900, nowtm->tm_mon + 1, nowtm->tm_mday);

            FILE *fp = fopen(file_name, "a+");
            if (fp == nullptr)
            {
                std::cout << "file open failed..." << std::endl;
                exit(EXIT_FAILURE);
            }
            std::string msg = m_lckQue.Pop();

            char time_buf[128] = {0};
            sprintf(time_buf, "%d:%d:%d-[%s]", nowtm->tm_hour, nowtm->tm_min, nowtm->tm_sec, (m_logLevel == INFO ? "INFO" : "ERROR"));
            msg.insert(0, time_buf);
            msg.append("\n");
            fputs(msg.c_str(), fp);
            fclose(fp);
        }
    });
    writeLogTask.detach();
}
//设置日志级别
void Logger::setLogLevel(LogLevel level)
{
    m_logLevel = level;
}
//写日志,把日志信息写入LockQueue缓冲区中
void Logger::Log(const std::string &msg)
{
    m_lckQue.Push(msg);
}
