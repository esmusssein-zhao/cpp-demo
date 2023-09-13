#include <iostream>
#include <algorithm>
using namespace std;
struct DOT
{
	double x;
	double y;
	DOT() = delete;
	DOT(double a,double b):x(a),y(b){}
};

//bool isOnLine(DOT a,DOT b,DOT c)
//{
//	double k = (a.y - b.y) / (a.x - b.x);
//	if (k == ((a.y - c.y) / (a.x - c.x)))
//	{
//		if (c.x >= min({ a.x,b.x }) && c.x <= max({ a.x,b.x }))
//			return true;
//	}
//	return false;
//}

bool isOnLine(DOT a, DOT b, DOT c)
{
	if (c.y == ((a.y - b.y) / c.x) / (a.x - b.x) + (a.y * (a.x - b.x) / b.x * (a.y - b.y)))
		return true;
	return false;
}

//double distance(DOT a, DOT b)
//{
//	double x, y;
//	x = fabs(a.x - b.x);
//	y = fabs(a.y - b.y);
//	return sqrt(x * x + y * y);
//}
//bool isOnLine(DOT a, DOT b, DOT c)
//{
//
//	if (distance(a, b) == distance(a, c) + distance(c, b))
//		return true;
//	return false;
//}

int main() 
{
	DOT a(12.1, -1.51);
	DOT b(-2.4, 2.43);
	DOT c(-2.4, 2.43);
	cout << isOnLine(a,b,c) << endl;
	return 0;
}
