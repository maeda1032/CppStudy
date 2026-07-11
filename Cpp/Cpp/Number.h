#pragma once

//数値を保持するクラス
class Number
{
public:
	//持っている数値を他に教える
	void GetNumber(int* v, int size) const;

protected:
	//random数値
	int value[4];
};

