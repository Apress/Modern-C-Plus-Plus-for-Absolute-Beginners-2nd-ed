#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "person.h"

namespace nm
{
    // derived class Employee
    class Employee : public Person
    {
    private:
        std::string jobtitle;
    public:
        // default constructor
        Employee();
        // user provided constructor
        Employee(const std::string& aname, int argage, const std::string& ajobtitle);
        // copy constructor
        Employee(const Employee& rhs);
        // copy assignment operator
        Employee& operator=(const Employee& rhs);
        // move constructor
        Employee(Employee&& rhs) noexcept;
        // move assignment operator
        Employee& operator=(Employee&& rhs) noexcept;
        void setjobtitle(const std::string& ajobtitle);
        std::string getjobtitle() const;
        void formatprint() override;
    };
}

#endif // !EMPLOYEE_H