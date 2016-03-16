#include <iostream>
#include <string>
#include "Book.h"
using namespace std;

int main(){
	Book b1, b2("The Lord"), b3("Harry Potter", 50, 250);
	cout << b1 << endl << b2 << endl << b3 << endl;


	return 0;
}