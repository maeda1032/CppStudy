
#include <iostream>
#include <functional>
#include<vector>
#include<algorithm>

//2つの値を
bool greater(int l, int r)
{
	return l > r;
}

int main()
{
	//begin最初
	//end 最後まで
	//
	std::vector<float> vec = { 10,8,4,9,2,3,5 };

	//小さい値から大きい値の順に並び変える
	std::sort(vec.begin(), vec.end()),greater;

	for (std::vector<float>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		std::cout << *it << std::endl;
	}
}


