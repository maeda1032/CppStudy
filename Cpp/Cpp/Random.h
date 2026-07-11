#pragma once

#include "Number.h"

//ランダム値生成クラス
class Random:public Number
{
public:
	//ランダムな値を生成する
	void Generate();

	//持っている情報を他に教える
	void GetValue(int* v, int size)const;

};

