
#include <iostream>

class Character
{
private:
	char name[10];
	int hp;
	int attack;

public:

	void StatusUpdate(char* name1, int hp1, int attack1)
	{
		strcpy_s(name, 10, name1);
		hp = hp1;
		attack = attack1;
	}
	void PrintStatus(Character chara)
	{
		std::cout << chara.name << std::endl;
		std::cout << chara.hp << std::endl;
		std::cout << chara.attack << std::endl;
	}
};




int main()
{
	Character chara1;
	chara1.StatusUpdate("tarou", 53, 25);
	chara1.PrintStatus(chara1);

	Character chara2;
	chara1.StatusUpdate("jirou", 532, 255);
	chara1.PrintStatus(chara2);
}

