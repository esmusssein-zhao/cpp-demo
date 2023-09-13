#pragma once
#include <string>
#include <iostream>
#include <istream>
class Staff
{
public:
	Staff() :number(0), name(), post(), responsibility() {}
	explicit Staff(const int Number):number(Number),name(),post(),responsibility(){}
	Staff(std::istream& is);//使用输入流对抽象类进行初始化，用于子类调用父类
	void showInfo() const { std::cout << "姓名：" << name << '\n' << "编号：" << number << '\n' << "岗位：" << post << '\n' << "职责：" << responsibility << std::endl; }//禁止修改内容的显示信息
	virtual void showObligation() const{};//禁止修改内容的显示职责
	virtual ~Staff(){}//虚析构，不做操作，但是保留
	std::string name;
protected:
	std::string post;
	std::string responsibility;
private:
	int number;
};
Staff::Staff(std::istream& is)
{
	std::string isInit;
	std::cout << "请输入职工序号：";
	while (is >> isInit, std::cin.get() != '\n') {}
	number = stoi(isInit);
	std::cout << "请输入职工姓名：";
	while (is >> isInit, std::cin.get() != '\n') {}
	name = isInit;
	std::cout << "请输入职工岗位：";
	while (is >> isInit, std::cin.get() != '\n') {}
	post = isInit;
	std::cout << "请输入职工职责：";
	while (is >> isInit, std::cin.get() != '\n') {}
	responsibility = isInit;
	std::cout << "完成" << std::endl;
}