#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <iostream>
#include <string>

class Sales_data{
private:
	std::string bookNo = "book_number";
	unsigned units_sold = 0;
	double revenue = 0.0;
	void do_display(std::ostream &os) const { os << *this; }
	void do_show() const { std::cout << *this; }
	static int count;

public:
	// Sales_data() = default;
	Sales_data() { ++count; }
	explicit Sales_data(const std::string &b): bookNo(b) { ++count; }
	Sales_data(const std::string &b, unsigned u, double p): bookNo(b), units_sold(u), revenue(p*u) { ++count; }
	explicit Sales_data(std::istream &);
	// error: an initializer for a delegating constructor must appear alone
	// Sales_data(const std::string &b, unsigned u, double p): Sales_data(b), units_sold(u), revenue(p*u) { ++count; }

	std::string isbn() const { return bookNo; }
	double avg_price() const;
	Sales_data &display(std::ostream &os){ do_display(os); os << " (plain version display)"; return *this; }
	const Sales_data &display(std::ostream &os) const { do_display(os); os << " (const version display)"; return *this; }
	Sales_data &show(){ do_show(); std::cout << " (plain version show)"; return *this; }
	const Sales_data &show() const { do_show(); std::cout << " (const version show)"; return *this; }

	Sales_data &operator+=(const Sales_data &);
	Sales_data &operator-=(const Sales_data &);

	// non-member functions
	friend std::ostream &operator<<(std::ostream &, const Sales_data &);
	friend std::istream &operator>>(std::istream &, Sales_data &);
	friend Sales_data operator+(const Sales_data &, const Sales_data &);
	friend Sales_data operator-(const Sales_data &, const Sales_data &);
};

Sales_data::Sales_data(std::istream &is){
	is >> *this;
	++count;
}

double Sales_data::avg_price() const{
	if(units_sold)
		return revenue / units_sold;
	else 
		return 0;
}

std::ostream &operator<<(std::ostream &os, const Sales_data &item){
	os << item.isbn() << " " << item.units_sold << " "
	   << item.revenue << " " << item.avg_price() << " count = " << Sales_data::count;
	return os;
}

std::istream &operator>>(std::istream &is, Sales_data &item){
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

Sales_data& Sales_data::operator+=(const Sales_data &item){
	units_sold += item.units_sold;
	revenue += item.revenue;
	return *this;
}

Sales_data& Sales_data::operator-=(const Sales_data &item){
	units_sold -= item.units_sold;
	revenue -= item.revenue;
	return *this;
}

Sales_data operator+(const Sales_data &item1, const Sales_data &item2){
	Sales_data temp = item1;
	temp += item2;
	return temp;
}

Sales_data operator-(const Sales_data &item1, const Sales_data &item2){
	Sales_data temp = item1;
	temp -= item2;
	return temp;
}


#endif