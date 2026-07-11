
#include <iostream>
#include "Player.h"
#include "Goblin.h"
#include "Slime.h"
#include "Turn.h"

int main()
{
	Turn turn;

	std::shared_ptr<Character> player;
	player.reset(new Player());

	std::shared_ptr<Character> enemies[2];
	enemies[0].reset(new Goblin());
	enemies[1].reset(new Slime());

	//ゲームループ
	while (true)
	{
		bool end = turn.exec(player, enemies, 2);
		if (end)
		{
			//決着
			break;
		}
	}
}

