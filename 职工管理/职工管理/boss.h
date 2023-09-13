#pragma once
#include "staff.h"

class Boss final :public Staff//禁止对Boss进行继承
{
public:
	Boss() :number(0) {}
	explicit Boss(const int Number) :number(Number) {}
	Boss(std::istream& is) :Staff(is) {}
	void showObligation() { std::cout << "管理公司所有事务" << std::endl; }
private:
	int number;
};