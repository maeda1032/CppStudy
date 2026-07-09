
#include <iostream>

class Character
{
public:
	int attack = 0;
	int hp = 0;
	int animal = 0;

};

Character* CharacterStatus()
{
	Character* chara = new Character;

	chara->animal = 10;
	chara->hp = 20;
	chara->attack = 30;

	return chara;
}

void disp(Character* chara)
{
	std::cout << "animalの数" << chara->animal << std::endl;
	std::cout << "hpの数値" << chara->hp << std::endl;
	std::cout << "attackの数値" << chara->attack << std::endl;
}

void DestroyInstance(Character*& chara)
{
	if (chara == nullptr) return;
	delete chara;
	chara = nullptr;
	std::cout << "Characterが破棄されました。" << std::endl;
}

int main()
{
	Character* newChara = CharacterStatus();

	disp(newChara);

	DestroyInstance(newChara);
}

