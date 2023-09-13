#include <iostream>
#include <set>
#include <map>
#include <vector>

using namespace std;

class PERSON
{
protected:
	string name;
	map<string, double> scores;
public:
	virtual void AddS(string, double) = 0;
};
class STUDENT:public PERSON
{
	friend class PROJECT;
protected:
	string name;
	map<string, double> scores;
public:
	STUDENT(string n) :name(n) {}
	STUDENT(string n, string cN, double s) :name(n)
	{
		scores.insert({ cN,s });
	}
	void AddS(pair<string, double> c) 
	{
		scores.insert(c);
	}
	void AddS(string cN, double s) override
	{
		scores.insert({ cN,s });
	}
protected:
	double rClassScore(string clsaaName)
	{
		srand((unsigned int)time(NULL));
		auto f = scores.find(clsaaName);
		if (f != scores.end())
			return (*f).second;
		else
		{
			int score = rand();
			scores.insert({ clsaaName ,score });
		}
	}
};

class BOARDLINE
{
public:
	virtual int borderline() = 0;
};

class PROJECT :public BOARDLINE
{
private:
	string className;
	multiset<double> sameClass;
	int num;
	
public:
	PROJECT(string cN, vector<STUDENT*> s):className(cN),num(0)
	{
		for (const auto& ev : s)
		{
			++num;
			sameClass.insert((*ev).rClassScore(className));
		}
	}
	int borderline() override
	{
		auto temp = sameClass.cbegin();
		for (int t = 1; t < num * 0.6; t++)
			temp++;
		if (*temp > 60)
		{
			return 60;
		}
		int argC = static_cast<int>(*temp) % 10;
		if (argC)
		{
			return (argC + 1) * 10;
		}
		else
			return argC * 10;
	}
	~PROJECT() = default;
};

int main(int agrc, char** argv)
{
	vector<STUDENT*> s;
	for (int i = 0; i < 1000; i++)
	{
		STUDENT* n = new STUDENT("student");
		s.emplace_back(n);
	}
	PROJECT English("English", s);
	PROJECT Chinese("Chinese", s);
	PROJECT Math("Math", s);
	PROJECT PE("PE", s);
	PROJECT Music("Music", s);
	return 0;
}