
#include <iostream>

int main()
{
	int array[6];
	array[0] = 5;
	array[1] = 15;
	array[2] = 52;
	array[3] = 53;
	array[4] = 354;
	array[5] = 65;

	int* p = array;

	for (int i = 0; i < 6; i++)
	{
		std::cout << array[i] << std::endl;
	}



	for (int i = 0; i < 6; i++)
	{
		std::cout << *p << std::endl;

		p++;
	}
}

