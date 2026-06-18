
#include <iostream>

static int incetance = 0;

class MyClass
{
public:
	MyClass();
	~MyClass();
	static void IncetanceCount(int incetance);
private:

};

MyClass::MyClass()
{
	incetance += 1;
}

MyClass::~MyClass()
{
	incetance -= 1;
}

void MyClass::IncetanceCount(int incetance)
{
	std::cout << incetance << std::endl;
}

int main()
{
   
}

