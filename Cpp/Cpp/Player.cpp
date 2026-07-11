#include "Player.h"
#include <stdlib.h>

void Player::setAttack()
{
	param_.attack_ = rand() % 11;
}