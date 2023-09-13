#pragma once
#include "staff.h"

class Manager final :public Staff//禁止对Manager进行继承
{
public:
	Manager() :number(0) {}
	explicit Manager(const int Number) :number(Number) {}
	Manager(std::istream& is) :Staff(is) {  }
	void showObligation() { std::cout << "完成老板交给的任务，并下发给员工" << std::endl; }
private:
	int number;
};