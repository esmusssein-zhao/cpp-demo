#include"head.h"

using namespace std;

//12.7
/*
shared_ptr<vector<int>> make()
{
	return make_shared<vector<int>>();
}
shared_ptr<vector<int>> in(shared_ptr<vector<int>>in_p)
{
	int i;
	while (cin >> i)
		in_p->push_back(i);
	return in_p;
}
void print(shared_ptr<vector<int>>put)
{
	for (auto out : *put)
		cout << out << " ";
}
*/
int main()
{
	//print(in(make()));
	//12.23
	/*string s("hello");
	string s1("world");*/
	//内存分配和析构分离
	/*allocator<string>s2;
	auto p = s2.allocate(20);
	s2.construct(p, s + " " + s1);
	cout << *p << endl;
	s2.destroy(p);
	s2.deallocate(p, 20);*/
	//动态分配数组unique_ptr
	/*unique_ptr<char[]>up(new char[20]());
	char a = 0;
	for(char out:s)
		up[a++] = out;
	for (char out : s1)
		up[a++] = out;
	cout << up << endl;
	up.reset();*/
	return 0;
}