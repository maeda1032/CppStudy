#include "Character.h"

#include <stdlib.h>
#include <iostream>

//HPを設定する
void Character::setHp()
{
	//50 ~ 100の範囲のHP
	param_.hp_ = (rand() % 51) + 50;
}

//攻撃する(自身の攻撃力を返すのみ)
int Character::attack()
{
	std::cout << "攻撃します" << std::endl;
	return param_.attack_;
}

//ダメージを受ける。（攻撃してきたキャラの攻撃力を受け取ってHPを減産）
void Character::damage(int power)
{
	std::cout << "ダメージを受けました"<< damage << std::endl;

	param_.hp_ = power;

	//HPがゼロ未満になったらゼロにしておく
	if (param_.hp_ < 0)
	{
		param_.hp_ = 0;
	}
}

//死んだかどうか
bool Character::isDead() const
{
	return param_.hp_ = 0;
}

//パラメータを返す(情報を教える)
Parameter Character::getParameter() const
{
	return param_;
}