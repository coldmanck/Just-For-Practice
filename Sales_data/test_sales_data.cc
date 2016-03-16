#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Sales_data.h"
using namespace std;

int Sales_data::count = 0;

int main(){
	Sales_data s1, s2("yoyo"), s3("haha", 123, 456), s4(cin);
	cout << s1 << endl << s2 << endl << s3 << endl << s4 << endl;
	Sales_data s5 = s2 + s3, s6 = s4 - s3;
	cout << "s5: " << s5 << endl << "s6: " << s6 << endl;
	s5 += s6;
	cout << "s5: " << s5 << endl << "s6: " << s6 << endl;
	
	// string str= "yoyo~~~";
	// s5 += Sales_data("yoyo~~~");
	// cout << "s5: " << s5 << endl << "s6: " << s6 << endl;
	// cout << "Please input a new object: ";
	// s5 += cin;
	Sales_data s8 = s5;	s8 += s6;
	cout << "s5: " << s5 << endl << "s6: " << s6 << endl << "s: " << s8 << endl;

	
	s5.display(cout); cout << endl;
	s5.show(); cout << endl;

	const Sales_data s7("const_book", 1000, 500);
	s7.display(cout); cout << endl;
	s7.show(); cout << endl;

	// used in file io
	ifstream if1;
	ofstream of2("/Users/DueMBA/Desktop/test.txt");
	of2 << s2 << endl << s3 << endl << s4 << endl << s5 << endl << s6 << endl;
	// s2.display(of2);

	std::vector<int> v;
	cout << "vector<int>::max_size() " << v.max_size() << endl;
	cout << "INT_MAX " << INT_MAX << endl;

	return 0;
}