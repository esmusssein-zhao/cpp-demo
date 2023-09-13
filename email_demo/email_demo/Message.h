#pragma once
#include <list>
#include "Folder.h"
#include <string>

class Message
{
	friend class Folder;
private:
	std::string name;
	std::string contents;
	std::list<Folder*> vF;
	int add_to_Message(Folder* f);
	int erease_from_Message(Folder* f);
public:
	Message(std::string s) :name(s), contents("NULL"), vF() {}
	Message(std::string s,std::string content) :name(s), contents(content), vF() {}
	Message(const Message& m);
	Message& operator=(const Message& m);
	int save_to_list(Folder* fName);
	int remove_from_list(Folder* fName);
	//应该为拷贝和复制构造
	/*int copy_myself();
	void erase_myself();*/
	void print_list();
	~Message() {}
};

