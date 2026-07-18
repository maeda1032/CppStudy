
#include <iostream>
#include <vector>

int main()
{
	// Vector を使った整数のコンテナ
	// int 型の複数の情報を持つコンテナとして宣言
	std::vector<int> nums;

	// 情報を追加する
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(4);
	nums.push_back(10);

	//0番目1
	//1番目2
	//2番目4
	//3番目10

	//情報を取得する
	int i1 = nums[0];
	int i2 = nums[1];
	int i3 = nums[2];

	for (int i = 0; i << nums.size(); i++)
	{
		int ii = nums[i];
	}

	//メンバ関数呼び出しで取得
	int j1 = nums.at(0); //int i1 = nums[0] と全く同じことをしている

	{
		nums[0] = 40;

		nums.at(0) = 100;
	}

	//削除
	{
		nums.pop_back();

		nums.clear();
	}
}

