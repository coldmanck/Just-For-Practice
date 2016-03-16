#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

class Rect {
private:
	double x1 = 0.0, x2 = 0.0, y1 = 0.0, y2 = 0.0;
	double area = 0.0;
	void init(){ area = abs((x2 - x1) * (y2 - y1)); }
public:
	Rect(double xa, double xb, double ya, double yb): x1(xa), x2(xb), y1(ya), y2(yb) { init(); }
	Rect() = default;

	double getArea(){ return area; }

	friend std::istream &operator>>(std::istream &, Rect &);
	friend std::ostream &operator<<(std::ostream &, const Rect &);
	friend double find_area(const Rect &, const Rect &);

};

std::istream &operator>>(std::istream &is, Rect &r){
	is >> r.x1 >> r.x2 >> r.y1 >> r.y2;
	r.init();
	return is;
}

std::ostream &operator<<(std::ostream &os, const Rect &r){
	os << r.x1 << " " << r.x2 << " " << r.y1 << " " << r.y2 << " " << r.area;
	return os;
}

double find_area(const Rect &r1, const Rect &r2){
	double rx1 = (r1.x2 - r2.x1);
	double rx2 = (r2.x2 - r1.x1);
	double ry1 = (r1.y2 - r2.y1);
	double ry2 = (r2.y2 - r1.y1);
	if( rx1 * rx2 > 0 && ry1 * ry2 > 0){
		double area = (rx1 > rx2 ? rx2 : rx1) * (ry1 > ry2 ? ry2 : ry1);
		return abs(area);
	}

	return 0;
}

int main(){
	double count;
	cin >> count;
	vector<Rect> rects(count);
	for(auto i = rects.begin(); i != rects.end(); ++i)
		cin >> *i;
	
	double sum = 0.0;
	vector<double> intersecAreas(count * (count - 1) / 2, 0.0);
	for(auto i = rects.begin(); i != rects.end() - 1; ++i)
		for(auto j = i + 1; j != rects.end(); ++j){
			double area = find_area(*i, *j);
			intersecAreas.push_back(area);
			sum += area;
			cout << i - rects.begin() << "-th & " << j - rects.begin() << "-th area: " << area << endl;
		}

	cout << "Intersection area = " << sum << endl;

	return 0;
}

/*
Test input:
2
0 1 0 1
0.5 1.5 0 1

Test output:
0-th & 1-th area: 0.5
Intersection area = 0.5
*/
