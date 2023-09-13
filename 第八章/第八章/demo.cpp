#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <list>
#include <deque>
#include <stack>
using namespace std;
/*istream& print(istream& in)
{
	string s;
	while (in.eof(), in >> s) 
	{
		cout << s << " ";
	}
	in.clear();
	return in;
}
*/
//9.45
/*string &call(string &a,string b,string c)
{
	a.insert(0,b);
	a.append(c);
	return a;
}*/
//9.46
/*string& call(string& a, string b, string c)
{
	a.insert(0, b);
	a.insert(a.size(), c);
	return a;
}
*/

/*class Date
{
private:
	unsigned year;
	unsigned mouth;
	unsigned day;
public:
	Date() = default;
	Date(unsigned a) :year(a), mouth(1), day(1) {};
	Date(unsigned a, unsigned b, unsigned c) :year(a), mouth(b), day(c) {};
	Date(std::istream& is);
	unsigned getYear() { return year; }
	unsigned getMouth() { return mouth; }
	unsigned getDay() { return day; }
	Date(string& s)
	{
		//string temp = s;
		string::size_type pos = 0;
		string numbers{ "JFMAOSND123456789" };
		pos = s.find_first_of(numbers, pos);
		if (s[pos] < 57 && s[pos] > 48)
		{
			pos = s.find('/', pos) + 1;
			string dayf = s.erase(pos);
			day = stoul(dayf);
			//s被改变,在使用s.erase时，导致下面出现越界
			pos = s.find_first_of(numbers, pos);
			if (s[pos + 1] != '/')
			{
				string mouf = s.erase(0, pos);
				mouf = mouf.erase(2);
				mouth = stoul(mouf);
				string yeaf(s, pos + 1);
				year = stoul(yeaf);
			}
			else
			{
				string mouf = s.erase(0, pos);
				mouf = mouf.erase(1);
				mouth = stoul(mouf);
				string yeaf(s, pos + 1);
				year = stoul(yeaf);
			}
		}
	};
	void output(Date info);
};
Date::Date(std::istream& is)
{
	cout << "分别输入年月日->";
	is >> year >> mouth >> day;
}
void Date::output(Date info)
{
	cout << info.getYear() << "年" << info.getMouth() << "月" << info.getDay() << "日" << endl;
}
*/
//9.52
string handleNum(vector<string>operCon)//处理 收到内容(操作内容)函数
{
	string result{ "计算器功能" };
	//实现计算器功能，传入的内容是string，需要转化为char进行识别
	return result;
}
int main()
{
	/*string s{ "5/15/2022" };
	Date demo1(s);
	demo1.output(demo1);*/
	//8.1
	/*ifstream file("a.txt");
	if (!file)
	{
		cerr << "open file woring!";
		return -1;
	}
	print(file);
	file.close();*/
	//8.5
	/*string file("a.txt");
	ifstream in;
	in.open(file);
	if (!in)
	{
		cerr << "open file woring!";
		return -1;
	}
	vector<string>output;
	string s;
	while (in >> s)
	{
		output.push_back(s);
	}
	for (string out : output)
	{
		cout << out << endl;
	}*/
	//8.4
	/*string file("a.txt");
	ifstream in;
	in.open(file);
	//ifstream in("a.txt");
	if (!in)
	{
		cerr << "open file woring!";
		return -1;
	}
	string line;
	vector<string>output;
	while (getline(in, line))
	{
		output.push_back(line);
	}
	in.close();
	for (string out : output)
		{
			cout << out << endl;
		}*/
	//8.9
	/*string file("a.txt");
	ifstream in;
	in.open(file);
	if (!in)
	{
		cerr << "open file woring!";
		return -1;
	}
	string s;
	while (in >> s)
	{
		istringstream a(s);
		print(a);
		cout << endl;
	}*/
	//8.10
	/*ifstream in("a.txt");
	if (!in)
	{
		cerr << "open file woring!";
		return -1;
	}
	string str;
	vector<string>vs;
	while (in >> str)
	{
		vs.push_back(str);
	}
	auto v_e = vs.end();
	for (auto v_b = vs.begin(); v_b < v_e; v_b++)
	{
		istringstream a(*v_b);
		cout << a.str() << " ";
	}*/
	//9.13
	/*list<int> li{ 1,2,3,4,5 };
	vector<double>vd;
	for (auto temp : li)
		vd.push_back(temp);
	for (auto out : vd)
		cout << out << " ";
	cout << endl;
	vd={ 5,6,7,8,9 };
	for (auto out : vd)
		cout << out << " ";*/
	//9.18
	/*string input;
	deque<string>sdeq;
	while (cin >> input)
	{
		sdeq.push_back(input);
	}
	auto end = sdeq.end();
	auto begin = sdeq.begin();
	for (begin; begin < end; begin++)
	{
		cout << *begin << " ";
	}*/
	//9.19
	/*string input;
	list<string>sdeq;
	while (cin >> input)
	{
		sdeq.push_back(input);
	}
	auto end = sdeq.end();
	auto begin = sdeq.begin();
	for (begin; begin != end; begin++)
	{
		cout << *begin << " ";
	}*/
	//9.20
	/*list<int>ilis{ 1,2,3,4,5,6,7,8,9,10 };
	deque<int>ide1;
	deque<int>ide2;
	for (auto flag : ilis)
	{
		if ((flag) % 2)
		{
			ide1.push_back(flag);
		}
		else
		{
			ide2.push_back(flag);
		}
	}
	cout << "ide1:" << endl;
	for (auto flag : ide1)
		cout << flag << " ";
	cout << endl;
	cout << "ide2:" << endl;
	for (auto flag : ide2)
		cout << flag << " ";*/
	//9.43
	/*string oldVal{"tho"};
	string s(oldVal);
	string newVal{ "though" };
	//s.insert(0, newVal).erase(6, 3);
	//s.replace(0, 3, newVal);
	s.append(newVal,3,3);
	cout << s << endl;*/
	//9.45.6
	/*string name{ "yi" };
	name = call(name, "Mr.", " Jr.");
	cout << name << endl;
	*/
	//9.49
	/*vector<string> svc{ "1.1","2.2","3.3","4.4","5.5","6.6" };
	double total = 0;
	for (auto flag : svc)
	{
		total += stod(flag);
		//total+=flag;
	}
	cout << "total is->" << total << endl;
	return 0;*/
	//9.52
	stack<string>strStac;//栈
	vector<string>input{ "(","2","+","4",")","+","5","*","2" };//输入内容
	vector<string>handle;//处理括号内的内容
	vector<unsigned>lFlag;//左括号标记容器
	unsigned rFlag = 0;//右括号标记
	for (auto put : input)
	{
		if (put == "(")
		{
			strStac.push(put);
			lFlag.push_back(strStac.size());
		}
		if (put == ")")
		{
			strStac.push(put);
			rFlag = strStac.size();
			for (lFlag.back(); lFlag.back() < rFlag; lFlag.back()++)//把括号内内容放入“处理括号内的内容”中
			{
				strStac.pop();
				handle.insert(handle.begin(),strStac.top());//头插，vector不能使用push_front
			}
			lFlag.pop_back();//删除已经出栈的左括号的位置
			strStac.pop();
			string handleNumEnd = handleNum(handle);//处理收到内容
			strStac.push(handleNumEnd);//处理后内容再次入栈
			handle.clear();//清除处理过的内容
		}
		strStac.push(put);
	}
	if (strStac.size() != 0)
	{
		handle.insert(handle.begin(), strStac.top());
		strStac.pop();
	}
	string numEnd = handleNum(handle);//处理剩余内容
	for (auto last : input)
		cout << last;
	cout << "=" << numEnd << endl;//输出结果
	return 0;
}