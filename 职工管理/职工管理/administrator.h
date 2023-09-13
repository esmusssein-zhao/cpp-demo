#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <memory>
//管理者对象
class Administrator
{
public:
	Administrator() = default;
	~Administrator() {};
	void menu();
	void Exit();
	std::pair<int, std::vector<std::string>>& Add(std::shared_ptr<std::map<int, std::vector<std::string>>>);
	void Delete(std::shared_ptr<std::map<int, std::vector<std::string>>>);
	void show(std::map<int, std::vector<std::string>>&);//显示内容（map&）
	void show(std::shared_ptr<std::map<int, std::vector<std::string>>>&);//显示内容（智能指针）
	void show(std::pair<const int, std::vector<std::string>>&);
	std::map<int, std::vector<std::string>>& readFile(std::istream&);//文件流读取内容
	std::pair<const int, std::vector<std::string>>& Change(std::pair<const int, std::vector<std::string>>&);
	void saveFile(std::shared_ptr<std::map<int, std::vector<std::string>>>, std::ostream&);//保存内容
	std::pair<const int, std::vector<std::string, std::allocator<std::string>>>& Find(std::shared_ptr<std::map<int, std::vector<std::string>>>);
private:
	std::map<int, std::vector<std::string>> details;//文件读取后放入map中
	std::pair<int, std::vector<std::string>> p;
};
