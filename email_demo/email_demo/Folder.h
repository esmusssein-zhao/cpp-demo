#pragma once
#include <list>
#include "Message.h"
#include <string>
class Folder
{
	friend class Message;
private:
	std::list<Message*> lM;
	std::string name;
	int add_to_Folder(Message* m);
	int erease_from_Folder(Message* m);
public:
	Folder(std::string s) :lM(0),name(s) {}
	~Folder() {}
	int remove_from_list(Message* m);
	int add_to_list(Message* m);
	void print_list();
private:
	//½ûÓÃ¿½±´
	Folder(const Folder&) = delete;
	Folder& operator=(const Folder&) = delete;
};

