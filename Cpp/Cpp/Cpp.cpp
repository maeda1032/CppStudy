
#include <iostream>


class MyClass
{
public:

	static int incetance;

	MyClass();
	~MyClass();

	static void IncetanceCount();

	void functionA() const
	{
		std::cout << incetance << std::endl;
	}
private:

};
int MyClass::incetance = 0;

MyClass::MyClass()
{
	incetance += 1;
}

MyClass::~MyClass()
{
	incetance -= 1;
}

void MyClass::IncetanceCount()
{
	std::cout << incetance << std::endl;
}


int main()
{
	MyClass::incetance = 0;

	MyClass::IncetanceCount();
	{
		MyClass myClass;
		myClass.functionA();
	}
	MyClass::IncetanceCount();
}

