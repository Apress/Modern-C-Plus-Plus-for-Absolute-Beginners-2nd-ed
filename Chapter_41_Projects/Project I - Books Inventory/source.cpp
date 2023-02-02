#include <iostream>
#include <vector>
#include <string>

class Book
{
private:
	std::string title;
	int pages;
public:
	Book();
	Book(const std::string& atitle, int apages);
	void printdata();
	std::string gettitle() const;
	int getpages() const;
	void settitle(const std::string& atitle);
	void setpages(int apages);
};

Book::Book() : title{ "Default Book Title" }, pages{ 0 }
{
}

Book::Book(const std::string& atitle, int apages) : title{ atitle }, pages{ apages }
{
}

void Book::printdata()
{
	std::cout << "The book title is: " << title << ", and the number of pages is: " << pages << '\n';
}

std::string Book::gettitle() const
{
	return title;
}

int Book::getpages() const
{
	return pages;
}

void Book::settitle(const std::string& atitle)
{
	title = atitle;
}

void Book::setpages(int apages)
{
	pages = apages;
}

int main()
{
	Book defaultbook;
	std::cout << "Default constructor invoked." << '\n';

	Book mybook{ "My Book Title", 123 };
	std::cout << "User-provided constructor invoked." << '\n';
	mybook.printdata();

	std::cout << "The book title is: " << mybook.gettitle() << '\n';
	std::cout << "The number of pages is: " << mybook.getpages() << '\n';

	std::cout << "Setting the new title... " << '\n';
	mybook.settitle("New Book Title");
	std::cout << "Setting the new number of pages... " << '\n';
	mybook.setpages(456);
	mybook.printdata();

	std::cout << "\nCreating an inventory of books... " << '\n';
	std::vector<Book> v = {
		Book("Sample Book Title 1", 100),
		Book("Sample Book Title 2", 200),
		Book("Sample Book Title 3", 300),
		Book("Sample Book Title 4", 400),
		Book("Sample Book Title 5", 500),
	};
	for (auto& el : v)
	{
		el.printdata();
	}
}