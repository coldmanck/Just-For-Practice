#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Rect {
private:
	double x1 = 0.0, x2 = 0.0, y1 = 0.0, y2 = 0.0;
public:
	Rect(double xa, double xb, double ya, double yb): x1(xa), x2(xb), y1(ya), y2(yb) {}
	Rect() = default;

	friend std::istream &operator>>(std::istream &, Rect &);
	friend std::ostream &operator<<(std::ostream &, const Rect &);
	friend double find_area(const Rect &, const Rect &);

};

std::istream &operator>>(std::istream &is, Rect &r){
	is >> r.x1 >> r.x2 >> r.y1 >> r.y2;
	return is;
}

std::ostream &operator<<(std::ostream &os, const Rect &r){
	os << r.x1 << " " << r.x2 << " " << r.y1 << " " << r.y2;
	return os;
}

double find_area(const Rect &r1, const Rect &r2){
	double rx1 = (r1.x2 - r2.x1);
	double rx2 = (r2.x2 - r1.x1);
	double ry1 = (r1.y2 - r2.y1);
	double ry2 = (r2.y2 - r1.y1);
	if( rx1 * rx2 > 0)
		if( ry1 * ry2 > 0){
			double area = (rx1 > rx2 ? rx2 : rx1) * (ry1 > ry2 ? ry2 : ry1);
			return area > 0 ? area : -1.0 * area;
		}

	return 0;
}

int main(){
	Rect r1, r2;
	cin >> r1 >> r2;

	cout << "Area = " << find_area(r1, r2) << endl;

	return 0;
}
