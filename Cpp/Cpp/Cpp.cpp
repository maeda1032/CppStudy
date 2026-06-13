
#include <iostream>

class MyClass 
{
public:


	std::weak_ptr<MyClass> ptr_ = {};
};


void func(int)
{
	std::cout << "intが呼ばれました。" << std::endl;
}

void func(char*)
{
	std::cout << "charが呼ばれました。" << std::endl;
}


int main()
{
	{
		//NULLを渡した場合、無効なアドレスを持つポインタではなくint型の0と表示されるため
		func(nullptr);
	}
}

