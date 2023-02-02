#include "employee.h"
#include <vector>
#include <memory>

using namespace nm;

int main()
{
    // a vector unique pointers
    std::vector<std::unique_ptr<Person>> v2;
    v2.emplace_back(std::make_unique<Employee>("Sample Name 1", 20, "Developer"));
    v2.emplace_back(std::make_unique<Employee>("Sample Name 2", 25, "Engineer"));
    v2.emplace_back(std::make_unique<Employee>("Sample Name 3", 30, "Quality Assurance"));
    v2.emplace_back(std::make_unique<Employee>("Sample Name 4", 35, "Human Resources"));
    v2.emplace_back(std::make_unique<Employee>("Sample Name 5", 40, "Manager"));
    v2.emplace_back(std::make_unique<Employee>("Sample Name 6", 45, "CEO"));
    for (const auto& el : v2)
    {
        el->formatprint();
    }

    std::cout << "Testing..." << '\n';
    // testing
    Employee o3; // The default constructor invoked
    Employee o4("Sample name 7", 50, "Accountant");
    // copy assignment test:
    o3 = o4;
    o3.formatprint();
}