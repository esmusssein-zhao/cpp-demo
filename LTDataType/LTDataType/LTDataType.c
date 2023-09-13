#include "LTDataType.h"
// �������������ͷ���.
ListNode* ListCreate()
{
    ListNode* head = (ListNode*)malloc(sizeof(ListNode));
    head->_next = NULL;
    head->_prev = NULL;
    return head;
}
// ˫����������
void ListDestory(ListNode* plist)
{
    plist->_next = NULL;
    plist->_prev = NULL;
}
// ˫�������ӡ
void ListPrint(ListNode* plist)
{
	ListNode* flag = plist;
	if (flag->_next== NULL)
	{
		printf("list is null!");
	}
	else
	{
		flag = flag->_next;
		while (flag->_next != plist)
		{
			printf(" %d ->", flag->_data);
			flag = flag->_next;
		}
		printf(" %d ", flag->_data);
	}
}
// ˫������β��
void ListPushBack(ListNode* plist, LTDataType x)
{
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	if (newNode == NULL)
	{
		printf("error:create error!");
		exit(-1);
	}
	else
	{
		newNode->_data = x;
		if (plist->_next == NULL)//ֻ��һ��ͷ�ڵ�
		{
			newNode->_prev = plist;
			newNode->_next = plist;
			plist->_prev = newNode;
			plist->_next = newNode;
		}
		else//�������ڵ�
		{
			ListNode* flag = plist;//���ָ�룬����Ķ�ԭָ��
			while (flag->_next != plist)
			{
				flag = flag->_next;
			}
			newNode->_next = plist;
			newNode->_prev = flag;
			flag->_next = newNode;
		}
	}
}
//˫������βɾ
void ListPopBack(ListNode* plist)
{
	if (plist->_next == NULL)
	{
		printf("could not del!");
		exit(-1);
	}
	else
	{
			ListNode* flag = plist->_next;//���ָ�룬����Ķ�ԭָ��,��һ����Ч��
			ListNode* frontFlag = NULL;
			while (flag->_next != plist)
			{
				frontFlag = flag;
				flag = flag->_next;
			}
			if (frontFlag == NULL)//ֻ��һ���ڵ�
			{
				free(flag);
				flag = NULL;
				plist->_next = NULL;
				plist->_prev = NULL;
			}
			else
			{
				free(flag);
				flag = NULL;
				frontFlag->_next = plist;
			}
	}
}
// ˫������ͷ��
void ListPushFront(ListNode* plist, LTDataType x)
{
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	while (newNode == NULL)
	{
		printf("error:create error!");
		exit(-1);
	}
	newNode->_data = x;
	if (plist->_next == NULL)
	{
		newNode->_prev = plist;
		newNode->_next = plist;
		plist->_prev = newNode;
		plist->_next = newNode;
	}
	else
	{
		ListNode* flag = plist->_next;
		newNode->_next = flag;
		newNode->_prev = plist;
		flag->_prev = newNode;
		plist->_next = newNode;
	}
}
// ˫������ͷɾ
void ListPopFront(ListNode* plist)
{
	while (plist->_next == NULL)
	{
		printf("error:list is null!");
		exit(-1);
	}
	ListNode* flag = plist->_next;
	if (flag->_next == plist)
	{
		free(flag);
		flag = NULL;
		plist->_next = NULL;
		plist->_prev = NULL;
	}
	else
	{
		ListNode* nextFlag = flag->_next;
		plist->_next = nextFlag;
		nextFlag->_prev = plist;
		free(flag);
		flag = NULL;
	}
}
// ˫���������
ListNode* ListFind(ListNode* plist, LTDataType x)
{
	ListNode* flag = plist;
	while (flag->_next != plist)
	{
		if (flag->_data == x)
		{
			return flag;
		}
		else
		{
			flag = flag->_next;
		}
	}
	if (flag->_data != x)
	{
		return NULL;
	}
	return flag;
}
// ˫��������pos��ǰ����в���
void ListInsert(ListNode* pos, LTDataType x)
{
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	while (newNode == NULL)
	{
		printf("error:create error!");
		exit(-1);
	}
	newNode->_data = x;
	ListNode* frontPos = pos->_prev;
	newNode->_next = pos;
	newNode->_prev = frontPos;
	pos->_prev = newNode;
	frontPos->_next = newNode;
}
// ˫������ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos)
{
	ListNode* frontPos = pos->_prev;
	ListNode* nextPos = pos->_next;
	frontPos->_next = nextPos;
	nextPos->_prev = frontPos;
}
