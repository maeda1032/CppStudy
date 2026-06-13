
#include <iostream>
#include<stdio.h>

void Swap(int* pointInt, int& sansyouValue)
{
	int	a = 100;
	int	b = 500;
	pointInt = &a;
	printf("ポインターが呼ばれました。数値は%dです\n",pointInt);

	sansyouValue = b;
	printf("参照が呼ばれました。数値は%dです\n", sansyouValue);
}


int main()
{
	int* pointValue = 0;
	int sansyouValue = 0;
	printf("入れ替え前の数値は&d,&dです。", pointValue, sansyouValue);
	Swap(pointValue, sansyouValue);
}

