#ifndef _HEAD_H_
#define _HEAD_H_

#include<iostream>
#include <vector>
#include <set>
#include <map>
#include <fstream>
#include <string>
class QueryResult;
//��ѯ�����
class TextQuery
{
public:
	TextQuery(std::ifstream&fs);
	QueryResult query(const std::string& word)const;
private:
	std::map<std::string, std::shared_ptr<std::set<int>>>word_place;//ÿ�����������кź�����
	std::shared_ptr<std::vector<std::string>>file;//�����ļ�
};

//��ѯ��
class QueryResult
{
public:
	QueryResult(std::string s, 
		std::shared_ptr<std::set<int>>pl,
		std::shared_ptr<std::vector<std::string>>pf):
		sought(s), line_number(pl), file(pf){}
private:
	std::string sought;//��ѯ����
	std::shared_ptr<std::set<int>>line_number;//���ֵ��к�
	std::shared_ptr<std::vector<std::string>>file;//�����ļ�
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

//���Ҳ����ؽ��
void runQueries(std::ifstream& infile)
{
	TextQuery tq(infile);//�����ļ�������ѯmap
	while (true)
	{
		std::cout << "enter word to look for,or q to quit:";
		std::string s;
		if (!(std::cin >> s) || s == "q")
			break;
		print(std::cout, tq.query(s)) << std::endl;//��ӡ��ѯ���
	}
}
std::ostream print(std::ostream&, QueryResult&qr)
{
	
}

#endif
