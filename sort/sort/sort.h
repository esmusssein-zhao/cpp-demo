#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;
std::vector<int> Random_vector()
{
	srand((unsigned int) time(NULL));
	std::vector<int> v;
	int num = rand() % 30;
	for (; num > 0; num--)
	{
		v.push_back(rand() % 1000);
	}
	return v;
}
void print_bit(int num)
{
	for (int i = 31; i > 0; i--)
	{
		//整数1，10，100这类和一个数按位与，只有0和其他数
		cout << ((num & (1 << i)) ? "1" : "0");
	}
}
int Sum_of_factorials(int num)
{
//方法一 递归
#if 0
	//先考虑出口和入口；先写出口，再写入口
	int total=1;
	while (num > 1)//是否进入
	{
		for (int flag = num; flag > 1; flag--)
		{
			total = total * flag;
		}
		//入口
		return total += Sum_of_factorials(num - 1);
	}
	//出口
	return total;
#endif
//方法二
	int total = 0;
	int flag = 1;
	for (int i = 1; i <= num; i++)
	{
		flag *= i;
		total += flag;
	}
	return total;
}
