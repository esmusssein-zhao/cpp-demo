#include "SListNode.h"

// ��̬����һ���ڵ�
SListNode* BuySListNode(SLTDateType x)
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	if (newNode == NULL)
	{
		printf("list is null!");
		exit(-1);
	}
	else
	{
		newNode->data = x;
		newNode->next = NULL;
		return newNode;
	}
}
// �������ͷ��
void SListPushFront(SListNode** pplist, SLTDateType x)
{
	SListNode* plist = BuySListNode(x);
	if (*pplist == NULL)
	{
		*pplist = plist;
	}
	else
	{
		plist->next = *pplist;
		*pplist = plist;
	}
}
// �������βɾ
void SListPopBack(SListNode** pplist)
{
	if (*pplist == NULL)
	{
		exit(-1);
	}
	else
	{
		SListNode* phead = *pplist;
		SListNode* q = NULL;
		while (phead->next != NULL)
		{
			q = phead;
			phead = phead->next;
		}
		free(phead);
		phead = NULL;
		if (q == NULL)
		{
			*pplist = NULL;
			printf("list is null!");
			Sleep(1000);
			exit(-1);
		}
		else
		{
			q->next = NULL;
		}
	}
}
// �������ӡ
void SListPrint(SListNode* plist)
{
	SListNode* flag = plist;
	if (flag == NULL)
	{
		printf("list is null!");
	}
	else
	{
		while(flag != NULL)
		{
			printf(" %d ->", flag->data);
			flag = flag->next;
		}
		printf("NULL");
	}
	printf("\n");
}
// ���������ӡ(�ݹ�)�����������������ܵ��º�������ջ�����Ӧ��ʹ��ջ���з����������
void reSListPrint(SListNode* phead)
{
	if(phead != NULL)
	{
		if (phead->next != NULL)
			reSListPrint(phead->next);
		printf("%d <-", phead->data);
	}
}
// ������β��
void SListPushBack(SListNode** pplist, SLTDateType x)
{
	SListNode* plist = BuySListNode(x);
	if (*pplist == NULL)
	{
		*pplist = plist;
	}
	else
	{
		SListNode* phead = *pplist;
		while (phead->next != NULL)
		{
			phead = phead->next;
		}
		phead->next = plist;
	}
}
// ������ͷɾ
void SListPopFront(SListNode** pplist)
{
	if (*pplist == NULL)
	{
		exit(-1);
	}
	else
	{
		SListNode* phead = *pplist;
		phead = phead->next;
		free(*pplist);
		*pplist = phead;
	}
}
// ���������
SListNode* SListFind(SListNode* plist, SLTDateType x)
{
	while (plist->next != NULL)
	{
		if (plist->data == x)
		{
			return plist;
		}
		else
		{
			plist = plist->next;
		}
	}
	if (plist->data != x)
	{
		return NULL;
	}
	return plist;
}
// ��������posλ��֮ǰ����x
void SListInsert(SListNode** pplist, SListNode* pos, SLTDateType x)
{
	SListNode* newNode = BuySListNode(x);
	SListNode* phead = *pplist;
	/*if (pos == phead)
	{
		newNode->next = phead;
		*pplist = newNode;
	}*/
	if (phead->next != pos)
	{
		phead = phead->next;
	}
	newNode->next = phead->next;
	phead->next = newNode;
}
// ������ɾ��posλ�õ�ֵ
void SListErase(SListNode** pplist, SListNode* pos) 
{
	SListNode* phead = *pplist;
	if (phead == NULL)
	{
		printf("error:list is NULL!");
	}
	if (phead == pos)
	{
		phead = phead->next;
		*pplist = phead;
	}
	else
	{
		while (phead->next != pos)
		{
			phead = phead->next;
		}
		if (pos->next == NULL)
		{
			free(pos);
			phead->next = NULL;
		}
		else
		{
			phead->next = pos->next;
			free(pos);
			pos = NULL;
		}
	}
}

