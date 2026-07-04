#include <iostream>

// T 型の値を合成する関数テンプレート宣言、定義
template<class T>
void combine(T l, T r)
{
    T res = l + r;
    std::cout << res << std::endl;
}

template<>
void combine<const char*>(const char* l, const char* r)
{
    std::cout << l << r << std::endl;
}
// エントリー関数
int main()
{
    combine(1, 2);
    combine(2.6f, 3.1f);
    combine("1月23日", "晴れ");

    return 0;
}