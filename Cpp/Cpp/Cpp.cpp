#include <iostream>
#include <thread>
#include <mutex>

int counter = 0;
std::mutex g_mutex; // ミューテックスを用意する

void Increment()
{
    for (int i = 0; i < 100000; ++i)
    {
        g_mutex.lock();   // ロックを取得（他スレッドではここから待機させる）
        ++counter;      // クリティカルセクション
        g_mutex.unlock(); // ロックを解放
    }
}

int main()
{
    std::thread tA(Increment);
    std::thread tB(Increment);

    tA.join();
    tB.join();

    // 正しく 200000 になる
    std::cout << "カウンタ: " << counter << std::endl;

    return 0;
}