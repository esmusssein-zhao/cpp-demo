#include "LTDataType.h"
//改进：在某些情况下不需要像单链表判断节点所在位置
int main()
{
	// 创建返回链表的头结点.
	ListNode* a = ListCreate();
	//ListPushFront(a, 4);
	//ListPushBack(a, 1);
	ListPushFront(a, 3);
	ListPushBack(a, 2);
	//ListInsert(ListFind(a, 2), 6);
	ListErase(ListFind(a, 2));
	//ListPopFront(a);
	//ListPopBack(a);
	//ListDestory(a);
	ListPrint(a);
	return 0;
}
