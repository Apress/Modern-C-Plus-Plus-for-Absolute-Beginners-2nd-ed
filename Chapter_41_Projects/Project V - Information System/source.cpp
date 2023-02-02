#include <iostream>
#include <string>
#include <vector>
#include <memory>

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

	Employee::Employee() : Person(), jobtitle{ "The Default Role" }
	{}

	Employee::Employee(const std::string& aname, int argage, const std::string& ajobtitle) : Person(aname, argage), jobtitle{ ajobtitle }
	{}

	Employee::Employee(const Employee& rhs) : Person(rhs), jobtitle{ rhs.jobtitle }
	{
	}

	Employee& Employee::operator=(const Employee& rhs)
	{
		Person::operator=(rhs);
		jobtitle = rhs.jobtitle;
		return *this;
	}

	Employee::Employee(Employee&& rhs) noexcept : Person(std::move(rhs)), jobtitle{ std::move(rhs.jobtitle) }
	{
	}

	Employee& Employee::operator=(Employee&& rhs) noexcept
	{
		Person::operator=(std::move(rhs));
		jobtitle = std::move(rhs.jobtitle);
		return *this;
	}

	void Employee::setjobtitle(const std::string& ajobtitle)
	{
		jobtitle = ajobtitle;
	}

	std::string Employee::getjobtitle() const
	{
		return jobtitle;
	}

	void Employee::formatprint()
	{
		std::cout << "Employee's name: " << getname() << ", age: " << getage() << ", job title: " << jobtitle << '\n';
	}
}

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