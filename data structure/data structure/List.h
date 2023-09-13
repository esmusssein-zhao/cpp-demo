#pragma once
#include <iostream>
#include <memory>

using namespace std;
class Node
{
public:
	Node():info(0),pnext(nullptr){}
	Node(int a ) :info(a), pnext(nullptr) {}
	void pchangeNext(const shared_ptr<Node>& next)
	{
		pnext = next;
	}
	const shared_ptr<Node> pgetNext()const
	{
		return pnext;
	}
	int getInfo()const
	{
		return info;
	}
	void changeInfo(int a)
	{
		info = a;
	}
private:
	int info;
	shared_ptr<Node> pnext;
};
class List
{
public:
	List() :head(nullptr),longsize(0) {}
	List(int a) :head(new Node(a)), longsize(1) {}
	void add(const int createInfo);
	void print()const;
	void popback();
	shared_ptr<Node> endNode();
private:
	shared_ptr<Node> head;
	int longsize;
};

