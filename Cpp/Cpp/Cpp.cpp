
#include <iostream>

class Charactor
{
public:
	struct MyStruct
	{
		int hp = 0;
		int attack = 0;
		float difence = 0;
	};

	MyStruct Status;

	void StatusCheck(int attack, int hp, float difence);

	Charactor();
	~Charactor();
};
inline void Charactor::StatusCheck(int attack,int hp,float difence)
{
	std::cout << "ステータスは以下の通りです" << std::endl;
	std::cout << "attack" << attack << std::endl;
	std::cout << "hp" << hp << std::endl;
	std::cout << "difence" << difence << std::endl;
}


Charactor::Charactor()
{
	std::cout << "コンストラクタが呼ばれました" << std::endl;
}

Charactor::~Charactor()
{
	std::cout << "デストラクタが呼ばれました" << std::endl;
}



int main()
{
	//ローカル変数
	{
		Charactor localChara;

		localChara.Status.attack = 10;
		localChara.Status.difence = 21.4f;
		localChara.Status.hp = 15;

		localChara.StatusCheck(localChara.Status.attack,localChara.Status.hp,localChara.Status.difence);

	}
	//new deleteで呼び出す
	{
		Charactor* newChara = new Charactor;

		newChara->Status.attack = 30;
		newChara->Status.hp = 40;
		newChara->Status.difence = 10.5f;

		newChara->StatusCheck(newChara->Status.attack, newChara->Status.hp, newChara->Status.difence);

		delete newChara;
	}


}

