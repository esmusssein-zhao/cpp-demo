#pragma once
#include <string>
#include <iostream>
#include <istream>
class Staff
{
public:
	Staff() :number(0), name(), post(), responsibility() {}
	explicit Staff(const int Number):number(Number),name(),post(),responsibility(){}
	Staff(std::istream& is);//ʹ���������Գ�������г�ʼ��������������ø���
	void showInfo() const { std::cout << "������" << name << '\n' << "��ţ�" << number << '\n' << "��λ��" << post << '\n' << "ְ��" << responsibility << std::endl; }//��ֹ�޸����ݵ���ʾ��Ϣ
	virtual void showObligation() const{};//��ֹ�޸����ݵ���ʾְ��
	virtual ~Staff(){}//���������������������Ǳ���
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
	std::cout << "������ְ����ţ�";
	while (is >> isInit, std::cin.get() != '\n') {}
	number = stoi(isInit);
	std::cout << "������ְ��������";
	while (is >> isInit, std::cin.get() != '\n') {}
	name = isInit;
	std::cout << "������ְ����λ��";
	while (is >> isInit, std::cin.get() != '\n') {}
	post = isInit;
	std::cout << "������ְ��ְ��";
	while (is >> isInit, std::cin.get() != '\n') {}
	responsibility = isInit;
	std::cout << "���" << std::endl;
}