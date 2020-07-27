#pragma once

#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>

//异步写日志队列
template <typename T>
class LockQueue
{
public:
    //框架写日志
    void Push(const T &msg);
    //读线程使用
    T Pop();

private:
    std::queue<T> m_queue;
    std::mutex m_mutex;
    std::condition_variable m_condvariable;
};

template <typename T>
void LockQueue<T>::Push(const T &msg)
{
    std::lock_guard<std::mutex> lock(m_mutex);
    m_queue.push(msg);
    m_condvariable.notify_all();
}
template <typename T>
T LockQueue<T>::Pop()
{
    std::unique_lock<std::mutex> lock(m_mutex);
    while (m_queue.empty())
    {
        m_condvariable.wait(lock);
    }
    T log = m_queue.front();
    m_queue.pop();
    m_condvariable.notify_all();
    return log;
}