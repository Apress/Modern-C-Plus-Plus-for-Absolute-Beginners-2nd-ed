#include <iostream>

int main()
{
    std::cout << "Please enter two integer numbers: ";
    int x;
    int y;
    std::cin >> x >> y;
    int result = x + y;
    std::cout << "The result is: " << result;
}
