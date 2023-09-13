#include "administrator.h"

using namespace std;
void Administrator::menu()
{
	std::cout << "0.退出" << std::endl;
	std::cout << "1.添加职工信息" << std::endl;
	std::cout << "2.显示" << std::endl;
	std::cout << "3.删除" << std::endl;
	std::cout << "4.修改" << std::endl;
	std::cout << "5.查找" << std::endl;
}
void Administrator::Exit()
{
	system("pause");
	exit(0);
}
//查找
pair<const int, vector<string, allocator<string>>>& Administrator::Find(shared_ptr<map<int, vector<string>>>pFileDetails)
{
	int id;
	bool flag;
	do
	{
		std::cout << "请输入要查找或修改的员工工号：";
		cin >> id;
		auto temp = pFileDetails->find(id);
		auto end = pFileDetails->end();
		if (temp == end)
		{
			std::cout << "没有找到该员工" << std::endl;
			flag = true;
		}
		else
		{
			flag = false;
			return *temp;
		}
	} while (flag);
}
//"<<"重载
ostream& operator<<(ostream& os, const vector<string>& s)
{
	for (auto& put : s)
		os << ',' << put;
	return os;
}
//保存内容到文件
void Administrator::saveFile(shared_ptr<map<int, vector<string>>>pFileDetails,ostream& os)
{
	for(auto it = pFileDetails->begin(); it != pFileDetails->end(); it++)
	{
		os << it->first << it->second << endl;
	}
}
//添加职工
pair<int, vector<string>>& Administrator::Add(shared_ptr<map<int, vector<string>>>pFileDetails)
{
	std::cout << "添加职工信息" << std::endl;
	bool flag;
	do
	{
		std::cout << "职工编号：";
		int number;
		cin >> number;
		if (pFileDetails->find(number) == pFileDetails->end())
		{
			flag = false;
			p.first = number;
			std::cout << "职工姓名：";
			string name;
			cin >> name;
			p.second.push_back(name);
			cout << "职工职位：";
			string position;
			cin >> position;
			p.second.push_back(position);
			cout << "职工职责：";
			string duty;
			cin >> duty;
			p.second.push_back(duty);
			return p;
		}
		else
		{
			cout << "职工编号已存在,请重新输入！" << endl;
			flag = true;
		}
	} while (flag);
}
//删除
void Administrator::Delete(shared_ptr<map<int, vector<string>>>pFileDetails)
{
	bool flag;
	do
	{
		std::cout << "请输入要删除的职工编号：";
		int number;
		cin >> number;
		auto find = pFileDetails->find(number);
		auto end = pFileDetails->end();
		if (find != end)
		{
			flag = false;
			pFileDetails->erase(number);
			cout << "删除成功！" << endl;
		}
		else
		{
			cout << "职工编号不存在,请重新输入！" << endl;
			flag = true;
		}
	} while (flag);
}
//读文件
map<int, vector<string>>& Administrator::readFile(istream& is)
{
	pair<int, vector<string>> p;
	int temp = 1;
	string line;
	while (getline(is,line))//获取文件的没一行内容
	{
		string str;
		istringstream ss(line);
		while (getline(ss, str, ','))//获取ss的每一行内容并通过‘，’进行拆分放入str中
		{
			if (temp % 4 == 1)
			{
				p.first = stoi(str);//string类型转换为int类型
				++temp;
				continue;
			}
			if (temp % 4 == 2)
			{
				p.second.push_back(str);
				++temp;
				continue;
			}
			if (temp % 4 == 3)
			{
				p.second.push_back(str);
				++temp;
				continue;
			}
			if (temp % 4 == 0)
			{
				temp = 1;
				p.second.push_back(str);
				details.insert(p);//把vector插入到map中
				p.second.clear();//清空vector内容
				continue;
			}
		}
	}
	return details;
}
//修改
pair<const int, vector<string>>& Administrator::Change(pair<const int, vector<string>>& changePair)
{
	string infor;
	cout << "员工姓名：";
	cin >> infor;
	changePair.second[0] = infor;
	cout << "员工职位：";
	cin >> infor;
	changePair.second[1] = infor;
	cout << "员工职责：";
	cin >> infor;
	changePair.second[2] = infor;
	return changePair;
}
//显示
void Administrator::show(map<int, vector<string>>& mapShow)
{
	for (auto& flag : mapShow)
	{
		cout << "工号：" << flag.first << endl;
		cout << "姓名：" << flag.second[0] << endl;
		cout << "岗位：" << flag.second[1] << endl;
		cout << "职责：" << flag.second[2] << endl;
	}
}
void Administrator::show(pair<const int, vector<string>>& mapShow)
{
		cout << "工号：" << mapShow.first << endl;
		cout << "姓名：" << mapShow.second[0] << endl;
		cout << "岗位：" << mapShow.second[1] << endl;
		cout << "职责：" << mapShow.second[2] << endl;
}
void Administrator::show(shared_ptr<map<int, vector<string>>>& mapShow)
{
	for (auto& flag : *mapShow)
	{
		cout << "工号：" << flag.first << endl;
		cout << "姓名：" << flag.second[0] << endl;
		cout << "岗位：" << flag.second[1] << endl;
		cout << "职责：" << flag.second[2] << endl;
		cout << endl;
	}
}

	
