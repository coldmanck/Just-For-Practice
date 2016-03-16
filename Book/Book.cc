#include <iostream>
#include <string>
#include "Book.h"
using namespace std;

int Book::count = 0;

Book& Book::operator+=(const Book &b){
	amount += b.amount;
	return *this;
}

Book& Book::operator-=(const Book &b){
	amount -= b.amount;
	return *this;
}

Book operator+(const Book &b1, const Book &b2){
	Book temp = b1;
	temp += b2;
	return temp;
}

Book operator-(const Book &b1, const Book &b2){
	Book temp = b1;
	temp -= b2;
	return temp;
}

std::istream& operator>>(std::istream &is, Book &b){
	is >> b.bookName >> b.amount >> b.price >> b.code;
	return is;
}

std::ostream& operator<<(std::ostream &os, const Book &b){
	os << b.bookName << " " << b.amount << " " << b.price << " " << b.code;
	return os;
}