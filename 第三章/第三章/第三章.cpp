#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <stdexcept>
using std::cin; using std::cout; using std::endl; 
using std::string; using std::vector; using std::runtime_error;
int main()
{
	/*
	string a;
	while (cin >> a)
	{
		cout << a << endl;
	}*/
	
	/*while (getline(cin, a))
	{
		cout << a << endl;
	}*/

	//3.6
	
	/*string a("kjshf89453");
	for (auto& flag : a)
		flag = 'X';
	cout << a << endl;*/

	/*for (auto flag = 0; flag < a.size(); flag++)
	{
		a[flag] = 'X';
	}
	cout << a << endl;*/

	/*char flag = 0;
	while (flag < a.size())
	{
		a[flag] = 'X';
		flag++;
	}
	cout << a << endl;*/

	//3.10
	/*string input;
	cin >> input;
	if (!input.empty())
	{
		for (auto flag = 0; flag < input.size(); flag++)
		{
			if (ispunct(input[flag]))
			{
				continue;
			}
			cout<< input[flag];
		}
	}*/

	/*if (!input.empty())
	{
		for (auto flag : input)
		{
			if (ispunct(flag))
			{
				continue;
			}
			cout << flag;
		}
		cout << endl;
	}*/

	//3.14
	/*vector<int>numb;
	int a;
	while (cin >> a)
	{
		numb.push_back(a);
	}
	for (auto b : numb)
		cout << b;*/

	//3.15
	/*vector<string>numb;
	string a;
	while (cin >> a)
	{
		numb.push_back(a);
	}*/

	//3。17
	/*string in;
	vector<string>s;
	while (cin >> in)
	{
		s.push_back(in);
	}
	for (auto &a : s)//读取每个字符串
	{
		for (auto& b : a)//读取每个字符串中的每个字符
		{
			b = toupper(b);
			cout << b << endl;
		}
	}*/
	
	//3.20-1
	/*vector<int>arr;
	vector<int>arr1;
	int a;
	while (cin >> a)
	{
		arr.push_back(a);
	}
	for (unsigned b = 0; b < arr.size(); b += 2)
	{
		if(b+1 >= arr.size())
		{
			arr1.push_back(arr[b]);
		}
		else
		{
			arr1.push_back(arr[b] + arr[b + 1]);
		}
	}
	for (auto c : arr1)
	{
		cout << c << " ";
	}*/

	//3.20-2
	/*vector<int>arr;
	vector<int>arr1;
	int a;
	while (cin >> a)
	{
		arr.push_back(a);
	}
	for (unsigned int b = 0; b <= arr.size()/2; b ++)
	{
		if (b == arr.size() - 1 - b)
		{
			arr1.push_back(arr[b]);
		}
		else
		{
			arr1.push_back(arr[b] + arr[arr.size() - 1 - b]);
		}
	}
	for (auto c : arr1)
	{
		cout << c << " ";
	}*/

	//3.22
	/*vector<int>arr;
	srand((unsigned int)time(NULL));
	for (int a = 0; a < 10; a++)
	{
		arr.push_back(rand());
	}
	cout << "原来的：";
	for (auto c : arr)
	{
		cout << c << " ";
	}
	cout << endl;
	for (auto varr = arr.begin(); varr<arr.end(); varr++)
	{
		*varr = 2 * *varr;
	}
	cout << "现在的：";
	for (auto c : arr)
	{
		cout << c << " ";
	}*/

	//3.24-1
	/*vector<int>arr;
	vector<int>arr1;
	int a;
	while (cin >> a)
	{
		arr.push_back(a);
	}
	auto arr_begin = arr.begin();
	auto arr_end = arr.end(); 
	for (arr_begin; arr_begin < arr_end; arr_begin+=2)
	{
		if (arr_begin + 1 == arr_end)
		{
			arr1.push_back(*arr_begin);
		}
		else
		{
			arr1.push_back(*arr_begin + *(arr_begin+1));
		}
	}
	for (auto c : arr1)
	{
		cout << c << " ";
	}*/

	//3.24-2
	/*vector<int>arr;
	vector<int>arr1;
	int a;
	while (cin >> a)
	{
		arr.push_back(a);
	}
	auto arr_begin = arr.begin();
	auto arr_end = arr.end();
	for (arr_begin; arr_begin <= (arr_begin + (arr_end - arr_begin)/2); arr_begin++, arr_end--)
	{
		if (arr_begin == arr_end-1)
		{
			arr1.push_back(*arr_begin);
		}
		else
		{
			arr1.push_back(*arr_begin + *(arr_end - 1));
		}
	}
	for (auto c : arr1)
	{
		cout << c << " ";
	}*/
	
	//3.25
	/*vector<unsigned>scores(11, 0);
	unsigned grade;
	while (cin >> grade)
	{
		auto fen_duan = scores.begin();
		if (grade <= 100)
		{
			//*(fen_duan + grade / 10) += 1;
			++ *(fen_duan + grade / 10);
		}
	}
	for (auto c : scores)
	{
		cout << c << " ";
	}*/
	
	//3.43
	//int ia[3][4]{0};
	//1
	/*for (int& a : ia)
	{
		for (int b : a)
		{
			cout << b;
		}
	}*/
	//2
	/*for (int a = 0; a < 3; ++a)
	{
		for (int b = 0; b < 4; ++b)
		{
			cout << ia[a][b];
		}
	}*/
	//3
	/*for (int a = 0; a < 3; ++a)
	{
		for (int b = 0; b < 4; ++b)
		{
			cout << *(*(ia + a) + b);
		}
	}*/

	//3.44
	/*using ia_y = int[4];
	for (ia_y* p = ia; p != ia + 3; ++p)
	{
		for (int* q = *p; q != *p + 4; q++)
		{
			cout << *q;
		}
	}*/
	
	//5.20
	/*cout << "输入：" << endl;
	string string1;
	string second="";
	bool flag = false;
	while (cin >> string1)
	{
		if (string1 == second)
		{
			cout << "重复的为：" << string1 << endl;
			flag = true;
			break;
		}
		else
		{
			second = string1;
		}
	}
	if (!flag)
	{
		cout << "没有了" << endl;
	}*/
	
	//5.23
	/*int a,b;
	while (cin >> a >> b)
	{
		try
		{
			if (b == 0)
			{
				throw runtime_error("不能为0！");
			}
			cout << "a / b = " << a / b << endl;
		}
		catch (runtime_error err)
		{
			cout << err.what() << endl;
			break;
		}
	}*/
	double a = 0.1;
	double b = 0.2;
	cout << a + b << endl;
	return 0;
}