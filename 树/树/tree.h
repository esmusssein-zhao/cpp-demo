#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
class node
{
private:
	double data;
	size_t parent;
public:
	node(double d, size_t p);
	bool isRoot();
	bool isSame(double);
};

class tree
{
private:
	std::vector<node> pNv;
	size_t node_number=0;
public:
	tree(node& a);
	void addNode(node& a);
	std::vector<node>::iterator findNode(double);
	void removeNode(std::vector<node>::iterator itNode);
};	