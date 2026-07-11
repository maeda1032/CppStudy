#pragma once

#include "Random.h"
#include "Number.h"
#include "Result.h"

//ランダム値と入力値を比較し、判定結果を保持するクラス
class Judge
{
public:
	//繰り返した回数を保持する
	void JudgePlus()
	{
		judgeCount++;
	}

	//ランダム値と入力値の情報を受け取って、比較して、結果を教える
	Result Compare(const Number& rand, const Number& input);

private:
	int judgeCount;//比較回数
};

