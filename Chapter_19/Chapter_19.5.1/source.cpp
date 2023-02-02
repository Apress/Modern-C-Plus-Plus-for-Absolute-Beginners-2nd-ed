#include <iostream>

void myfunction(int byvalue)
{
    std::cout << "An argument passed by value: " << byvalue;
}

int main()
{
    myfunction(123);
}