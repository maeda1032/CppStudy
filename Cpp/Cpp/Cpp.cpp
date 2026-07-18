
#include <iostream>

#include <vector>

int main()
{
	std::vector<int> nums;

	{
		nums.push_back(1);
		nums.push_back(2);
		nums.push_back(3);
		nums.push_back(4);
		nums.push_back(5);

		nums.push_back(6);
		nums.push_back(7);
		nums.push_back(8);
		nums.push_back(9);
		nums.push_back(10);
	}
	
	
	// for ループで削除する場合
	for (std::vector<int>::iterator it = nums.begin(); it != nums.end();)
	{
		
		// erase の戻り値で、削除した次の位置を取得する
		it = nums.erase(it);
	}

	for (int i = 0; i < 5; i++)
	{
		std::cout << nums[i] << std::endl;
	}
}

