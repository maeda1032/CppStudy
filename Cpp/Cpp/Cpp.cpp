
#include <iostream>

class HasDrawA {
public:
	void draw() { std::cout << "HasDrawA::draw()が呼び出されました" << std::endl; }
};

class HasDrawB {
public:
	void draw() { std::cout << "HasDrawB::draw()が呼びだれました" << std::endl; }
};

class NoneDraw{};

template<class T>
concept HasDrawObject = requires(T & t) {
	t.draw();
};

template <class T>
void callDraw(T& x) {
	if constexpr (HasDrawObject<T>)
	{
		x.draw();
	}
	else
	{
		std::cout << "draw()が呼び出せません" << std::endl;
	}
}

int main()
{
	HasDrawA a;
	HasDrawB b;
	NoneDraw n;
	
	callDraw(a);
	callDraw(b);
	callDraw(n);

	return 0;
	
}