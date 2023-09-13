#include "administrator.h"

using namespace std;
void Administrator::menu()
{
	std::cout << "0.�˳�" << std::endl;
	std::cout << "1.���ְ����Ϣ" << std::endl;
	std::cout << "2.��ʾ" << std::endl;
	std::cout << "3.ɾ��" << std::endl;
	std::cout << "4.�޸�" << std::endl;
	std::cout << "5.����" << std::endl;
}
void Administrator::Exit()
{
	system("pause");
	exit(0);
}
//����
pair<const int, vector<string, allocator<string>>>& Administrator::Find(shared_ptr<map<int, vector<string>>>pFileDetails)
{
	int id;
	bool flag;
	do
	{
		std::cout << "������Ҫ���һ��޸ĵ�Ա�����ţ�";
		cin >> id;
		auto temp = pFileDetails->find(id);
		auto end = pFileDetails->end();
		if (temp == end)
		{
			std::cout << "û���ҵ���Ա��" << std::endl;
			flag = true;
		}
		else
		{
			flag = false;
			return *temp;
		}
	} while (flag);
}
//"<<"����
ostream& operator<<(ostream& os, const vector<string>& s)
{
	for (auto& put : s)
		os << ',' << put;
	return os;
}
//�������ݵ��ļ�
void Administrator::saveFile(shared_ptr<map<int, vector<string>>>pFileDetails,ostream& os)
{
	for(auto it = pFileDetails->begin(); it != pFileDetails->end(); it++)
	{
		os << it->first << it->second << endl;
	}
}
//���ְ��
pair<int, vector<string>>& Administrator::Add(shared_ptr<map<int, vector<string>>>pFileDetails)
{
	std::cout << "���ְ����Ϣ" << std::endl;
	bool flag;
	do
	{
		std::cout << "ְ����ţ�";
		int number;
		cin >> number;
		if (pFileDetails->find(number) == pFileDetails->end())
		{
			flag = false;
			p.first = number;
			std::cout << "ְ��������";
			string name;
			cin >> name;
			p.second.push_back(name);
			cout << "ְ��ְλ��";
			string position;
			cin >> position;
			p.second.push_back(position);
			cout << "ְ��ְ��";
			string duty;
			cin >> duty;
			p.second.push_back(duty);
			return p;
		}
		else
		{
			cout << "ְ������Ѵ���,���������룡" << endl;
			flag = true;
		}
	} while (flag);
}
//ɾ��
void Administrator::Delete(shared_ptr<map<int, vector<string>>>pFileDetails)
{
	bool flag;
	do
	{
		std::cout << "������Ҫɾ����ְ����ţ�";
		int number;
		cin >> number;
		auto find = pFileDetails->find(number);
		auto end = pFileDetails->end();
		if (find != end)
		{
			flag = false;
			pFileDetails->erase(number);
			cout << "ɾ���ɹ���" << endl;
		}
		else
		{
			cout << "ְ����Ų�����,���������룡" << endl;
			flag = true;
		}
	} while (flag);
}
//���ļ�
map<int, vector<string>>& Administrator::readFile(istream& is)
{
	pair<int, vector<string>> p;
	int temp = 1;
	string line;
	while (getline(is,line))//��ȡ�ļ���ûһ������
	{
		string str;
		istringstream ss(line);
		while (getline(ss, str, ','))//��ȡss��ÿһ�����ݲ�ͨ�����������в�ַ���str��
		{
			if (temp % 4 == 1)
			{
				p.first = stoi(str);//string����ת��Ϊint����
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
				details.insert(p);//��vector���뵽map��
				p.second.clear();//���vector����
				continue;
			}
		}
	}
	return details;
}
//�޸�
pair<const int, vector<string>>& Administrator::Change(pair<const int, vector<string>>& changePair)
{
	string infor;
	cout << "Ա��������";
	cin >> infor;
	changePair.second[0] = infor;
	cout << "Ա��ְλ��";
	cin >> infor;
	changePair.second[1] = infor;
	cout << "Ա��ְ��";
	cin >> infor;
	changePair.second[2] = infor;
	return changePair;
}
//��ʾ
void Administrator::show(map<int, vector<string>>& mapShow)
{
	for (auto& flag : mapShow)
	{
		cout << "���ţ�" << flag.first << endl;
		cout << "������" << flag.second[0] << endl;
		cout << "��λ��" << flag.second[1] << endl;
		cout << "ְ��" << flag.second[2] << endl;
	}
}
void Administrator::show(pair<const int, vector<string>>& mapShow)
{
		cout << "���ţ�" << mapShow.first << endl;
		cout << "������" << mapShow.second[0] << endl;
		cout << "��λ��" << mapShow.second[1] << endl;
		cout << "ְ��" << mapShow.second[2] << endl;
}
void Administrator::show(shared_ptr<map<int, vector<string>>>& mapShow)
{
	for (auto& flag : *mapShow)
	{
		cout << "���ţ�" << flag.first << endl;
		cout << "������" << flag.second[0] << endl;
		cout << "��λ��" << flag.second[1] << endl;
		cout << "ְ��" << flag.second[2] << endl;
		cout << endl;
	}
}

	
