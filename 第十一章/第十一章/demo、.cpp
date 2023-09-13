#include <string>
#include<iostream>
#include <map>
#include <vector>
#include <fstream>
#include <utility>
#include<sstream>
using namespace std;
/*void add_family(map<string, vector<string>>& family, const string& surname)
{
	if (family.find(surname) == family.end())
	{
		family[surname] = vector<string>{};
	}
}
void add_person(map<string, vector<string>>& family, const string& surname, const string& child)
{
	if (family.find(surname) == family.end())
	{
		cerr << "no family!" << endl;
	}
	else
	{
		family[surname].push_back(child);
	}
}
*/
//11.33
void translate(string& rule, string& transform)
{
	ifstream ifrule(rule);
	string getRule;
	map<string, vector<string>>mapRule;
	//每行的内容存入到map中
	while (getline(ifrule, getRule))
	{
		string word;
		istringstream words(getRule);//使用时加入sstream，不能使用istream
		int flag = 0;
		string temp;
		while (words >> word)
		{
			if (flag == 0)
			{
				temp = word;
				mapRule[temp];
				++flag;
			}
			else
			{
				mapRule[temp].push_back(word);
			}
		}
	}
	//查看map内容
	/*for (pair<string,vector<string>> out : mapRule)
	{
		for (string vec : out.second)
		{
			cout << vec << " ";
		}
		cout << endl;
	}
	for (auto out : mapRule["u"])
	{
		cout << out << " ";
	}*/
	ifstream iftransform(transform);
	string getTrans;
	//输出翻译内容
	while (iftransform >> getTrans)
	{
		auto temp = mapRule.find(getTrans);
		auto end = mapRule.cend();
		if (temp != end)
		{
			for (auto out : temp->second)
			{
				cout << out << " ";
			}
		}
		else
		{
			cout << getTrans << " ";
		}
	}
}
int main()
{
	/*map<string, vector<string>>family;
	add_family(family, "yi");
	add_person(family, "yi", "yyz");
	add_person(family, "yi", "yyy");
	for (auto temp : family["yi"])
		cout << temp << endl;
	add_person(family, "zhang", "yyy");
	cout << "hello" << endl;*/
	string rule("rule.txt");
	string transform("transform.txt");
	translate(rule, transform);
	return 0;
}