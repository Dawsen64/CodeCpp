#include "semaphore.h"
#include <thread>
#include <mutex>
#include <iostream>
using namespace std;

Semaphore sem(0);
Semaphore sem1(1);

void funA()
{
    while (true) {
        sem.wait();
        cout << "funA" << endl;
        sem1.signal();
    }
}

void funB()
{
    sem1.wait();
    cout << "funB" << endl;
    sem.signal();
}

int main()
{
    thread th(funA);
    funB();
    funB();
    funB();
    funB();
    funB();
    th.join();
}