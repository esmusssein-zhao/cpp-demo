#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <memory>
#include<sstream>
#ifndef _HEAD_H_
#define _HEAD_H_
class Person
{
	friend void print(const Person&);
	friend void print(const std::shared_ptr<Person>);
	friend std::ostream& operator<<(std::ostream& os, const std::shared_ptr<std::vector<Person>>& p);
public:
	Person() = default;
	explicit Person(const std::string& Name) :
		name(Name), tel(), sex("null"), address("null"), age(0) {}
	Person(const std::string Name, std::vector<std::string>Tel,
		std::string Sex, std::string Address, int Age) :
		name(Name), tel(Tel), sex(Sex), address(Address), age(Age) {}
	/*Person(const Person&p) { this->address = p.address, this->age = p.age,
		this->name = p.name, this->sex = p.sex, this->tel = p.tel; }*/
	inline void changeTel(std::vector<std::string>newsTel) { tel = newsTel; }
	inline void changeSex(std::string newsSex) { sex = newsSex; }
	inline void changeAdderss(std::string newsAdderss) { address = newsAdderss; }
	inline void changeAge(int newsAge) { age = newsAge; }
	std::string getName()const { return name; }
	std::vector<std::string> getTel()const { return tel; }
	std::string getSex()const { return sex; }
	std::string getAddress()const { return address; }
	int getAge()const { return age; }
private:
	int age;
	std::string name;//����const�޷�����ɾ��
	std::vector<std::string>tel;
	std::string sex;
	std::string address;
};
//����"<<"(std::shared_ptr<std::vector<Person>>)
std::ostream& operator<<(std::ostream & os, const std::shared_ptr<std::vector<Person>>&p)
{
	auto begin = (*p).begin();
	auto end = (*p).end();
	for (begin; begin < end; begin++)
	{
		os << "name:" << begin->name << '\n' << "tel:";
		auto v_begin = begin->tel.begin();
		auto v_end = begin->tel.end();
		for (v_begin; v_begin < v_end; v_begin++)
			os << *v_begin << "  ";
		os << '\n' << "sex:" << begin->sex << '\n' << "address:" << begin->address << '\n' << "age:" << begin->age << std::endl;
	}
	return os;
}
//����"<<"(std::vector<std::string>)
std::ostream& operator<<(std::ostream& os, const std::vector<std::string>& s)
{
	for (auto& put : s)
		os << put<<" ";
	return os;
}
//����
auto find(std::shared_ptr<std::vector<Person>> book_ptr, std::string name)
{
	auto begin = book_ptr->begin();
	auto end = book_ptr->end();
	for (begin; begin < end; begin++)
	{
		if (begin->getName() == name)
			return begin;
	}
	return end;
}
//�޸ĳ�Ա
void changeMember(std::shared_ptr<std::vector<Person>> book_ptr)
{
	std::string name;
	auto end = book_ptr->end();
	bool flag = false;
	do
	{
		std::cout << "Enter the name you want to change(using name search)->";
		while (std::cin >> name, std::cin.get() != '\n') {}
		auto result = find(book_ptr, name);
		if (result != end)
		{
			std::string matter;
			std::cout << "Please enter the revised phone number, gender, address, age " << std::endl;
			//�޸ĵ绰
			std::cout << "phone number:";
			std::vector<std::string>newTel;
			do
			{
				while (std::cin >> matter, std::cin.get() != '\n')
					newTel.push_back(matter);
				std::cout << "another tel?(Y/N) ->";
				while (std::cin >> matter, std::cin.get() != '\n') {}
			} while (matter == "Y" || matter == "y" || matter == "YES" || matter == "yes");
			(*result).changeTel(newTel);
			//�޸��Ա�
			std::cout << "sex:";
			while (std::cin >> matter, std::cin.get() != '\n') {}
			(*result).changeSex(matter);
			//�޸ĵ�ַ
			std::cout << "address:";
			while (std::cin >> matter, std::cin.get() != '\n') {}
			(*result).changeAdderss(matter);
			//�޸�����
			std::cout << "age:";
			while (std::cin >> matter, std::cin.get() != '\n') {}
			(*result).changeAge(stoi(matter));
		}
		else
		{
			std::cout << "There's no information on this guy! try again?(y/n)->";
			while (std::cin >> name, std::cin.get() != '\n') {}
			if (name == "Y" || name == "y" || name == "YES" || name == "yes")
				flag = true;
			else
				break;
		}
	} while (flag);
}
//ɾ����Ա
void delMember(std::shared_ptr<std::vector<Person>> book_ptr)
{
	std::string name;
	auto end = book_ptr->end();
	bool flag = false;
	do
	{
		std::cout << "Enter the name you want to delete->";
		while (std::cin >> name, std::cin.get() != '\n') {}
		auto result = find(book_ptr, name);
		if (result != end)
		{
			book_ptr->erase(result);
			std::cout << "deleted successfully!" << std::endl;
			break;
		}
		else
		{
			std::cout << "There's no information on this guy! try again?(y/n)->";
			while (std::cin >> name, std::cin.get() != '\n') {}
			if (name == "Y" || name == "y" || name == "YES" || name == "yes")
				flag = true;
			else
				break;
		}
	} while (flag);
}
//����
void save(std::shared_ptr<std::vector<Person>> book_ptr)
{
	auto begin = (*book_ptr).begin();
	auto end = (*book_ptr).end();
	std::ofstream save("addressBook.txt");
	for (begin; begin < end; begin++)
	{
		save << begin->getName() << "\n" <<
			begin->getTel() << "\n" << begin->getSex() << "\n" <<
			begin->getAddress() << "\n" << begin->getAge() << std::endl;
	}
}//�������
//��ʾ����(shared_ptr)
void show(const std::shared_ptr<std::vector<Person>>book_ptr)
{
	for (auto& p : *book_ptr)
		print(p);
}
//���ļ�����
std::vector<Person> readFile(std::istream& ifs)//istream����������
{
	std::vector<Person>addressBook;
	std::vector<std::string>nameT;
	std::vector<std::vector<std::string>>telT;
	std::vector<std::string>sexT;
	std::vector<std::string>addressT;
	std::vector<int>ageT;
	std::string content;
	int line = 1;
	//ÿ�в�ͬ���ݷ��ֱ���벻ͬ��vector
	while (getline(ifs, content))
	{
		int location = line % 5;
		if (location == 1)
		{
			nameT.push_back(content);
			++line;
		}
		if (location == 2)
		{
			std::istringstream ifc(content);
			std::string tels;
			std::vector<std::string>tel;//ÿ�ζ����µ�vector
			while (ifc >> tels)
			{
				tel.push_back(tels);
			}
			telT.push_back(tel);
			++line;
		}
		if (location == 3)
		{
			sexT.push_back(content);
			++line;
		}
		if (location == 4)
		{
			addressT.push_back(content);
			++line;
		}
		if (location == 0)
		{
			int age = stoi(content);//stringתΪint 
			ageT.push_back(age);
			++line;
		}
	}
	size_t numbers = telT.size();
	for (int i = 0; i < numbers; i++)
		addressBook.push_back(Person(nameT[i], telT[i], sexT[i], addressT[i], ageT[i]));
	return addressBook;
}
//��ʾ����(vector)
void show(const std::vector<Person>addressBook)
{
	for (auto& p : addressBook)
		print(p);
}
//�������(shared_ptr)
void print(const std::shared_ptr<Person> p)
{
	std::cout << "name: " << p->name << std::endl;
	std::cout << "tel: ";
	for (auto& tel : p->tel)
		std::cout << tel << '\t';
	std::cout << "sex: " << p->sex << std::endl;
	std::cout << "address: " << p->address << std::endl;
	std::cout << "age: " << p->age << std::endl;
}
//�������(Person)
void print(const Person& p)
{
	std::cout << "name: " << p.name << std::endl;
	std::cout << "tel: ";
	for (auto& tel : p.tel)
		std::cout << tel << "   ";
	std::cout << std::endl;
	std::cout << "sex: " << p.sex << std::endl;
	std::cout << "address: " << p.address << std::endl;
	std::cout <<"age: " << p.age << std::endl;
}
//����³�Ա
Person addNewMm()
{
	std::string matter;
	std::cout << "new:" << std::endl;
	std::cout << '\t' << "name:";
	//�������
	while (std::cin >> matter, std::cin.get() != '\n') {}
	Person news(matter);
	//����ʹ��ָ��
	/*shared_ptr<Person> newsptr = make_shared<Person>(news);
	print(newsptr);*/
	//��ӵ绰
	std::vector<std::string>newTel;
	std::cout << '\t' << "tel:";
	do
	{
		while (std::cin >> matter, std::cin.get() != '\n'){}
			newTel.push_back(matter);
		std::cout << "another tel?(Y/N) ->";
		while (std::cin >> matter, std::cin.get() != '\n') {}
	} while (matter == "Y" || matter == "y" || matter == "YES" || matter == "yes");
	news.changeTel(newTel);
	//����Ա�
	std::cout << '\t' << "sex:";
	while (std::cin >> matter, std::cin.get() != '\n'){}
	news.changeSex(matter);
	//��ӵ�ַ
	std::cout << '\t' << "address:";
	while (std::cin >> matter, std::cin.get() != '\n'){}
	news.changeAdderss(matter);
	//�������
	std::cout << '\t' << "age:";
	while (std::cin >> matter, std::cin.get() != '\n'){}
	news.changeAge(stoi(matter));
	return news;
}
//�˵�
int menu()
{
	std::cout << '\t' << '\t' << '\t' << '\t' << '\t' << '\t' << "address book" << std::endl;
	std::cout << '\t' << '\t' << '\t' << "________________________________________________________" << std::endl;
	std::cout << '\t' << '\t' << '\t' << '\t' << '\t' << "1.Add a Contact" << std::endl;
	std::cout << '\t' << '\t' << '\t' << '\t' << '\t' << "2.Show Contacts" << std::endl;
	std::cout << '\t' << '\t' << '\t' << '\t' << '\t' << "3.Deleting Contacts" << std::endl;
	std::cout << '\t' << '\t' << '\t' << '\t' << '\t' << "4.Searching for Contacts" << std::endl;
	std::cout << '\t' << '\t' << '\t' << '\t' << '\t' << "5.Modifying Contacts" << std::endl;
	std::cout << '\t' << '\t' << '\t' << '\t' << '\t' << "6.Clearing Contacts" << std::endl;
	std::cout << '\t' << '\t' << '\t' << '\t' << '\t' << "7.Exit and save" << std::endl;
	std::cout << '\t' << '\t' << '\t' << "________________________________________________________" << std::endl;
	std::cout << '\t' << '\t' << '\t' << "  " << "You must use exit and save the closing program������" << std::endl;
	std::cout << "Please select the action you want to perform->";
	int choice;
in:
	while (std::cin >> choice, std::cin.get() != '\n')//�ж������Ƿ�Ϊint����
	{
		if (std::cin.bad())
			throw std::runtime_error("IO stream corrupted!");
		if (std::cin.fail())
		{
			std::cerr << "No numbers are entered!try again!" << std::endl;
			std::cin.clear();
			std::cin.ignore(200, '\n');
			continue;
		}
	}
	if (choice < 0 || choice > 8)
	{
		std::cout << "The number entered is not in the range, please re-enter!" << std::endl;
		goto in;
	}
	return choice;
}
#endif