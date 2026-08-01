
#include <iostream>
#include "Template.h"

int main()
{
    int add = Add(2,5);

    float minus = Subtraction(5.3f, 2.4f);

    int multi = MultiPlication(4, 2);

    float divide = Divide(6, 2);

    std::cout << add << std::endl;
    std::cout << minus << std::endl;
    std::cout << multi << std::endl;
    std::cout << divide << std::endl;

}

