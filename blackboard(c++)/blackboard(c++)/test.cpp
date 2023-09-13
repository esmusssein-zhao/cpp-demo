#include <iostream>
#include <iomanip>
#include <string>
#include <iterator>
#include <vector>
#include <array>
#include <map>
#include <set>
#include <sstream>
#include <fstream>
#include <tuple>
#include <queue>
#include <iterator>
#include <algorithm>
#include <functional>
#include <memory>
#include <thread>
#include <Windows.h>
#include <tuple>
using namespace std::placeholders;
using namespace std;
#define DEBUG
/*
void arry_same_search(int arr[])
{
	int arr_p[11]{};
	for (int x = 0; x < 11; x++)
	{
		arr_p[arr[x]]++;
	}
	for (int x = 0; x < 11; x++)
	{
		if (arr_p[x] > 1)
			cout << x << endl;
	}
}
bool arr_two_find(int* arr,int x,int y,int temp)
{
	int n = 0;
	int m = x - 1;
	while(n<=y && m>=0)
	{
		if (arr[m * y + n] == temp)
			return true;
		else if (arr[(x - 1) * y + n] > temp)
		{
			m -= 1;
			break;
		}
			n += 1;
	}
	return false;
}
//多线程下不安全
//class LAZY
//{
//private:
//	LAZY() = default;
//	static LAZY* p;
//public:
//	static LAZY* LAZY_interface()
//	{
//		if (p == nullptr)
//			p = new LAZY;
//		else
//			return p;
//	}
//};
//LAZY* LAZY::p = nullptr;
//
//class HUNGRY
//{
//private:
//	HUNGRY() = default;
//	static HUNGRY* p;
//public:
//	static HUNGRY* HUNGRY_inerface()
//	{
//		return p;
//	}
//};
//HUNGRY* HUNGRY::p = new HUNGRY;


class OPERATOR_t
{
private:
	int a;
public:
	OPERATOR_t():a(0){}
	int return_a() const
	{
		return a;
	}
};
ostream& operator<<(ostream& o, const OPERATOR_t& c)
{
	o << c.return_a();
	return o;
}
double searchhMedian(const vector<int>& v1, const vector<int>& v2)
{
	vector<int> count;
	for (auto& a : v1)
		count.push_back(a); 
	for (auto& a : v2)
		count.push_back(a);
	sort(count.begin(), count.end());
	size_t size = count.size();
	if ((size % 2) == 0)
		return (count[size / 2] + count[size / 2 + 1]) / 2;
	else
		return count[size / 2 + 1];
}

void arr_add_sort(int* arr1,int arr1_real_n, int* arr2, int arr2_real_n)
{
	int end = arr2_real_n + arr1_real_n - 1;
	int arr1_e = arr1_real_n - 1;
	int arr2_e = arr2_real_n - 1;
	while (arr1_e >= 0 || arr2_e >= 0)
	{
		if (arr1_e < 0)
		{
			while (arr2_e >= 0)
			{
				arr1[end--] = arr2[arr2_e--];
			}
			break;
		}
		if (arr2_e < 0)
		{
			while (arr1_e >= 0)
			{
				arr1[end--] = arr1[arr1_e--];
			}
			break;
		}
		if (arr1[arr1_e] >= arr2[arr2_e])
		{
			arr1[end--] = arr1[arr1_e--];
		}
		else
		{
			arr1[end--] = arr2[arr2_e--];
		}
	}

}*/
//
//void bubbleSor(int* arr, int num)
//{
//	for (int k = 0; k < num; k++)
//	{
//		for (int i = 0; i < num - 1; i++)
//		{
//			if (arr[i] > arr[i + 1])
//			{
//				int temp = arr[i];
//				arr[i] = arr[i + 1];
//				arr[i + 1] = temp;
//			}
//		}
//	}
//	for (int i = 0; i < num; i++)
//	{
//		cout << arr[i] << endl;
//	}
//		
//}
//
//void selectionSort(int* arr, int num)
//{
//	for (int i = 0; i < num-1; i++)
//	{
//		for (int j = i + 1; j < num; j++)
//		{
//			if (arr[i] > arr[j])
//			{
//				int temp = arr[i];
//				arr[i] = arr[j];
//				arr[j] = temp;
//			}
//		}
//	}
//	for (int i = 0; i < num; i++)
//	{
//		cout << arr[i] << endl;
//	}
//}
//
//void insertionSort(int* arr, int num)
//{
//	for (int i = 1; i < num; i++)
//	{
//		for (int j = 0; j < i; j++)
//		{
//			if (arr[j] < arr[i])
//			{
//				int temp = arr[j];
//				for (int k = j; k > -1; k--)
//				{
//					arr[j] = arr[k - 1];
//				}
//			}
//		}
//	}
//}
//int re_n(int n)
//{
//	if (n == 0)
//		return 0;
//	if (n == 1)
//		return 1;
//	if (n == 2)
//		return 1;
//	if (n == 3)
//		return 2;
//	if (n == 4)
//		return 4;
//	else
//		return  2 * re_n(n - 1) - re_n(n - 4);
//}
//vector<int> replaceElements(std::vector<int>& arr)
//{
//	std::vector<int> re(arr);
//	std::vector<int>::iterator temp = arr.begin();
//	std::vector<int>::iterator end = arr.end(); 
//	int i = 0;
//	while (end - temp >= 1)
//	{
//		std::vector<int>::iterator biggest = std::max_element(temp, end);
//		temp = biggest+1;
//		int nMaxIndex = /*std::distance(std::begin(arr), biggest);*/ biggest - arr.begin();
//		for (; i < nMaxIndex; i++)
//		{
//			re[i] = arr[nMaxIndex];
//		}
//	}
//	*(re.end() - 1) = -1;
//	return re;
//}
//
//struct ListNode {
//	int val;
//	ListNode* next;
//	ListNode() : val(0), next(nullptr) {}
//	ListNode(int x) : val(x), next(nullptr) {}
//	ListNode(int x, ListNode* next) : val(x), next(next) {}
//};
//
//ListNode* removeElements(ListNode* head, int val) {
//	ListNode* re = head;
//	ListNode* before = head;
//	if (head == nullptr)
//		return head;
//	if (head->next != nullptr)
//	{
//		if (head->val != val)
//		{
//			before = head;
//			head = head->next;
//		}
//		else {
//			if (before == head)
//				re = before = head->next;
//			else
//				before->next = head->next;
//		}
//	}
//	else {
//		if (head->val != val)
//			;
//		if (before != re && head->val == val)
//			before->next = nullptr;
//		else {
//			ListNode* a = new ListNode;
//			return a;
//		}
//	}
//	return re;
//}
//
//vector<int> findDisappearedNumbers(vector<int>& nums) {
//	vector<int> re;
//	sort(nums.begin(), nums.end());
//	for (auto a : nums)
//		cout << a << endl;
//	for (int i = 0; i < nums.size(); i++)
//	{
//		if (nums[i] != i + 1)
//			re.emplace_back(i + 1);
//	}
//	return re;
//
//}
//
//bool repeatedSubstringPattern(string s) {
//	string temp;
//
//	for (int j = 0; j < s.size() / 2; j++)
//	{
//		temp += s[j];
//		int i = 1;
//		string flag = temp;
//		while (flag.size() < s.size())
//		{
//			string  temp(s,0, j + 1);
//			flag += temp;
//			if (flag[i] != s[i])
//				break;
//			else
//				i++;
//		}
//		if (s == flag)
//			return true;
//		else
//			continue;
//	}
//	return false;
//}
//
//string addBinary(string a, string b) {
//	int i_a = stoi(a);
//	int i_b = stoi(b);
//	i_a = i_b + i_a;
//	cout << i_a << endl;
//	while (i_a)
//	{
//		i_b = i_b * 10 + (i_a % 2);
//		i_a = i_a / 2;
//	}
//	cout << i_b << endl;
//	return to_string(i_b);
//}
//
//class PP
//{
//private:
//	int a = 0;
//protected:
//	int b = 1;
//public:
//	int c = 2;
//};
//class BB :public PP
//{
//	void t()
//	{
//	}
//};

int main()//c++17
{
	vector<int>a{ 1,2,3,4 };
	cout << sizeof(a) << endl;
	a.emplace_back(5);
	cout << sizeof(a) << endl;
	string b{ "1" };
	cout << b.length() << endl;
	cout << sizeof(b) << endl;
	b += "abcde";
	cout << b.length() << endl;
	cout << sizeof(b) << endl;
	//PP n1;
	//BB b1;
	//b1.
	//cout << n1.c << endl;
	//cout << addBinary("11", "10") << endl;
	//int i = 0x01;
	//cout << ~i << endl;
	/*int flag = 1110;
	string temp(to_string(flag));
	cout<<count(temp.begin(), temp.end(), '1');*/
	//string s("ababab");
	//int a = 132;
	//to_string(a);
	//cout << repeatedSubstringPattern(s) << endl;
	/*vector<int> nums{ 4,3,2,7,8,2,3,1 };
	vector<int> re = findDisappearedNumbers(nums);
	cout << "______________" << endl;
	for(auto a:re)
		cout << a << endl;*/
	//ListNode head7 = ListNode(6);
	//ListNode* head7_ = &head7;
	//ListNode head6 = ListNode(5);
	//ListNode* head6_ = &head6;
	//ListNode head5 = ListNode(4);
	//ListNode* head5_ = &head5;
	//ListNode head4 = ListNode(3);
	//ListNode* head4_ = &head4;
	//ListNode head3 = ListNode(6);
	//ListNode* head3_ = &head3;
	//ListNode head2 = ListNode(2);
	//ListNode* head2_ = &head2;
	//ListNode head1 = ListNode(1);
	//ListNode* head1_ = &head1;
	//ListNode* head = &head1;
	//head1_->next = head2_;
	//head2_->next = head3_;
	//head3_->next = head4_;
	//head4_->next = head5_;
	//head5_->next = head6_;
	//head6_->next = head7_;
	//if (head->next != nullptr)
	//{
	//	cout << head->val << endl;
	//	head = head->next;
	//}
	//cout << head->val << endl;
	//removeElements(head, 6);
	//if (head->next != nullptr)
	//{
	//	cout << head->val<<endl;
	//	head = head->next;
	//}
	//cout << head->val << endl;
	/*uint32_t n = 0x80;
	cout << hammingWeight(n) << endl;*/
	//vector<int> arr{ 17, 18, 5, 4, 6, 1 };
	//vector<int> re = replaceElements(arr);
	//for (auto a : re)
	//	cout << a << " ";
	//cout<<re_n(37);
	/*int arr[] = { 4,2124,52,41,5,6,7,1,4,13,3 };
	selectionSort(arr, sizeof(arr)/sizeof(int));*/
	//bubbleSor(arr, sizeof(arr));
	/*int arr1[20] = { 11,12,13,14,22,44 };
	int arr2[5] = { 1,3,5,7,9 };
	arr_add_sort(arr1, 6, arr2, 5);
	for (auto a : arr1)
		cout << a << endl;*/
	return 0;
}
//auto f()
//{
//	return std::make_tuple(1, 2.3, "456");
//}
//enum class FRUITS : unsigned int
//{
//	apple,
//	pear,
//	peach
//};
//bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
//	string s1;
//	string s2;
//	for (auto s : word1)
//		s1 += s;
//	for (auto s : word2)
//		s2 += s;
//	cout << "s1:" << s1 << endl; 
//	cout << "s2:" << s2 << endl;
//	cout << s1.compare(s2) << endl;
//	return s1.compare(s2);
//}
//
//template <typename A,double F>
/*vector<string> word1;
	vector<string> word2;
	word1.push_back("ab");
	word1.push_back("c");
	word2.push_back("a");
	word2.push_back("bc");
	cout<<arrayStringsAreEqual(word1, word2);*/
/*//在c++17以后可以编译通过,可以使用switch（if）使itr在switch（if）范围中存在
	//实现：把vector中3所在元素改为4
	std::vector<int> vec = { 1, 2, 3, 4 };
	switch (const std::vector<int>::iterator itr = std::find(vec.begin(), vec.end(), 3);
		itr != vec.end()) {
		*itr = 4;
	}

	for (auto element = vec.begin(); element != vec.end();++element)
		std::cout << *element << std::endl;

	auto [x, y, z] = f();*/
/*int b = 1;
	const int a = 10;
	int arr[a+1]{};*/
	/*array<int, 21>a{1};
	clock_t t = clock();
	for (auto b : a)
		cout << b << endl;
	cout << "time:" << clock() - t << endl;*/
//class a
//{
//public:
//	int a;
//	int b;
//	int c;
//};
//class b :public a
//{
//	int d;
//	int e;
//	int f;
//};
/*vector<int> twoSum(vector<int>& nums, int target)
{
	multiset<int> intmulset;
	vector<int> total;
	intmulset.insert(nums.begin(), nums.end());
	for (auto flag : nums)
	{
		int temp = target - flag;
		if (intmulset.find(temp) != intmulset.end())
		{
			total.push_back(flag);
			total.push_back(*intmulset.find(temp));
			break;
		}
		else
			continue;
	}
	return total;
}
*/
//int main()
//{
//    //float a = 12.257902012398877;
//    //double b = 12.257902012398877;
//    //const float PI = 3.1415926;         // 常量定义
//    //cout << setprecision(15) << a << endl;  // 只有6-7位有效数字，后面的就不精确
//    //cout << setprecision(15) << b << endl;  // 有15-16位有效数字，所以完全正确
//    //cout << setprecision(15) << PI << endl;
//    //string book("12qw");
//    //string book2 = "12qw";
//    //cout << book << endl;
//    //cout << book2 << endl;
//    cout << "/*";
//    cout << "*/";
//    //cout << /*"/*"*/;
//    cout << /*"*/"/*"/*"*/;
//
//    return 0;
//}
//class Text
//{
//
//public:
//	Text() = default;
//	/*Text() { cout << "first" << endl; }*/
//	//Text(int a) { cout << "value" << endl; }
//	Text(const Text&) { cout << "copy" << endl; }
//	//~Text() { cout << "del" << endl; }
//
//private:
//
//};
//Text& fun(Text& a,int)
//{
//	Text d(a);
//	return d;
//}
//class Staff
//{
//public:
//	Staff() = default;
//	Staff(const int Number) :number(Number), name("null"), post("null"), responsibility("null") {}
//	Staff(const int Number,string Name,string Post,string Responsibility) :
//		number(Number), name(Name), post(Post), responsibility(Responsibility) {}
//	void showInfo() { std::cout << "姓名：" << name << '\n' << "编号：" << number << '\n' << "岗位：" << post << '\n' << "职责：" << responsibility << std::endl; }
//private:
//	std::string name;
//	std::string post;
//	std::string responsibility;
//	int number;
//};
//int main()
//{
//	Staff a;
	/*b a;
	Text a;*/
	/*Text b(1,2);
	Text c(b);
	fun(a,1);*/
	/*
	// currVal is the number we're counting; we'll read new values into val
	int currVal = 0, val = 0;

	// read first number and ensure that we have data to process
	if (std::cin >> currVal) {
		int cnt = 1;  // store the count for the current value we're processing
		while (std::cin >> val) { // read the remaining numbers 
			if (val == currVal)   // if the values are the same
				++cnt;            // add 1 to cnt 
			else { // otherwise, print the count for the previous value
				std::cout << currVal << " occurs "
					<< cnt << " times" << std::endl;
				currVal = val;    // remember the new value
				cnt = 1;          // reset the counter
			}
		}  // while loop ends here
		// remember to print the count for the last value in the file
		std::cout << currVal << " occurs "
			<< cnt << " times" << std::endl;
	} // outermost if statement ends here
	*/
	/*string s = ("5/15/2022");
	string::size_type pos = 1;
	//cout << s[pos] << endl;
	//cout << s[pos+1] << endl;
	//cout << s.substr(pos+1,pos+2) << endl;
	//cout << s<< endl;
	if (s[pos] < 57 && s[pos] > 48)
	{
		cout << s[pos] << "  " << '57' << endl;
	}
	if (s[pos] =='/')
	{
		cout << "/" <<  endl;
	}*/
	/*string s = ("5/15/2022");
	string::size_type pos = 2;
	string mouf = s.erase(0, pos);
	cout << mouf << endl;
	cout << s << endl;
	mouf = mouf.erase(2);
	cout << mouf << endl;
	cout << s << endl;*/
	/*int i;
	for (i = 0; i < 12; i++)
	{
		if (i == 1)
			break;;
	}
	cout << i << endl;*/
	/*vector<int> vec;
	back_insert_iterator<vector<int>> it = back_inserter(vec);
	*it = 1;
	*it = 2;
	for (auto out : vec)
		cout << out << endl;*/
	/*//array<int, 5>intarr{ 1,2,3,4,5 };
	map<string, vector<string>>mapRule{ {"1",{"2","3"}},{{"4"},{"5","6"}} };
	//查看map内容
	for (auto out : mapRule)
		for (auto vec : out.second)
			cout << vec << " ";
	*/
	/*vector<int>nums{ 1,2,3,4,5 };
	vector<int> end = twoSum(nums, 6);
	for (auto put : end)
		cout << put << " ";*/
	//string content = "13";
	//int age = stoi(content);//string转为int
	//cout << age << endl;
	/*string b = "1234 5678";
	istringstream a(b);
	string c;
	while (a >> c)
		cout << c << endl;*/
	/*vector<int>addressBook{ 1,2,3,4,5 };
	shared_ptr<vector<int>> book_ptr = make_shared<vector<int>>(addressBook);
	book_ptr->erase(book_ptr->begin());
	for (auto a : *book_ptr)
		cout << a << " ";*/
//	return 0;
//}
//using namespace std;
////基类People
//class People {
//protected:
//	char* m_name;
//	int m_age;
//public:
//	People(char*, int);
//};
//People::People(char* name, int age) : m_name(name), m_age(age) {}
////派生类Student
//class Student : public People {
//private:
//	float m_score;
//public:
//	Student(char* name, int age, float score);
//	void display();
//};
////People(name, age)就是调用基类的构造函数
//Student::Student(char* name, int age, float score) : People(name, age), m_score(score) { }
//void Student::display() {
//	cout << m_name << "的年龄是" << m_age << "，成绩是" << m_score << "。" << endl;
//}
//int main() {
//	
//}
//class A
//{
//public:
//	
//	A() = default;
//	A(string a, int b) :a(a), b(b) {}
//private:
//	string a;
//	int b;
//};
//int main()
//{
//	/*ifstream infile("test.csv");
//	string line;	
//	while (infile >> line)
//	{
//		cout << line << endl;
//	}*/
//	A q("", 1);
//	A b;
//	q= b;
//	
//	return 0;
//}
/*
class XieYi
{
public:
	void addcoin()
	{
		cout << "add coin" << endl;
	}
	void addlevel()
	{
		cout << "add level" << endl;
	}
};

class MingLing
{
public:
	virtual void action() = 0; 
};

class doCoin:public MingLing
{
public:
	doCoin(XieYi* x)
	{
		XieYi* xieyi= x;
	}
	void action()
	{
		xieyi->addcoin();
	}
private:
	XieYi* xieyi;
};

class dolevel :public MingLing
{
public:
	dolevel(XieYi* x)
	{
		XieYi* xieyi = x;
	}
	void action()
	{
		xieyi->addlevel();
	}
private:
	XieYi* xieyi;
};

class Sevser
{
public:
	void add(MingLing* mingling)
	{
		paidui.push(mingling);
	}
	void dowork()
	{
		while (!paidui.empty())
		{
			MingLing* domingling = paidui.front();
			domingling->action();
			paidui.pop();
		}
	}
private:
	queue<MingLing*> paidui;
};
int main()
{
	tuple<int,int,int> a = make_tuple(10, 20, 30);
	tuple<string, vector<string>, pair<string, int>>b;
	XieYi* xieyi = new XieYi;
	doCoin* coin =new doCoin(xieyi);
	dolevel* level = new dolevel(xieyi);
	Sevser a;
	a.add(coin);
	a.add(level);
	a.dowork();
	return 0;
}
*/
/*void f1(const char* a){}
void f2(char const *a){}
void f3(char* const a){}
*/
/*
class DEMO
{
public:
	DEMO(int a) :age(a),name("demo"),id(0) {}
	virtual void display()const
	{
		cout << "name:" << name << "age:" << age <<"id"<<id<< endl;
	}
	std::string name;
	int age;
private:
	int id;

};
class DEMO2:public DEMO
{
public:
	DEMO2(int a) :DEMO(a),test(66) {}
	virtual void display()const
	{
		cout << "name:" << name << "age:" << age <<"test"<<test<< endl;
	}
private:
	int test;
};
void print(DEMO a)
{
	a.display();
}
void print2(const DEMO& a)
{
	a.display();
}
int distributeCandies(vector<int>&candyType)
{
	
	sort(candyType.begin(),candyType.end());
	int number = candyType.size() / 2;
	int canEat = 0;
	for (auto& n : candyType)
	{
		int haif = (n + 1) / 2;
		if (haif >= number)
		{
			if (number != 0)
			{
				canEat++;
				return canEat;
			}
			else
				return canEat;
		}
		else
		{
			canEat++;
			number -= haif;
		}
	}
	return 0;
}
int main(void)
{
	DEMO a(10);
	DEMO2 b(20);
	print(a);
	print(b);
	cout << endl;
	print2(a);
	print2(b);
	cout << endl;
	int c = 1 / 2;
	cout << c << endl;
	return 0;
}
*/
/*int main()
{
	shared_ptr<int> i = make_shared<int>(10);
	shared_ptr<int> i3 = make_shared<int>(11);
	shared_ptr<int> i2(i);
	i2 = i3;
	cout << i2.use_count() << endl;
	cout << i.use_count() << endl;
	vector<int> arr{55, 66, 1, 65, 84, 96, 53, 78, 24, 36,77};
	for (int i = 0; i < arr.size() - 1; i++) {
		for (int j = 0; j < arr.size() - i - 1; j++) {
			if (arr[j + 1] < arr[j]) {
				int a = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = a;
			}
		}
	}
	for (int b : arr)
		cout << b << " ";
	
}*/
//static int ID = 1;
//class STUDENT
//{
//private:
//	string* Info;
//	int Id;
//public:
//	//无参构造函数
//	STUDENT() :Info(new string("null")), Id(ID)
//	{
//		cout << "无参构造函数" << endl;
//	}
//	//有参构造函数
//	STUDENT(string info) :Info(new string(info)), Id(ID)
//	{
//		++ID;
//		cout << "有参构造函数" << endl;
//	}
//	//析构函数
//	~STUDENT() 
//	{
//		delete Info; 
//		cout << "析构函数" << endl;
//	}
//	//拷贝构造
//	STUDENT( const STUDENT& s)
//	{
//		Id = ID;
//		Info = new string(*s.Info);
//		++ID;
//		cout << "拷贝构造" << endl;
//	}
//	//拷贝赋值运算符
//	STUDENT& operator=(const STUDENT& s)
//	{
//		if (this->Info == s.Info)
//		{
//			cout << "拷贝赋值运算符" << endl;
//			return *this;
//		}
//		else
//		{
//			*Info = *s.Info;
//			++ID;
//			cout << "拷贝赋值运算符" << endl;
//			return *this;
//		}
//	}
//	//移动构造
//	STUDENT(STUDENT&& s) noexcept:Info(s.Info)
//	{
//		Id = ID;
//		++ID;
//		s.Info = nullptr; 
//		cout << "移动构造(++Id)" << endl;
//	}
//	//移动赋值运算符
//	STUDENT& operator=(STUDENT&& s) noexcept
//	{
//		if(this != &s)
//		{
//			delete Info;
//			Info = s.Info;
//			Id = s.Id;
//			s.Info = nullptr;
//			//书上没有return
//		}
//		cout << "移动赋值运算符" << endl;
//		return *this;
//	}
//	friend ostream& operator<<(ostream&, const STUDENT&);
//};
//ostream& operator<<(ostream& os, const STUDENT& s)
//{
//	try
//	{
//		if (s.Info == nullptr)
//			throw runtime_error("指针为空！");
//		else
//		{
//			cout << "信息：" << *s.Info << "  " << "ID:" << s.Id << endl;
//			return os;
//		}
//	}
//	catch (runtime_error err)
//	{
//		cout << err.what() << endl;
//		return os;
//	}
//	
//	
//}
//class A
//{
//private:
//	int i;
//public:
//	A():i(0){}
//	A(int a):i(a){}
//	A& operator+(const A& a)
//	{
//		 A B(++i);
//		 return B;
//	}
//	A& operator++()
//	{
//		++i;
//		return *this;
//	}
//	A operator++(int)
//	{
//		A C(i);
//		++i;
//		return C;
//	}
//	A& operator-(const A& a)
//	{
//		A C(--i);
//		return C;
//	}
//	A& operator--()
//	{
//		--i;
//		return *this;
//	}
//	A operator--(int)
//	{
//		A C(i);
//		--i;
//		return C;
//	}
//	friend void print(A&);
//};
//void print(A& a)
//	{
//		cout << "value:" << a.i << endl;
//	}
//int carculator(int a, int b, int c)
//{
//	if (c == 0)
//		return a + b;
//	if (c == 1)
//		return a - b;
//	if (c == 2)
//		return a * b;
//	else
//		return 0;
//}
//class A
//{
//	virtual void hello(int a) { cout << a << endl; }
//};
//class B :public A
//{
//	void hello(int a)override 
//	{
//
//	}
//};
//class Base
//{
//public:
//	void pub_mem()
//	{
//		cout << "pub_mem" << endl;
//	}
//protected:
//	int prot_mem;
//private:
//	char priv_mem;
//};
//struct Pub_Derv :public Base
//{
//	int f() { return prot_mem; }
//	//char g() { return priv_mem; }
//};
//struct Priv_Derv :public Base
//{
//	int f1()const { return prot_mem; }
//};
//template <typename T,typename F>
//class CHILD
//{
//	static T a;
//	void print() { cout << "print"<<a << endl; }
//};
//template <>
//class CHILD<int, int>
//{
//	static int a;
//	void print() { cout << "print" << endl; }
//};
//
//template <>
//int CHILD<int,int>::a = 5;
//
//template <typename T, typename F>
//T CHILD<T, F>::a = 44;
//class A 
//{
//public:
//	int a = 1;
//};
//class B:virtual public A
//{
//public:
//	int b = 2;
//};
//class C :virtual public A
//{
//public:
//	int c = 3;
//};
//class AA :public B, public C
//{
//public:
//	int aa = 4;
//};
//class Screen {
//public:
//	typedef std::string::size_type pos;
//
//	// Action is a type that can point to a member function of Screen
//	// that returns a reference to a Screen and takes no arguments
//	typedef Screen& (Screen::* Action)();
//
//	// constructor: build screen of given size containing all blanks
//	Screen(pos ht = 0, pos wd = 0) : contents(ht* wd, ' '), cursor(0),
//		height(ht), width(wd) { }
//	friend int main();
//	// data is a static member that returns a pointer to member
//	static const std::string Screen::* data()
//	{
//		return &Screen::contents;
//	}
//
//	char get_cursor() const { return contents[cursor]; }
//	char get() const { return contents[cursor]; }
//	inline char get(pos ht, pos wd) const;
//private:
//	std::string contents;
//	pos cursor;
//	pos height, width;
//
//public:
//	// cursor movement functions 
//	// beware: these functions don't check whether the operation is valid
//	Screen& home() { cursor = 0; return *this; }
//	Screen& forward() { ++cursor; return *this; }
//	Screen& back() { --cursor; return *this; }
//	Screen& up() { cursor += height; return *this; }
//	Screen& down() { cursor -= height; return *this; }
//
//	// specify which direction to move; enum see XREF(enums)
//	enum Directions { HOME, FORWARD, BACK, UP, DOWN };
//	Screen& move(Directions);
//private:
//	static Action Menu[];      // function table
//};
//
//char Screen::get(pos r, pos c) const // declared as inline in the class
//{
//	pos row = r * width;      // compute row location
//	return contents[row + c]; // return character at the given column
//}
//
//inline
//Screen& Screen::move(Directions cm)
//{
//	// run the element indexed by cm on this object
//	return (this->*Menu[cm])(); // Menu[cm] points to a member function
//}
//struct A //16
//{
//	int a;//4
//	char b;//1
//	double c;//8
//};
//struct B//16
//{
//	double c;//8
//	int a;//4
//	char b;//1	
//};
//class A
//{
//private:
//	int a;
//	char b;
//	double c;
//public:
//	int get_a() { return a; }
//	virtual void print() { cout << a << b << c << endl; }//8
//	virtual void print1() { cout << a << b << c << endl; }
//};
//class A 
//{
//private:
//	int a;
//	double b;
//public:
//	A() :a(0), b(0) {};
//	A(int aa) :a(aa), b(0) {};
//	A(int aa,double bb) :a(aa), b(bb) {};
//	friend ostream& operator<<(ostream& os, A a)
//	{
//		os << a.a << " " << a.b;
//		return os;
//	}
//};
/*
class Complex {
public:
	Complex() : m_real(0.0), m_imag(0.0) { }
	Complex(double real, double imag) : m_real(real), m_imag(imag) { }
public:
	friend ostream& operator<<(ostream& out, Complex& c);
	friend Complex operator+(const Complex& c1, const Complex& c2);
	//operator double() const { return m_real; }
private:
	double m_real;
	double m_imag;
};
ostream& operator<<(ostream& out, Complex& c) {
	out << c.m_real << " + " << c.m_imag << "i";;
	return out;
}
Complex operator+(const Complex& c1, const Complex& c2) {
	Complex c;
	c.m_real = c1.m_real + c2.m_real;
	c.m_imag = c1.m_imag + c2.m_imag;
	return c;
}
*/
//void print1()
//{
//	Sleep(5000);
//	cout << "子线程1" << endl;
//}
//void print2()
//{
//	Sleep(5000);
//	cout << "子线程2" << endl;
//}
//struct A
//{
//	int a;
//	char b;
//	double c;
//}a[];
//template<typename T,typename P>
//double chuFa(T a, P b)
//{
//	try
//	{
//		if (b == 0)
//			throw b;
//		else
//			return a / b;
//	}
//	catch (P& b)
//	{
//		cerr << "被除数不能为0" << endl;
//		return ;
//	}
//}
//class D
//{
//private:	
//	int age;
//	string name;
//};
	/*D a;
	const_cast<D&&>(a);
	vector<int>vi;
	//atomic<D*>p(new D);D
	vi.emplace_back(3);*/
	////thread a(print1);
	//thread b(print2);
	////a.join();
	//b.detach();
	//cout << "主线程" << endl;
	/*Complex c1(24.6, 100);
	double f = c1;
	cout << f << endl;

	f = 10.4 + c1 + 5;
	cout << f << endl;

	int n = Complex(43.2, 9.3);
	cout << n << endl;*/
	/*A a(1);
	cout << a << endl;
	a = 4;
	cout << a << endl;*/
	//cout << sizeof(A) << endl;
	//shared_ptr<int> sp = make_shared<int>(4);
	//unique_ptr<int> up = make_unique<int>(3);
	//cout << sizeof(sp) << endl;
	//cout << sizeof(up) << endl;
	//cout << *sp << endl;
	//cout << *up << endl;
	/*cout << sizeof(A) << endl;
	cout << sizeof(B) << endl;*/
	/*int* ip = new int[10]; 
	int* to = ip;
	for (size_t number = 0; number < 10; number++)
	{
		*to = number;
		cout << *to << endl;
		to++;
	}
	cout << "____________________________" << endl;
	int* change = new(ip)int(666);
	for (size_t number = 0; number < 10; number++)
	{
		cout << *ip << endl;
		ip++;
	}*/
	/*string a = "123";
	a.~basic_string();*/
	//// pdata can point to a string member of a const (or nonconst) Screen
	//const string Screen::* pdata;  // uninitialized
	//pdata = &Screen::contents;    // points to the contents member
	//const string Screen::* pdata2 = &Screen::contents;
	//// data() returns a pointer to the contents member of class Screen
	//const string Screen::* pdata3 = Screen::data();
	/*
	// Screen objects
	Screen myScreen, * pScreen = &myScreen;
	const Screen cScreen, * pcScreen = &cScreen;

	// .* dereferences pdata to fetch the contents member 
	// from the object myScreen
	string str = myScreen.*pdata;  // s is a string
	const string cstr = cScreen.*pdata;  // c is a const string

	// ->* dereferences pdata to fetch contents 
	// from the object to which pScreen points
	str = pScreen->*pdata;

	// pmf is a pointer that can point to a Screen member function 
	// that takes no arguments, returns a char, and is const
	// that returns a char and takes no arguments
	char (Screen:: * pmf)() const = &Screen::get_cursor;
	char (Screen:: * pmf2)() const = &Screen::get; // same type as pmf

	pmf = &Screen::get; // which version of get deduced from type of pmf
	pmf2 = &Screen::get_cursor;

	Screen s;
	char c1 = s.get_cursor(); // gets character at the cursor directly
	char c2 = (s.*pmf2)();    // calls get_cursor indirectly through pmf2

	// call the function to which pmf points 
	// on the object to which pScreen points
	c1 = (pScreen->*pmf)();

	// pmf3 points to the two-parameter version of get
	char (Screen:: * pmf3)(Screen::pos, Screen::pos) const = &Screen::get;
	c1 = myScreen.get(0, 0);     // call two-parameter version of get 
	c2 = (myScreen.*pmf3)(0, 0); // equivalent call to get

	// Op is a type that can point to a member function of Screen 
	// that returns a char and takes two pos arguments
	typedef char (Screen::* Op)(Screen::pos, Screen::pos) const;

	Op get = &Screen::get; // get points to the get member of Screen

	myScreen.move(Screen::HOME);  // invokes myScreen.home
	myScreen.move(Screen::DOWN);  // invokes myScreen.down
	*/
	/*A a1;
	cout << a1.a << endl;
	B b1;
	cout << b1.a << endl;
	C c1;
	cout << c1.a << endl;
	AA aa1;
	cout << aa1.a << endl;*/
	//Priv_Derv d2;
	//d2.pub_mem();  
	/*char* p;
	cout << sizeof(p) << endl;
	unsigned int a = ~0;
	if (a > 65536)
	{
		cout << "32" << endl;
	}
	else
		cout << "64" << endl;*/
	/*int* sarr{ new int[20] };
	cout<<sizeof(sarr);*/
	/*int* a(new int(4));
	cout << *a << endl;
	shared_ptr<int> temp(a);
	cout << *temp << endl;*/
	/*shared_ptr<int> temp = make_shared<int>(a);
	cout << *temp << endl;*/
	/*int a = 1;
	int b = 2;
	auto bi = bind(carculator, _1, _2, 2);
	cout << carculator(a, bi(b, 3), 1) << endl;*/
	/*vector<string > words{ "a" ,"efusif","fgdfg","g","dfius","aer","b","cedfsf" };
	for (auto put : words)
		cout << put << "  ";
	cout <<""<< endl; volatile
	vector<string>::iterator a = partition(words.begin(), words.end(), [](string s)->bool
	{
		if (s.size() >= 5)
		{
			return true;
		}
		else
			return false;
	});
	for (auto put : words)
		cout << put << "  ";
	cout << (*a)  << endl;*/
	/*A a(1);
	A d = a++;
	print(a);
	print(d);
	int b = 1;
	int c = b++;
	cout << b << c << endl;*/
	/*STUDENT a("小王");
	STUDENT b("小红");
	std::swap(a, b);
	cout << "a->" << a << "b->" << b << endl;
	cout << "______________" << endl;

	STUDENT c("小绿");
	STUDENT d = std::move(c);
	cout << "c->" << c << "d->" << d << endl;
	cout << "______________" << endl;

	STUDENT e("小黄");
	e = e;
	cout << "e->" << e << endl;
	cout << "______________" << endl;

	STUDENT f("小紫");
	f = e;
	cout << "f->" << f << "e->" << e << endl;
	cout << "______________" << endl;*/
	/*string s{ "122124343r6we87uyfrgdjfuyvcetg3r8423rbitq4r" };
	string s1 = std::move(s);
	cout << s1 << endl;
	cout << s << endl;
	cout << "end" << endl;*/
	//set<int>a;
	//a.insert(3);
	//a.insert(1);
	//a.insert(5);
	//for (auto& b : a)
	//	cout << b << endl;
	/*unsigned u = 10;
	int a = -84;
	cout << u + a << endl;*/
	/*cout << "hllo world!"
		"my world" << endl;*/
	/*int a[]{ 1,2,3,4,5 };
	int* begn = begin(a);
	int* ed = end(a)-1;
	cout << *begn << *ed << endl;*/
	/*vector<int>a{ 1,2,3,4 };
	int arr[4];
	int* pa = &arr[4];
	for (auto put : a)
	{
		*pa = put;
		pa++;
	}*/
	/*int a[]{ 1,2,3,4,5 };
	vector<int>b(begin(a),end(a));
	ofstream ifs ("2.txt");
	string s;
	while (cin >> s)
	{
		ifs << s<<endl;
	}
	ifs.close();
	cout << "结束" << endl;
	ifstream ifi("2.txt");
	string out;
	ifi >> out;
	cout << out << endl;
	cout << "结束" << endl;*/
	/*ifstream read("3.txt");
	string re;
	read >> re;
	cout << re;*/
	/*ofstream write("1.txt", ofstream::app);
	string a = "1234";
	write << a;*/
	/*string s{ "122124343r6we87uyfrgdjfuyvcetg3r8423rbitq4r" };
	istringstream ss(s);
	string s1;
	ss >> s1;
	cout << s1 << endl;
	std::move(s1);*/
	/*string s1{ "1322314" };
	string s2{ "fgset34t3" };
	cout << s1 << "  " << s2 << endl;
	std::swap(s1, s2);
	cout << s1 << "  " << s2 << endl;*/