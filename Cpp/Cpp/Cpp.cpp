
#include "Cpp.h"

int main()
{
	int i = 10;
	int r = 15;
	float f = 15.2f;
	float f1 = 24.2f;
	double d = 20;
	double d1 = 50;
	int i1 = 30;
	int i2 = 31;
	int i3 = 32;
	int addI = Add(i,r);
	float addF = Add(f,f1);
	double addD = Add(d,d1);
	int addI1 = Add(i1, i2, i3);

	disp(addI);
	disp(addI1);
	disp(addF);
	disp(addD);
}

