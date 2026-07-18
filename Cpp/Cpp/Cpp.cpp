
#include <iostream>
#include <map>

int main()
{
	//ペアで覚えたいとき
	std::map<char, float >map;

	{
		map.emplace('a', 3.1f);
	}

	{
		float f2 = map['a'];
	}

	//実装方法
	{
		//メンバ関数を使って更新
		map.at('a') = 0.3f;

		//[]で更新
		map['a'] = 100.5f;
	}

	//削除方法
	{
		//全部削除
		map.clear();

		//
	}
}

