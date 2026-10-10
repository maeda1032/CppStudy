#include <iostream>
#include <thread>
#include <mutex>

std::mutex g_mutexA;
std::mutex g_mutexB;

void ThreadA()
{
    g_mutexA.lock();                                     // 1. A をロック
    std::cout << "スレッドA: mutexA をロック" << std::endl;

    g_mutexB.lock();                                     // 3. B を待機し続ける
    std::cout << "スレッドA: mutexB をロック" << std::endl;

    g_mutexB.unlock();
    g_mutexA.unlock();
}

void ThreadB()
{
    g_mutexB.lock();                                     // 2. B をロック
    std::cout << "スレッドB: mutexB をロック" << std::endl;

    g_mutexA.lock();                                     // 4. A を待機し続ける
    std::cout << "スレッドB: mutexA をロック" << std::endl;

    g_mutexA.unlock();
    g_mutexB.unlock();
}

int main()
{
    std::thread tA(ThreadA);
    std::thread tB(ThreadB);

    tA.join(); // 永遠に終わらない
    tB.join();

    return 0;
}