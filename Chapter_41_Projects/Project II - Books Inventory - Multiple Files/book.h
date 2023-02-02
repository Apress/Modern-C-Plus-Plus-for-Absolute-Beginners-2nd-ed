#ifndef BOOK_H
#define BOOK_H

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

#endif