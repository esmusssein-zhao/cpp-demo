#include <iostream>
#include <regex>
#include <iomanip>
#include <fstream>
using namespace std;
int main()
{
	//string pattern("[^c]ei");
	//pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
	//regex r(pattern);
	////regex r("[[:alpha:]]*[^c]ei[[:alpha:]]*");
	//smatch results;
	//string test = "receipt freind theif receve";
	//if (regex_search(test, results, r))
	//	cout << results.str() << endl;
	
	/*cout << "value:" << sqrt(2.0) << '\n' << 
		hexfloat << sqrt(2.0) << '\n' << 
		uppercase << sqrt(2.0) <<'\n' << 
		nouppercase << sqrt(2.0) << '\n' << 
		defaultfloat << sqrt(2.0) << '\n' << endl;*/

	cout << setw(20) << 33 << '\n';
	cout << setw(20) << sqrt(2.0) << '\n';
	cout << left << setw(20) << sqrt(2.0) << "hello" << endl;
	cout << hex << showbase << 20 << endl;
	cout << 222 << noshowbase<<dec<<'\n' << 22 << endl;
	return 0;
	
	
}
istream& open_file(ifstream & in, const string & file)
{
	in.close();//防止流未关闭
	in.clear();//清除状态
	in.open(file);//打开文件
	return in;//返回文件流
}