
#include <iostream>
#include <memory>

class UniPtr
{
public:
	UniPtr();
	~UniPtr();

	std::shared_ptr<UniPtr> ptr_ = {};
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

		{
			std::cout << "スコープ開始地点" << std::endl;
			std::shared_ptr<UniPtr> ptr1 = std::make_shared<UniPtr>();
			std::shared_ptr<UniPtr> ptr2 = std::make_shared<UniPtr>();

			ptr1->ptr_ = ptr2;
			ptr2->ptr_ = ptr1;

			std::cout << "スコープ終了地点" << std::endl;
		}
	}
}

