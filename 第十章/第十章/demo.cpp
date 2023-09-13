#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <list>
#include <numeric>
#include<functional>

using namespace std;
using namespace std::placeholders;
/*
//10.14&10.15
bool isShort(const string& s1, const string& s2)
{
	return s1.size() < s2.size();
}
bool division(const string& s1)
{
	return s1.size() > 5;
}
//10.16
void biggies(vector<string> strve, int a)
{
	auto begin = strve.begin();
	auto end = strve.end();
	do
	{
		auto temp = find_if(begin, end, [a](const string& str) {return str.size() == a; });//找到长度等于a的单词
		if (temp == end)//未找到时，temp为end
			break;
		cout << *temp << " ";
		begin = temp + 1;//避免进入死循环
	} while (begin != end);
}
*/
//对stream进行输出
istream& print(istream& in)
{
	int i;
	while (in >> i)
	{
		cout << i << " ";
	}
	in.clear();
	return in;
}
//10.33  使用ifstream、ofstream、istream_iterator、ostream_iterator拆分文件内容
void split(string& file_from, string& file_odd, string& file_even)
{
	ifstream in(file_from);
	//print(in);//添加后其他两个文件的内容为空
	ofstream out_odd(file_odd);
	ofstream out_even(file_even);
	istream_iterator<int>intii(in), eof;
	ostream_iterator<int> intoit_odd(out_odd, " ");
	ostream_iterator<int> intoit_even(out_even, " ");
	while (intii != eof)
	{
		if (*intii % 2)
		{
			*intoit_odd++ = *intii;
			intii++;
		}
		else
		{
			*intoit_even++ = *intii;
			intii++;
		}
	}
}
int main()
{
	//10.33
	string s1("demo.txt");
	ifstream in(s1);
	print(in);
	in.close();
	cout << endl;
	string s2("odd.txt");
	string s3("even.txt");
	split(s1, s2, s3);//拆分文件内容

	ifstream in_odd("odd.txt");
	cout << "奇数为：";
	print(in_odd);
	cout << endl;
	in_odd.close();

	ifstream in_even("even.txt");
	cout << "偶数为：";
	print(in_even);
	in_even.close();
	//10.31
	/*istream_iterator<int> striit(cin), eof;
	ostream_iterator<int> stroit(cout," ");
	vector<int>striitp;
	while (striit != eof)
	{
		striitp.push_back(*striit++);//迭代器后移
	}
	sort(striitp.begin(), striitp.end());
	copy(striitp.begin(), striitp.end(), stroit);*/
	//10.29
	/*ifstream in("word.txt");
	istream_iterator<string>in_iter(in), eof;
	vector<string>strvecis(in_iter, eof);//直接使用拷贝初始化
	for (auto temp : strvecis)
		cout << temp << " ";
	*/
	/*//ifstream in("word.txt");
	vector<string>strve{ "1","3","4","5","6","7","8","9" };
	//string str;
	//int a = 4;
	////while (in >> str)
	//	strve.push_back(str);*/
	//10.28
	/*vector<string>strvec_ins;
	vector<string>strvec_back;
	vector<string>strvec_front;
	//unique_copy(strve.begin(), strve.end(), inserter(strvec_ins, strvec_ins.end()));
	//unique_copy(strve.begin(), strve.end(), back_inserter(strvec_back));
	//unique_copy(strve.begin(), strve.end(), front_inserter(strvec_front));//error
	//for (auto temp : strvec_ins)
	for (auto temp : strvec_front)
		cout << temp << " ";
	*/
	//10.27
	/*vector<string>strve_e;
	unique_copy(strve.begin(), strve.end(), back_inserter(strve_e));
	for (auto temp : strve_e)
		cout << temp << " ";*/
	//10.22
	/*auto size_bind = bind(biggies, _1, _2);
	size_bind(strve, 2);*/
	//10.21
	/*auto fun = [&a] ()->bool {while (a)--a; return a; };
	auto a_new = fun();
	cout << "the number is :" << a_new << endl;
	cout << "a is :" << a << endl;*/
	//10.20
	/*auto count = count_if(strve.begin(), strve.end(), [a](const string& str) {return str.size() > a; });
	cout << "->" << count << endl;*/
	//10/18
	/*stable_sort(strve.begin(), strve.end(), isShort);
	auto flag = partition(strve.begin(), strve.end(), [a](const string& str) {return str.size() == a; });
	auto start = strve.cbegin();
	for (; start < flag; start++)
	{
		cout << *start << " ";
	}
	//biggies(strve, a);*/
	//10.11
	/*
		sort(strve.begin(),strve.end());
		auto end_unique = unique(strve.begin(),strve.end());
		strve.erase(end_unique,strve.end());
		stable_sort(strve.begin(),strve.end(),isShort);
		for(auto temp:strve)
			cout<<temp<<" ";
	*/
	//10.13
	/*
	stable_sort(strve.begin(),strve.end(),isShort);
	auto flag = partition(strve.begin(),strve.end(),division);
	auto start = strve.cbegin();
	for(;start<=flag;start++)
	{
		cout<<*start<<" ";
	}
	*/
	//10.14&10.15
	/*
	int a=1;
		int b=2;
	//	auto total_two = [](int a,int b)->int{return a+b;};
		auto total_one = [a](int b)->int{return a+b;};
	//	cout<<"a+b="<<total_two(a,b)<<endl;
		cout<<"a+b="<<total_one(6)<<endl;
	*/	
	//10.1&10.2
	/*ifstream in("demo.txt");
	//vector<int>intvec;
	list<string>strlis;
	//int int_in;
	string int_in;
	while (in >> int_in)
	{
		//intvec.push_back(int_in);
		strlis.push_back(int_in);
	}
	cout << "vector<int>intvec is->";
	//for (auto put : intvec)
	for (auto put : strlis)
		cout << put << " ";
	cout << endl;
	cout << "12 times is=>";
	//cout << count(intvec.cbegin(), intvec.cend(), 12) << endl;
	cout << count(strlis.cbegin(), strlis.cend(), "12") << endl;*/
	//10.3&10.6
	/*//ifstream in("demo.txt");
	ifstream in("demo2.txt");
	vector<int>intvec;
	int int_in;
	while (in >> int_in)
	{
		intvec.push_back(int_in);
	}
	fill_n(intvec.begin(), intvec.size(), 0);
	for (auto put : intvec)
		cout << put << " ";
	//cout << "total is ->" << accumulate(intvec.cbegin(), intvec.cend(), 0) << endl;*/
	return 0;
}