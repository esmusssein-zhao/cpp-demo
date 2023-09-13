#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>
template<typename C>
void print1(const C& arr)
{
	for (auto arrNum : arr)
		std::cout << arrNum << std::endl;
}
template void print1(const int& arr);
