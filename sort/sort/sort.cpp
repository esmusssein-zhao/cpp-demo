#include "sort.h"
#include "sort.hpp"
#include "lookup.hpp"
int main()
{
#if 0
	print_bit(12);//按位打印
	cout << Sum_of_factorials(4) << endl;//阶乘之和
	for (double b : Bubble_sort(a))//冒泡
		cout << b << " ";
	for (double b : Select_sort(a))//选择
		cout << b << " ";
	for (int b : Insert_sort(a))//插入
		cout << b << " ";
	cout << binary_search(a, 3) << endl;//二分查找
	cout << Ascending_order(a) << endl;//是否有序
	cout << binary_more_and_same_left(a, 677) << endl;//大于等于某数的最左位置
	cout << binary_less_and_same_right(a, 9) << endl;//小于等于某数的最右位置
#endif
	//vector<int> a = Random_vector();//随机向量
	vector<int> a{ 1,23,4,6,7,9,9,7,9,45,45,6,64,54 };
	for (int b : Insert_sort(a))
		cout << b << " ";
	cout << endl;
	
	return 0;
}

