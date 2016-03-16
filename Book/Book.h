#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>

class Book {
private:
	std::string bookName;
	int amount = 0;
	double price = 0.0;
	static int count;
	int code;

	void init(){ ++count; code = count;}
	void do_display(std::ostream &os) const { os << *this; }

public:
	explicit Book(std::string b): bookName(b) { init(); }
	Book(): Book("") { init(); }
	Book(std::string b, int a, double p): bookName(b), amount(a), price(p) { init(); }

	Book &operator+=(const Book &);
	Book &operator-=(const Book &);
	Book &display(std::ostream &os) {
		do_display(os); 
		return *this; 
	}
	const Book &display(std::ostream &os) const {
		do_display(os);
		return *this;
	}

	friend Book operator+(const Book &, const Book &);
	friend Book operator-(const Book &, const Book &);
	friend std::istream &operator>>(std::istream &, Book &);
	friend std::ostream &operator<<(std::ostream &, const Book &);
};

// friend functions need to be declared
Book operator+(const Book &, const Book &);
Book operator-(const Book &, const Book &);
std::istream &operator>>(std::istream &, Book &);
std::ostream &operator<<(std::ostream &s, const Book &);

#endif