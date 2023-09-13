#include "SListNode.h"

int main()
{
	SListNode* a = NULL;
	//头插
	SListPushFront(&a, 4);
	SListPushFront(&a, 5);
	//尾插
	SListPushBack(&a, 1);
	SListPushBack(&a, 2);
	SListPushBack(&a, 3);
	//SListPushBack(&a, 4);
	//尾删
	//SListPopBack(&a);
	// 查找
	//SListNode* b = SListFind(a, 3);
	// 删除位置
	//SListErase(&a, b);
	// 位置前添加
	//SListInsert(&a,b, 6);
	//头删
	//SListPopFront(&a);
	//打印
	SListPrint(a);
	reSListPrint(a);
	return 0;
}