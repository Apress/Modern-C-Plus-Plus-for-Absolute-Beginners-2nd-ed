#include <iostream>
#include <string>

int main()
{
    std::string s = "Hello World!";
    if (s.contains("World"))
    {
        std::cout << "The string contains the given substring." << '\n';
    }
    else
    {
        std::cout << "The string does not contain the given substring." << '\n';
    }
}
