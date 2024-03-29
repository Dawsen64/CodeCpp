#ifndef _SEMAPHORE_H
#define _SEMAPHORE_H
#include <mutex>
#include <condition_variable>
using namespace std;

class Semaphore
{
public:
    Semaphore(long count = 0) : count(count) {}
    //V����������
    void signal()
    {
        unique_lock<mutex> unique(mt);
        ++count;
        if (count <= 0)
            cond.notify_one();
    }
    //P����������
    void wait()
    {
        unique_lock<mutex> unique(mt);
        --count;
        if (count < 0)
            cond.wait(unique);
    }

private:
    mutex mt;
    //�ź���
    condition_variable cond;
    long count;
};
#endif

