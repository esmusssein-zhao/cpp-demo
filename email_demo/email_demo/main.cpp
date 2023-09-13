#include "Folder.h"
#include "Message.h"
#include <iostream>

int main(int argc, char* argv[])
{
	Message* m1(new Message("m1"));
	Message* m2(new Message("m2"));
	Folder* book(new Folder("book"));
	m1->save_to_list(book);
	m2->save_to_list(book);
	m1->print_list();
	m2->print_list();
	book->print_list();
	std::cout<<"_________________" << std::endl;
	book->remove_from_list(m1);
	m1->print_list();
	book->print_list();
	std::cout << "_________________" << std::endl;
	book->add_to_list(m1); 
	m1->print_list();
	book->print_list();
	return 0;
}