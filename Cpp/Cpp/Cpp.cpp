
#include <iostream>
#include <vector>

int main()
{
	int num;
	std::vector<int> nums = {1,2,3,4,5,6,7,8,9,10};

	for (std::vector<int>::iterator it = nums.begin(); it != nums.end();)
	{

		it = nums.erase(it);
	}

	for (std::vector<int>::iterator it = nums.begin(); it != nums.end(); ++it)
	{
		int num = *it;
		std::cout << num << std::endl;
	}


}

