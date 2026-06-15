
#include <iostream>

void PtrSwap(int* ptrSwap1,int* ptrSwap2)
{
	int a = *ptrSwap1;
	*ptrSwap1 = *ptrSwap2;
	*ptrSwap2 = a;
}

void RefSwap(int& swapRef1,int& swapRef2)
{
	int a = swapRef1;
	swapRef1 = swapRef2;
	swapRef2 = a;
}

int main()
{
	int ptr1 = 10;
	int ptr2 = 50;

	std::cout << "現在のptr数値" << ptr1 << "," << ptr2 << std::endl;

	int* ptrSwapInt1 = &ptr1;
	int* ptrSwapInt2 = &ptr2;
	
	PtrSwap(ptrSwapInt1,ptrSwapInt2);

	std::cout << "変更後のptr数値" << ptr1 << "," << ptr2 << std::endl;


	int ref1 = 20;
	int ref2 = 80;

	std::cout << "現在のref数値" << ref1 << "," << ref2 << std::endl;


	int& refSwapInt1 = ref1;
	int& refSwapInt2 = ref2;

	RefSwap(refSwapInt1,refSwapInt2);


	std::cout << "変更後のref数値" << ref1 << "," << ref2 << std::endl;

}

