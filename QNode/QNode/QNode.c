#include "QNode.h"
// ��ʼ������
void QueueInit(Queue* q)
{
	q->_front = NULL;
	q->_rear = NULL;
}
// ��β�����
void QueuePush(Queue* q, QDataType data)
{
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	newNode->_data = data;
	newNode->_pNext = NULL;
	if (q->_front == NULL)
	{
		q->_front = newNode;
		q->_rear = newNode;
	}
	else
	{
		q->_rear->_pNext = newNode;
		q->_rear = newNode;
	}
}
// ��ͷ������
void QueuePop(Queue* q)
{
	if (q->_front == q->_rear)
	{
		QNode* head = q->_front;
		free(head);
		q->_front = NULL;
		q->_rear = NULL;
	}
	else
	{
		QNode* head = q->_front;
		q->_front = head->_pNext;
		free(head);
		head = NULL;
	}
}
// ��ȡ����ͷ��Ԫ��
QDataType QueueFront(Queue* q)
{
	if (q->_front == q->_rear)
	{
		printf("link queue is null!");
		return 0;
	}
	else
	{
		return q->_front->_data;
	}
	
}
// ��ȡ���ж�βԪ��
QDataType QueueBack(Queue* q)
{
	if (q->_front == q->_rear)
	{
		printf("link queue is null!");
		return 0;
	}
	else
	{
		return q->_rear->_data;
	}
}
// ��ȡ��������ЧԪ�ظ���
int QueueSize(Queue* q)
{
	QNode* head = q->_front;
	if (q->_front == q->_rear)
	{
		return 1;
	}
	if (q->_front == NULL)
	{
		return 0;
	}
	else
	{
		int count = 1;
		while(head->_pNext!= q->_rear)
		{
			count++;
			head = head->_pNext;
		}
		return ++count;
	}
}
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0
int QueueEmpty(Queue* q)
{
	if (q->_front != NULL)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
// ���ٶ���
void QueueDestroy(Queue* q)
{
	free(q);
	q = NULL;
}
