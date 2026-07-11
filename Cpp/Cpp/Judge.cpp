#include "Judge.h"

Result Judge::Compare(const Number& rand, const Number& input)
{
	//ランダム値と入力値の情報を受け取るための箱を宣言
	int rn[4];
	int in[4];


	bool isHit[4] = {};
	int hitNum = 0;
	for (int i = 0; i < 4; i++)
	{
		if (rn[i] == in[i])
		{
			hitNum++;
		}
	}

	//ブロー数を調べる
	int blowNum = 0;
	for (int i = 0; i < 4; i++)
	{
		if (isHit[i])
		{
			continue;
		}

		int inputNum = in[i];

		//rn用のループ
			for (int j = 0; j < 4; j++)
			{
				if (isHit[i])
				{
					continue;
				}
				if (rn[j] == inputNum)
				{
					blowNum++;
				}
			}
	}

	Result res;
	res.hit_ = hitNum;
	res.blow_ = blowNum;
	res.isClear_ = (hitNum == 4);

	return res;

}