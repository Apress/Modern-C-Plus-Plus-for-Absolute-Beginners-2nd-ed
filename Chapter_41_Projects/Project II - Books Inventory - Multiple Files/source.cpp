#include "book.h"

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