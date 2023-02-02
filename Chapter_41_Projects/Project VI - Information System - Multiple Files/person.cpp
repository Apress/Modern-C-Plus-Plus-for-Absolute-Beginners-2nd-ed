#include "person.h"

namespace nm 
{
    Person::Person() : name{ "Default name" }, age{ -1 }
    {
    }

    Person::Person(const std::string& aname, int argage) : name{ aname }, age{ argage }
    {
    }

    Person::Person(const Person& rhs) : name{ rhs.name }, age{ rhs.age }
    {
    }

    Person& Person::operator=(const Person& rhs)
    {
        name = rhs.name;
        age = rhs.age;
        return *this;
    }

    Person::Person(Person&& rhs) noexcept : name{ std::move(rhs.name) }, age{ std::move(rhs.age) }
    {
    }

    Person& Person::operator=(Person&& rhs) noexcept
    {
        name = std::move(name);
        age = std::move(age);
        return *this;
    }

    void Person::printname()
    {
        std::cout << name << '\n';
    }

    void Person::printage()
    {
        std::cout << age << '\n';
    }

    void Person::printdata()
    {
        std::cout << name << ' ' << age << '\n';
    }

    std::string Person::getname() const
    {
        return name;
    }

    int Person::getage() const
    {
        return age;
    }

    void Person::setname(const std::string& aname)
    {
        name = aname;
    }

    void Person::setage(int argage)
    {
        age = argage;
    }

    void Person::formatprint()
    {
        std::cout << "Person's name: " << name << ", age: " << age << '\n';
    }
}