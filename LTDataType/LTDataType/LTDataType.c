#include "LTDataType.h"
// 创建返回链表的头结点.
ListNode* ListCreate()
{
    ListNode* head = (ListNode*)malloc(sizeof(ListNode));
    head->_next = NULL;
    head->_prev = NULL;
    return head;
}
// 双向链表销毁
void ListDestory(ListNode* plist)
{
    plist->_next = NULL;
    plist->_prev = NULL;
}
// 双向链表打印
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
// 双向链表尾插
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
		if (plist->_next == NULL)//只有一个头节点
		{
			newNode->_prev = plist;
			newNode->_next = plist;
			plist->_prev = newNode;
			plist->_next = newNode;
		}
		else//有其他节点
		{
			ListNode* flag = plist;//标记指针，避免改动原指针
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
//双向链表尾删
void ListPopBack(ListNode* plist)
{
	if (plist->_next == NULL)
	{
		printf("could not del!");
		exit(-1);
	}
	else
	{
			ListNode* flag = plist->_next;//标记指针，避免改动原指针,第一个有效数
			ListNode* frontFlag = NULL;
			while (flag->_next != plist)
			{
				frontFlag = flag;
				flag = flag->_next;
			}
			if (frontFlag == NULL)//只有一个节点
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
// 双向链表头插
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
// 双向链表头删
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
// 双向链表查找
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
// 双向链表在pos的前面进行插入
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
// 双向链表删除pos位置的节点
void ListErase(ListNode* pos)
{
	ListNode* frontPos = pos->_prev;
	ListNode* nextPos = pos->_next;
	frontPos->_next = nextPos;
	nextPos->_prev = frontPos;
}
