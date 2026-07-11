#include "Turn.h"


bool Turn::exec(std::shared_ptr<Character> player,
	std::shared_ptr<Character>* enemies, int enemyNum) {
	player->setAttack();
	for (int i = 0; i < enemyNum; i++)
	{
		enemies[i]->setAttack();
	}

	//プレイヤーが生き残っている敵を探して攻撃する
	{
		int targetEnemyIndex = 0;
		for (int i = 0; i < enemyNum; i++)
		{
			if (enemies[i]->isDead())
			{
				targetEnemyIndex = i;
				break;
			}
			enemies[i]->setAttack();
		}
		//プレイヤーの攻撃（攻撃力取得）
		int playerPower = player->attack();
		//生き残っている敵のダメージ関数を呼び出す
		enemies[targetEnemyIndex]->damage(playerPower);
	}
}