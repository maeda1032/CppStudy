
#include <iostream>

class Vector2
{
public:
	float x = 0;
	float y = 0;
	Vector2 operator +(const Vector2& vector2);
	Vector2 operator -(const Vector2& vector2);
	bool operator ==(const Vector2& vector2);

	Vector2(float initX, float initY);

};

Vector2::Vector2(float initX, float initY)
{
	x = initX;
	y = initY;	
}


Vector2 Vector2::operator +(const Vector2& vector2)
{
	Vector2 result(0.0f, 0.0f);

	result.x = x + vector2.x;
   	result.y = y + vector2.y;

	return result;
}

Vector2 Vector2::operator -(const Vector2& vector2)
{
	Vector2 result(0.0f, 0.0f);

	result.x = x - vector2.x;
	result.y = y - vector2.y;

	return result;
}

bool Vector2::operator ==(const Vector2& vector2)
{
	bool isCheck = false;
	if (x == vector2.x && y == vector2.y)
	{
		isCheck = true;
	}

	return isCheck;
}

std::ostream& operator <<(std::ostream& os, const Vector2& vector2)
{
	os << vector2.x << "," << vector2.y; // 改行(endl)はmain側で制御できるようにここでは書かないのが一般的です
	return os;
}

int main()
{
	Vector2 vector2a(0.0f,0.0f);
	Vector2 vector2b(5.0f,3.0f);
	Vector2 vector2c(15.0f,13.0f);
	
    Vector2 total = vector2a + vector2b;

	std::cout << total << std::endl;

    total = total - vector2c;

	std::cout << total << std::endl;

    bool check = vector2a == vector2b;

	std::cout << std::boolalpha << "同じかどうか: " << check << std::endl;

}

