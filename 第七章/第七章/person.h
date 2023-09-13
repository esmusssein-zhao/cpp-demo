#pragma once
#ifndef _PERSON_H_
#include <iostream>
#include<string>

class Person
{
	friend std::istream& read(std::istream& is, Person news);
	friend std::ostream& print(std::ostream& os, Person output);
public:
	Person() = default;//Ĭ��
	Person(std::string n, std::string d) :name(n), address(d) {}
	//Person(std::string name, std::string address){}//������ͬ��
	Person(std::string n) :name(n) {}//��Person(std::string n) :name(n), address(n) {}��ͬ
	//Person(std::string name){}//������ͬ��
	Person(std::istream& is) { is >> this->name >> this->address; }
	//Person(std::istream& is);
private:	
	std::string getName()const { return name; };
	std::string getAdress()const { return address; };
	std::string name;
	std::string address;
};

std::istream &read(std::istream &is, Person news)
{
	std::cout << "new information:";
	is >> news.name >> news.address;
	return is;
}

std::ostream& print(std::ostream& os, Person output)
{
	os << "name:" << output.name << "  " << "address" << output.address;
	return os;
}

//Person::Person(std::istream& is)
//{
//	read(is, *this);
//}


#endif // !_HEAD_H_
