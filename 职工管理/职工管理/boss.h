#pragma once
#include "staff.h"

class Boss final :public Staff//��ֹ��Boss���м̳�
{
public:
	Boss() :number(0) {}
	explicit Boss(const int Number) :number(Number) {}
	Boss(std::istream& is) :Staff(is) {}
	void showObligation() { std::cout << "����˾��������" << std::endl; }
private:
	int number;
};