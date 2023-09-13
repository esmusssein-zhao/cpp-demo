#pragma once
#ifndef _HEAD_H_
#include <iostream>
#include<string>
#include <vector>

class Salea_data
{
	friend Salea_data add(const Salea_data& rls, const Salea_data& lls);
	friend std::ostream& print(std::ostream& os, Salea_data& iteam);
	friend std::istream& read(std::istream& is, Salea_data& iteam);
public:
	Salea_data() = default;
	Salea_data(const std::string &s) :bookNo(s){}//a����const���Ρ����ã����򱨴�
	//Salea_data(const std::string &s) :bookNo(s), units_sold(0), revenue(0) {}//b
	//Salea_data(const std::string &s, unsigned us, double re) :
	// bookNo(s), units_sold(us), revenue(re) {}//c
	//Salea_data(std::istream& ns);//ʹ��read�������г�ʼ��
	Salea_data(std::istream& ns) { ns >> this->bookNo>>this->revenue>>this->units_sold; }
	Salea_data(const std::string &s, unsigned us, double re)//d  bcd��ͬ
	{
		bookNo = s;
		units_sold = us;
		revenue = re;
	}
	std::string isbn()const;//�������
	Salea_data& combine(const Salea_data&);//ͳ��
	double avg_price()const
	{
		if (units_sold)
		{
			return revenue / units_sold;
		}
		else
		{
			return 0;
		}
	}
private:
	std::string bookNo;//���
	unsigned units_sold = 0;//������
	double revenue = 0;//����
};

std::istream &read(std::istream &is, Salea_data &iteam)
{
	double price = 0;//����
	is >> iteam.bookNo >> price >> iteam.units_sold;
	iteam.revenue = price * iteam.units_sold;
	return is;
}

std::ostream& print(std::ostream& os, Salea_data& iteam)
{
	os << iteam.isbn() << " " << " " << iteam.units_sold << " " << iteam.revenue;
	return os;
}

std::string Salea_data::isbn()const
{
	return bookNo;
}
Salea_data& Salea_data::combine(const Salea_data& rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}
Salea_data add(const Salea_data &rls, const Salea_data &lls)
{
	Salea_data als = rls;
	als.combine(lls);
	return als;
 }
//Salea_data::Salea_data(std::istream& ns)
//{
//	read(ns, *this);
//}
class Screen
{
public:
	using pos = std::string::size_type;
	Screen() = default;
	Screen(pos ht, pos wh) :height(ht), width(wh), contents(ht* wh, ' ') {}
	Screen(pos ht, pos wh, char c) :height(ht), width(wh), contents(ht* wh, c) {}
	char get()const { return contents[cursor]; }
	char get(pos ht, pos wh)const;
	Screen& move(pos ht, pos c);
	void some_number()const;
private:
	pos cursor = 0;//���
	pos height = 0, width = 0;
	std::string contents;//����
	mutable size_t access_ctr;
};
inline Screen& Screen::move(pos ht, pos c)
{
	pos row = ht * width;
	cursor = row + c;
	return *this;
}
char Screen::get(pos ht, pos wh)const
{
	pos row = ht * width;
	return contents[row + wh];

}
void Screen::some_number()const
{
	++access_ctr;//��¼���ô���
	//wtd
}
class Windows_mgr
{
private:
	std::vector<Screen> screens{ Screen(24,80,' ')};
};
#endif // !_HEAD_H_
