
#include <iostream>

class MyClass 
{
public:
	void func(int i);
	void func(char* c);

	int value = 10;
};

void MyClass::func(int i)
{
	std::cout << "intが呼ばれました。" << i << std::endl;
}

void MyClass::func(char* c)
{
	if (c == nullptr)
	{
		std::cout << "nullptrです" << std::endl;
		return;
	}
	std::cout << "char*が呼ばれました。"<< c << std::endl;
}

int main()
{
	std::unique_ptr<MyClass> ptr = std::make_unique<MyClass>();
	ptr->func(nullptr);
	//NULLの曖昧さについて
	//nullptrとは異なりNULLには０という数値が割り当てられている
	//つまり今回の場合はfunc(int i)が呼ばれることになる
	//これの問題点はfunc(0)でも同様のことが起こることである
	//func(NULL)とfunc(0)はまったくの別物だが、プログラム的には同じ扱いになってしまう
	//またnullptrと違いif(i == NULL)でも0も同じく処理されてしまう等の問題がある

	return 0;
}

