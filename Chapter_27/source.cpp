#include <iostream>

void myfunction()
{
    static int x = 0; // defined only the first time, skipped every other // time
    x++;
    std::cout << "Function ran: " << x << " time(s)." << '\n';
}

int main()
{
    myfunction(); // x == 1
    myfunction(); // x == 2
    myfunction(); // x == 3
}