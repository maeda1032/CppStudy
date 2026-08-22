#include <iostream>

/*
template <class T>
auto sum(T first)
{
   return first;
}
*/
// 渡された引数をすべて合計する関数
//一つ目の引数だけ独立、二つ目以降をパラメータパック
template <class T,class... Args>
auto sum(T first,Args... args) {

    if constexpr(sizeof...(args) != 0)
    {
        return first + sum(args...);
    }
    else
    {
        return first;
    }
     return first + sum(args...);
  
}



// エントリー関数
int main() {
    auto a1 = sum(1, 2.2f, 3.7f, 4.1f, 5.9f);
    auto a2 = sum(1, 2.3f, 4.7f, 6.1f, 7.2f);

    std::cout << a1 << std::endl;
    std::cout << a2 << std::endl;

    return 0;
}