#include "Folder.h"
#include  <iostream>

int Folder::add_to_Folder(Message* m)
{
	lM.emplace_back(m);
	return 1;
}

int Folder::erease_from_Folder(Message* m)
{
	auto temp = lM.cbegin();
	auto end = lM.cend();
	for (temp; temp != end; temp++)
	{
		if (*temp == m)
		{
			lM.erase(temp);
			return 1;
		}
	}
	return 0;
}

int Folder::remove_from_list(Message* m)
{
	erease_from_Folder(m);
	m->erease_from_Message(this);
	return 1;
}

int Folder::add_to_list(Message* m)
{
	lM.emplace_back(m);
	m->add_to_Message(this);
	return 1;
}

void Folder::print_list()
{
	std::cout << "Folder have:" << std::endl;
	for (auto single : lM)
		std::cout << single->name << std::endl;
}
