#pragma once
#include "staff.h"

class LaborialStaff final : public Staff//��ֹ��LaborialStaff���м̳�
{
public:
	LaborialStaff() :number(0) {}
	explicit LaborialStaff(const int Number) :number(Number) {}
	LaborialStaff(std::istream& is) :Staff(is) {  }//���ø���Ĺ��캯��
	virtual ~LaborialStaff() {}
	void showObligation() const override { std::cout << "��ɾ�����������" << std::endl; }
private:
	int number;
};