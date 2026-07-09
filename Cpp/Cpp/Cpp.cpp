
#include <iostream>

class UniPtr
{
public:
	UniPtr();
	~UniPtr();
};

UniPtr::UniPtr()
{
	std::cout << "生成" << std::endl;
}

UniPtr::~UniPtr()
{
	std::cout << "破棄" << std::endl;
}

int main()
{
	{
		std::unique_ptr<UniPtr> ptr = std::make_unique<UniPtr>();
	}
}

