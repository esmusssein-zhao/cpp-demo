#include "List.h"

void List::add(const int createInfo)
{
	shared_ptr<Node> nextList = make_shared<Node>(createInfo);
	shared_ptr<Node> pend = endNode();
	pend->pchangeNext(nextList);
	longsize++;
}

void List::print() const
{
	if (head == 0)
	{
		cout << "null" << endl;
	}
	else
	{
		shared_ptr<Node> flag = head;
		for (int i = 1; i < longsize; i++)
		{
			cout << flag->getInfo() << "->";
			flag = flag->pgetNext();
		}
		cout << flag->getInfo() << endl;
	}
	
}

void List::popback()
{
	if (longsize == 1)
	{
		head = nullptr;
	}
	else
	{ 
		int temp = longsize;
		shared_ptr<Node> flag = head;
		for (int i = 1; i < temp-1; i++)
		{
			head = head->pgetNext();
		}
		head->pchangeNext(nullptr);
		head = flag;
		longsize--;
	}
}

shared_ptr<Node> List::endNode()
{
	shared_ptr<Node> flag = head;
	while (flag->pgetNext() != nullptr)
	{
		flag = flag->pgetNext();
	}
	return flag;
}


