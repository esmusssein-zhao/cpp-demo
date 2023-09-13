
#include "标头.h"
using namespace std;
template<typename A,typename B>
auto find(const A& type, const B& search)
{
	int flag = 0;
	for(auto a: type)
	{
		if(a == search)
		{
			return flag;
		}
		else
			++flag;
	}
	return -1;
}


extern template void print1(const int& arr);
	
template<typename D>
void print2(D& mod)
{
	for (typename D::size_type first = 0; first < mod.size(); first++)
	{
		cout << mod[first] << "  ";
	}
}
template<typename E>
void print3(E& mod)
{
	typename E::iterator bagin = mod.begin();
	typename E::iterator end = mod.end();
	for(; bagin != end; bagin++)
	{
		cout << *bagin << "  ";
	}
}
int main()
{
	
	int arr1[43]{ 1,2,344,234,4,53,3,45,345,34,52,134,645,7,565 };
	string arr2[4]{ "2135","3242","3422","sfw" };
	double arr3[6]{ 12.3,3123,31.2,4.3,234.3 };
	
	print1(arr2);
	
	print1(arr3);
	print1(arr1);
	/*vector<int>t1{ 1,2,3,65,76,34,25,45,345,5,34,534,52,65,7,56 };
	set<string>t2{ "fsd","sdjghf34","324vt4e5t","45f3ty","v457byw","erwu","11" };
	print3(t1);
	print3(t2);*/
	/*auto it = find(t1, 4);
	auto it1 = find(t2, "11");
	cout << it << endl;
	cout << it1 << endl;*/
	return 0;
}

