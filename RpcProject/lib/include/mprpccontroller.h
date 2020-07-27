#pragma once
#include <google/protobuf/service.h>
#include <string>
class MprpcController : public google::protobuf::RpcController
{
public:
    MprpcController();
    //重置
    void Reset();
    //填写错误信息
    std::string ErrorText() const;
    bool Failed() const;
    void SetFailed(const std::string &reason);
    //以下未实现
    void StartCancel();
    bool IsCanceled() const;
    void NotifyOnCancel(google::protobuf::Closure *callback);

private:
    bool m_failed;         //判断是否失败
    std::string m_errText; //存储失败信息
};