
#include <iostream>
#include <string>
#include <thread>


// 引数付きの関数
void Count(int start, int end, std::string_view name)
{
    for (int i = start; i <= end; ++i)
    {
        std::cout << name << ": " << i << " ";
    }
    std::cout << std::endl;
}

int main()
{
    // スレッドA: 1 〜 5 をカウント
    std::thread tA(Count, 1, 5, "tA");

    // スレッドB: 6 〜 10 をカウント
    std::thread tB(Count, 6, 10, "tB");

    // 両スレッドの終了を待つ
    tA.join();
    tB.join();

    return 0;
}