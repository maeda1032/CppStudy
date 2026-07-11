#pragma once

struct Parameter {
	int hp_;		//HP
	int attack_;	//攻撃力
};

class Character
{
public:
	Character() = default;
	~Character() = default;

public:
	//攻撃力を設定する
	virtual void setAttack() = 0;

	//HPを設定する
	void setHp();

	//攻撃する
	int attack();

	//ダメージを受ける。（攻撃してきたキャラの攻撃力を受け取ってHPを減産）
	void damage(int power);

	//死んだかどうか
	bool isDead() const;

	//パラメータを返す(情報を教える)
	Parameter getParameter() const;





protected:
	Parameter param_;//パラメータ

};

