#include "tree.h"

node::node(double d, size_t p):data(d),parent(p)
{

}

bool node::isRoot()
{
	if(this->parent==-1)
		return true;
	return false;
}

bool node::isSame(double s)
{
	if (s == data)
		return true;
	return false;
}

tree::tree(node& a)
{
	pNv.emplace_back(a);
	++node_number;
}

void tree::addNode(node& a)
{
	try
	{
		if (a.isRoot())
			throw std::exception("已存在root");
		else
			pNv.emplace_back(a);
	}
	catch (const std::exception&)
	{
		std::cout << "已存在root,程序强制结束" << std::endl;
		abort();
	}
}

std::vector<node>::iterator tree::findNode(double f)
{
	auto cbegin = pNv.begin();
	auto cend = pNv.cend();
	for (;cbegin!=cend;cbegin++)
	{
		if (cbegin->isSame(f))
			return cbegin;
	}
}

void tree::removeNode(std::vector<node>::iterator itNode)
{
	pNv.erase(itNode);
	std::cout << "ok" << std::endl;
}
