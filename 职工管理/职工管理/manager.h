#pragma once
#include "staff.h"

class Manager final :public Staff//��ֹ��Manager���м̳�
{
public:
	Manager() :number(0) {}
	explicit Manager(const int Number) :number(Number) {}
	Manager(std::istream& is) :Staff(is) {  }
	void showObligation() { std::cout << "����ϰ彻�������񣬲��·���Ա��" << std::endl; }
private:
	int number;
};