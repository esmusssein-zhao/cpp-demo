#pragma once
#include "staff.h"

class LaborialStaff final : public Staff//禁止对LaborialStaff进行继承
{
public:
	LaborialStaff() :number(0) {}
	explicit LaborialStaff(const int Number) :number(Number) {}
	LaborialStaff(std::istream& is) :Staff(is) {  }//调用父类的构造函数
	virtual ~LaborialStaff() {}
	void showObligation() const override { std::cout << "完成经理交给的任务" << std::endl; }
private:
	int number;
};