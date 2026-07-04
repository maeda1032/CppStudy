#pragma once

template<class T>
class MyClass {
public:
	void Add(T value, T value1);
	void Minus(T value, T value1);
	void Multiplication(T value, T value1);
	void Division(T value, T value1);
};

template<class T>
void MyClass<T>::Add(T value, T value1)
{
	int result = 0;
	result = value + value1;

	std::cout << result << std::endl;
}

template<class T>
void MyClass<T>::Minus(T value, T value1)
{
	int result = 0;
	result = value - value1;

	std::cout << result << std::endl;
}

template<class T>
void MyClass<T>::Multiplication(T value, T value1)
{
	int result = 0;
	result = value * value1;

	std::cout << result << std::endl;
}

template<class T>
void MyClass<T>::Division(T value, T value1)
{
	int result = 0;
	result = value / value1;

	std::cout << result << std::endl;
}