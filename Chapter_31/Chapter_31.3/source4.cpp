#include <iostream>

namespace MyNameSpace
{
    int x;
}

namespace MySecondNameSpace
{
    int x;
}

int main()
{
    MyNameSpace::x = 123;
    MySecondNameSpace::x = 456;
    std::cout << "The 1st x is: " << MyNameSpace::x << ", the 2nd x is: " << MySecondNameSpace::x;
}
