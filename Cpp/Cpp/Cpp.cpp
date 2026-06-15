
#include <iostream>

class Constract
{
public:
	int apple = 10;
	Constract();
	Constract(int apple);
	Constract(const Constract& src);
	~Constract();
	void Apple(Constract con)
	{
		con.apple -= 20;
		std::cout << con.apple << std::endl;
	}
};
Constract::Constract()
{
	std::cout << "コンストラクタが呼ばれました。" << std::endl;
}
Constract::Constract(int apple)
{
	apple = 50;
	std::cout << "引数付きコンストラクタが呼ばれました。ただ今のリンゴの数は"<< apple << "です" << std::endl;

}

Constract::Constract(const Constract& src)
{
	std::cout << "コピーコンストラクタが呼ばれました。" << std::endl;
	apple = src.apple;
}

Constract::~Constract()
{
	std::cout << "デストラクタが呼ばれました。" << std::endl;

}






int main()
{
	Constract con;
	Constract con1(2);
	Constract Apple(con);
}

