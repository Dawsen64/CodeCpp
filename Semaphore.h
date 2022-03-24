#ifndef _SEMAPHORE_H
#define _SEMAPHORE_H
#include <mutex>
#include <condition_variable>
using namespace std;

class Semaphore
{
public:
    Semaphore(long count = 0) : count(count) {}
    //V²Ù×÷£¬»½ÐÑ
    void signal()
    {
        unique_lock<mutex> unique(mt);
        ++count;
        if (count <= 0)
            cond.notify_one();
    }
    //P²Ù×÷£¬×èÈû
    void wait()
    {
        unique_lock<mutex> unique(mt);
        --count;
        if (count < 0)
            cond.wait(unique);
    }

private:
    mutex mt;
    //ÐÅºÅÁ¿
    condition_variable cond;
    long count;
};
#endif

