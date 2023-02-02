#include <iostream>

int intfn();

int main()
{
    std::cout << "The function returned a value of: " << intfn();
}

int intfn()
{
    return 42; // return statement
}
