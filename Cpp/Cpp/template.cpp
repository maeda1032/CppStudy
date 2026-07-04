#include <iostream>
#include "template.h"

// T 型の数値を表示する関数テンプレートの定義
template<class T>
void disp(T value)
{
    std::cout << value << std::endl;
}

template void disp<int>(int value);