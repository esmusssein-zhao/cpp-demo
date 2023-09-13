#include<iostream>
#include <string>
#include <ostream>
using namespace std;
class Employee
{
	friend ostream& operator<<(ostream&, const Employee&);
protected:
	static int number;//static��Ա����������
private:
	std::string name;
	const int id;
public:
	string flag = "null";
	Employee() :name("null"),id(number) { ++number; }
	Employee(std::string name) :name(name), id(number) { ++number; }
	Employee(const Employee& news):name(news.name), id(number) { this->number = ++news.number; }//������ʼ��
	Employee& operator=(const Employee& news) { name = news.name; return *this; }//������ֵ�����
	int getId() const{ return id; } 
	virtual void workContent() { cout << "Employee: " << "work for boss" << endl; }//�麯��
	//virtual void workContent() = 0;//���麯��
	virtual string nativePlace(){return "China";}//�麯��
};
//void Employee::workContent()
//{
//	cout << "����������Դ��麯�����ж���" << endl;
//}
int Employee::number = 1;//��Ҫ���ⶨ��
class ContractWorker :public Employee//�̳�
{
private:
	std::string name;
	const int id;
public:
	ContractWorker() :Employee(), id(number) {  }//ʹ�ø���Ĺ��캯�����г�ʼ��
	ContractWorker(std::string name) :Employee(name), id(number) {  }
	ContractWorker(const ContractWorker& news) :Employee(news), id(number) { }
	virtual void workContent() override final { cout << "ContractWorker: " << "work for boss" << endl; }//��ʾ˵����дworkContent������ֹ���������า��
	virtual string nativePlace() { return "USA"; }
};
class DayLaborer final :public ContractWorker//���յ��࣬������̳�
{
private:
	std::string name;
	const int id;
public:
	DayLaborer() :ContractWorker(), id(number) {  }
	DayLaborer(std::string name) :ContractWorker(name), id(number) {  }
	DayLaborer(const DayLaborer& news) :ContractWorker(news), id(number) { }
};
class Boss :private Employee//˽�м̳�
{
private:
	std::string name;
	const int id;
public:
	using Employee::flag;//���ֶ���ԭ�з��ʼ���,���ǻ�Ҫע������λ��
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
	Employee a0("hello");//���麯���ǿ��Լ̳еģ����д��麯��������
	cout << a0.getId() << endl;
	ContractWorker a1("hello1");
	cout << a1.nativePlace() << endl;
	cout << a1.getId() << endl;
	ContractWorker a2("hello2");
	cout << a2.Employee::nativePlace() << endl;//�ر��麯��
	cout << a2.getId() << endl;
	DayLaborer a3("hello3");
	cout << a3.getId() << endl;
	a3.workContent();
	return 0;
}