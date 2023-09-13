#ifndef _HEAD_H_
#define _HEAD_H_

#include<iostream>
#include <vector>
#include <set>
#include <map>
#include <fstream>
#include <string>
class QueryResult;
//查询结果类
class TextQuery
{
public:
	TextQuery(std::ifstream&fs);
	QueryResult query(const std::string& word)const;
private:
	std::map<std::string, std::shared_ptr<std::set<int>>>word_place;//每个单词所在行号和内容
	std::shared_ptr<std::vector<std::string>>file;//输入文件
};

//查询类
class QueryResult
{
public:
	QueryResult(std::string s, 
		std::shared_ptr<std::set<int>>pl,
		std::shared_ptr<std::vector<std::string>>pf):
		sought(s), line_number(pl), file(pf){}
private:
	std::string sought;//查询单词
	std::shared_ptr<std::set<int>>line_number;//出现的行号
	std::shared_ptr<std::vector<std::string>>file;//输入文件
};

TextQuery::TextQuery(std::ifstream& fs):file(new std::vector<std::string>)
{
	std::string text;
	while (std::getline(fs, text))
	{
		file->push_back(text);
		int n = file->size() - 1;
		std::istringstream line(text);
		std::string word;
		while (line >> word)
		{
			std::shared_ptr<std::set<int>>& line_number = word_place[word];
			if (!line_number)
				line_number.reset(new std::set<int>);
			line_number->insert(n);
		}
	}
}

//查找并返回结果
void runQueries(std::ifstream& infile)
{
	TextQuery tq(infile);//保存文件建立查询map
	while (true)
	{
		std::cout << "enter word to look for,or q to quit:";
		std::string s;
		if (!(std::cin >> s) || s == "q")
			break;
		print(std::cout, tq.query(s)) << std::endl;//打印查询结果
	}
}
std::ostream print(std::ostream&, QueryResult&qr)
{
	
}

#endif
