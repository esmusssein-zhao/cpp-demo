#include "LTDataType.h"
//�Ľ�����ĳЩ����²���Ҫ�������жϽڵ�����λ��
int main()
{
	// �������������ͷ���.
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
