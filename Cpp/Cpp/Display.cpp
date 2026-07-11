#include "Display.h"

#include <iostream>

void Display::disp(const Result& res)
{
	std::cout << "Œ‹‰Ê";

	std::cout << "hit" << res.hit_ << std::endl;
	std::cout << "brow" << res.blow_ << std::endl;

	if (res.isClear_)
	{
		std::cout << "ƒQ[ƒ€ƒNƒŠƒA" << res.blow_ << std::endl;
	}
}