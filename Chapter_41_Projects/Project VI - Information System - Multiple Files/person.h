#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

namespace nm
{
    // base class Person
    class Person
    {
    private:
        std::string name;
        int age;
    public:
        // default constructor
        Person();
        // user-provided constructor
        Person(const std::string& aname, int argage);
        // copy constructor
        Person(const Person& rhs);
        // copy assignment operator
        Person& operator=(const Person& rhs);
        // move constructor
        Person(Person&& rhs) noexcept;
        // move assignment operator
        Person& operator=(Person&& rhs) noexcept;
        void printname();
        void printage();
        void printdata();
        std::string getname() const;
        int getage() const;
        void setname(const std::string& aname);
        void setage(int argage);
        virtual void formatprint();
        // virtual base class destructor
        virtual ~Person() {}
    };
}

#endif // !PERSON_H