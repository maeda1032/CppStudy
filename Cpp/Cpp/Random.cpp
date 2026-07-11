#include "Random.h"
#include <stdlib.h>
#include <time.h>
void Random::Generate()
{
	srand((unsigned int)time(NULL));

		//4桁のランダムな数を生成して、情報に設定する
		for (int i = 0; i < 4; i++)
		{
			value_[i] = rand() % 10;

			//value[i]がすでに過去出ているかどうかをチェック
				for (int j = 0; j < i; j++)
				{
					//これまですでに使われている場合、value[i]はやりなおさないといけない
					if (value_[j] == value_[i]) {
						i--;
						break;

						break;
					}
				}

		}
}

