#include <iostream>
#include <string>
#include <vector>
using namespace std;
string& singleSentenceProcessing(string& s)
{

}

string rPrint(char* st)
{
	string s = st;
	string rStr;
	int seat= 0;
	do
	{
		auto location = s.find('.', seat);
		if(string::npos != location)
		{
			seat = location + 1;
			string sStr(s, 0, location + 1);
			rStr += singleSentenceProcessing(sStr);
		}
		else
		{
			break;
		}
	} while (true);
}

int main()
{
	char st[] = "i am.";
	rPrint(st);

	return 0;
}