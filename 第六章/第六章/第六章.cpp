#include <iostream>
#include <string>
#include <vector>

using namespace std;
//int main(int a,char **b)
//{
//	string c;
//	for (int i = 0; i != a; ++i)
//	{
//		c += b[i];
//	}
//	cout << c << endl;
//	return 0;
//}
//6.26
//int total(initializer_list<int>list)
//{
//	int total = 0;
//	/*for (auto beg = list.begin(); beg != list.end(); ++beg)
//	{
//		total += *beg;
//	}*/
//	for (auto a : list)
//	{
//		total += a;
//	}
//	return total;
//}
int add(int a, int b)
{
	return a + b;
}
int sub(int a, int b)
{
	return a - b;
}
int mult(int a, int b)
{
	return a * b;
}
int division(int a, int b)
{
	return a / b;
}
int main()
{
	/*cout << total({ 1, 2, 3, 4 }) << endl;*/
	vector<decltype(add)*>fun{ add,sub,mult,division };//�Զ�ת��Ϊָ�룬���Բ���&
	int a, b;
	cin >> a >> b;
	for (auto flag : fun)
	{
		cout << flag(a, b) << endl;
	}
	return 0;
}