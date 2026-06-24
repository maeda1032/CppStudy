#include "Cpp.h"
#include "stdio.h"
#include <iostream>

int Add(int i, int r)
{
	int a = 0;
	std::cout << "呼ばれたのはintです数値は" << i << ","<<r << std::endl;

	a = i + r;
	return a;
}

float Add(float f, float f1)
{
	float addf = 0;
	std::cout << "呼ばれたのはfloatです数値は" << f << "," << f1 <<std::endl;
	
	addf = f + f1;
	return addf;
}

double Add(double d, double d1)
{
	double addD = 0;
	std::cout << "呼ばれたのはdoubleです数値は" << d << "," << d1 << std::endl;
	addD = d + d1;
	return addD;
}

int Add(int i1, int i2, int i3)
{
	int addI = 0;

	std::cout << "呼ばれたのは複数のintです数値は" << i1 << "," << i2 << "," << i3 << std::endl;

	addI = i1 + i2 + i3;

	return addI;
}

void disp(int i)
{
	std::cout << "intの計算結果は" << i << std::endl;
}

void disp(float f)
{
	std::cout << "floatの計算結果は" << f << std::endl;
}

void disp(double d)
{
	std::cout << "doubleの計算結果は" << d << std::endl;

}