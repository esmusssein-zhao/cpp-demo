#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <memory>
//�����߶���
class Administrator
{
public:
	Administrator() = default;
	~Administrator() {};
	void menu();
	void Exit();
	std::pair<int, std::vector<std::string>>& Add(std::shared_ptr<std::map<int, std::vector<std::string>>>);
	void Delete(std::shared_ptr<std::map<int, std::vector<std::string>>>);
	void show(std::map<int, std::vector<std::string>>&);//��ʾ���ݣ�map&��
	void show(std::shared_ptr<std::map<int, std::vector<std::string>>>&);//��ʾ���ݣ�����ָ�룩
	void show(std::pair<const int, std::vector<std::string>>&);
	std::map<int, std::vector<std::string>>& readFile(std::istream&);//�ļ�����ȡ����
	std::pair<const int, std::vector<std::string>>& Change(std::pair<const int, std::vector<std::string>>&);
	void saveFile(std::shared_ptr<std::map<int, std::vector<std::string>>>, std::ostream&);//��������
	std::pair<const int, std::vector<std::string, std::allocator<std::string>>>& Find(std::shared_ptr<std::map<int, std::vector<std::string>>>);
private:
	std::map<int, std::vector<std::string>> details;//�ļ���ȡ�����map��
	std::pair<int, std::vector<std::string>> p;
};
