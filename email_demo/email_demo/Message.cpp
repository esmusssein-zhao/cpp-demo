#include "Message.h"
#include <iostream>
int Message::add_to_Message(Folder* f)
{
	vF.emplace_back(f);
	return 0;
}
int Message::erease_from_Message(Folder* f)
{
	auto temp = vF.cbegin();
	auto end = vF.cend();
	for (temp; temp != end; temp++)
	{
		if (*temp == f)
		{
			vF.erase(temp);
			return 1;
		}
	}
	return 0;
}
Message::Message(const Message& m)
{
	contents = m.contents;
	name = m.name;
	vF = m.vF;
}

Message& Message::operator=(const Message& m)
{
	name = m.name;
	contents = m.contents;
	vF = m.vF;
	return *this;
}

int Message::save_to_list(Folder* fName)
{
	vF.emplace_back(fName);
	fName->add_to_Folder(this);
	return 1;
}

int Message::remove_from_list(Folder* fName)
{
	erease_from_Message(fName);
	fName->erease_from_Folder(this);
	return 1;
}

void Message::print_list()
{
	std::cout << "Message have:" << std::endl;
	for (auto single : vF)
		std::cout << single->name << std::endl;
}

