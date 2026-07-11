#include "Input.h"

#include <iostream>

void Input::Set()
{
	for (int i = 0; i < 4; i++)
	{
		std::cout << i << "”Ô‚Ì”’l‚ð“ü—Í : ";
		std::cin >> value[i];
	}
}


