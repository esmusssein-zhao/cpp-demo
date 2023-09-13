#include<iostream>
#include <string>
#include <ostream>
using namespace std;
class Employee
{
	friend ostream& operator<<(ostream&, const Employee&);
protected:
	static int number;//static成员，类内声明
private:
	std::string name;
	const int id;
public:
	string flag = "null";
	Employee() :name("null"),id(number) { ++number; }
	Employee(std::string name) :name(name), id(number) { ++number; }
	Employee(const Employee& news):name(news.name), id(number) { this->number = ++news.number; }//拷贝初始化
	Employee& operator=(const Employee& news) { name = news.name; return *this; }//拷贝赋值运算符
	int getId() const{ return id; } 
	virtual void workContent() { cout << "Employee: " << "work for boss" << endl; }//虚函数
	//virtual void workContent() = 0;//纯虚函数
	virtual string nativePlace(){return "China";}//虚函数
};
//void Employee::workContent()
//{
//	cout << "可以在类外对纯虚函数进行定义" << endl;
//}
int Employee::number = 1;//需要类外定义
class ContractWorker :public Employee//继承
{
private:
	std::string name;
	const int id;
public:
	ContractWorker() :Employee(), id(number) {  }//使用父类的构造函数进行初始化
	ContractWorker(std::string name) :Employee(name), id(number) {  }
	ContractWorker(const ContractWorker& news) :Employee(news), id(number) { }
	virtual void workContent() override final { cout << "ContractWorker: " << "work for boss" << endl; }//显示说明覆写workContent，并禁止后续其他类覆盖
	virtual string nativePlace() { return "USA"; }
};
class DayLaborer final :public ContractWorker//最终的类，不允许继承
{
private:
	std::string name;
	const int id;
public:
	DayLaborer() :ContractWorker(), id(number) {  }
	DayLaborer(std::string name) :ContractWorker(name), id(number) {  }
	DayLaborer(const DayLaborer& news) :ContractWorker(news), id(number) { }
};
class Boss :private Employee//私有继承
{
private:
	std::string name;
	const int id;
public:
	using Employee::flag;//保持对象原有访问级别,但是还要注意所放位置
	Boss(string name) :name(name), id(number) { number++; }
	void changeFlagAndGet(string s) { cout << this->flag << endl;; flag = s; }
	void changeFlag() { cout << flag << endl; }
};
ostream& operator<<(ostream& os, const Employee& e1)
{
	os << "name:" << e1.name << '\n' << "id:" << e1.id << endl;
	return os;
}
int main()
{
	Boss aa("yyz");
	aa.changeFlagAndGet("boss");
	cout << aa.flag << endl;
	Employee a0("hello");//有虚函数是可以继承的，但有纯虚函数不可以
	cout << a0.getId() << endl;
	ContractWorker a1("hello1");
	cout << a1.nativePlace() << endl;
	cout << a1.getId() << endl;
	ContractWorker a2("hello2");
	cout << a2.Employee::nativePlace() << endl;//回避虚函数
	cout << a2.getId() << endl;
	DayLaborer a3("hello3");
	cout << a3.getId() << endl;
	a3.workContent();
	return 0;
}