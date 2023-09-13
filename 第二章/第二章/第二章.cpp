#include <iostream>

int main()
{
	/*unsigned u = 10,x=40,j=-30,k=-32,a=-72;
	int i2 = 42,i = -42; 
	std::cout << j << std::endl;
	std::cout << u - x << std::endl;
	std::cout << u + x << std::endl;
	std::cout << k << std::endl;
	std::cout << u + i2 << std::endl;
	std::cout << u - i2 << std::endl;
	std::cout << u - i << std::endl;	
	std::cout << u + i << std::endl;
	std::cout << j + i << std::endl;
	std::cout << a << std::endl;
	int i = 43;
	int* p;
	int*& r = p;*/

	const int e = 423;
	int c = 21;
	double a = 3.14;
	int& f = e;
	int& i = 21;
	const int& d = c;
	const int& k = 2;
	int q = k;
	int& g = d * 2;
	const int& h = d * 2;
	const int& b = a;
	a = 2.12;
	std::cout << b <<"\n" << a << std::endl;

	/*const int x = 1;
	int y = 2;
	int* p = &x;
	const int* cp = &x;
	cp = &y;
	cp = &x;*/



	return 0;
}