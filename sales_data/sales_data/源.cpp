#include "head.h"
using namespace std;

int main()
{
	/*Salea_data total;
	if (read(cin, total))
	{
		Salea_data trans;
		while (read(cin, trans))
		{
			if (total.bookNo == trans.bookNo)
			{
				total.combine(trans);
			}
			else
			{
				print(cout, total) << endl;
				total = trans;
			}
		}
		print(cout, total) << endl;
	}
	else
	{
		cerr << "no data!" << endl;
	}*/
	Salea_data sd1;
	Salea_data sd2("001");
	Salea_data sd3("001",1,2);
	Salea_data sd4(cin);
}
