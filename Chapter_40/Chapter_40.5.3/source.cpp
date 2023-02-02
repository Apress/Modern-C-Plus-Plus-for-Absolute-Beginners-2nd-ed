#include <iostream>

#warning "User-defined warning message."
#warning "Some diagnostics message."

int main()
{
    std::cout << "Custom warning messages issued without interrupting the compilation.";
}