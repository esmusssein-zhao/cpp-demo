#include "SListNode.h"

int main()
{
	SListNode* a = NULL;
	//ͷ��
	SListPushFront(&a, 4);
	SListPushFront(&a, 5);
	//β��
	SListPushBack(&a, 1);
	SListPushBack(&a, 2);
	SListPushBack(&a, 3);
	//SListPushBack(&a, 4);
	//βɾ
	//SListPopBack(&a);
	// ����
	//SListNode* b = SListFind(a, 3);
	// ɾ��λ��
	//SListErase(&a, b);
	// λ��ǰ���
	//SListInsert(&a,b, 6);
	//ͷɾ
	//SListPopFront(&a);
	//��ӡ
	SListPrint(a);
	reSListPrint(a);
	return 0;
}