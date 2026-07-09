
#include <iostream>
#include <memory>

class UniPtr
{
public:
	UniPtr();
	~UniPtr();

	std::weak_ptr<UniPtr> ptr_ = {};
	int value = 0;
};

UniPtr::UniPtr()
{
	std::cout << "Instantiate" << std::endl;
}

UniPtr::~UniPtr()
{
	std::cout << "Delete" << std::endl;
}

int main()
{
	{

		{
			std::cout << "ScopeStartPoint" << std::endl;
			std::shared_ptr<UniPtr> ptr1 = std::make_shared<UniPtr>();
			std::shared_ptr<UniPtr> ptr2 = std::make_shared<UniPtr>();

			ptr1->ptr_ = ptr2;
			ptr2->ptr_ = ptr1;

			std::cout << "ScopeEndPoint" << std::endl;
		}
	}
}

