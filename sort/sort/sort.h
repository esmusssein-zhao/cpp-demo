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
		//����1��10��100�����һ������λ�룬ֻ��0��������
		cout << ((num & (1 << i)) ? "1" : "0");
	}
}
int Sum_of_factorials(int num)
{
//����һ �ݹ�
#if 0
	//�ȿ��ǳ��ں���ڣ���д���ڣ���д���
	int total=1;
	while (num > 1)//�Ƿ����
	{
		for (int flag = num; flag > 1; flag--)
		{
			total = total * flag;
		}
		//���
		return total += Sum_of_factorials(num - 1);
	}
	//����
	return total;
#endif
//������
	int total = 0;
	int flag = 1;
	for (int i = 1; i <= num; i++)
	{
		flag *= i;
		total += flag;
	}
	return total;
}
