#include "QNode.h"
// 初始化队列
void QueueInit(Queue* q)
{
	q->_front = NULL;
	q->_rear = NULL;
}
// 队尾入队列
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
// 队头出队列
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
// 获取队列头部元素
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
// 获取队列队尾元素
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
// 获取队列中有效元素个数
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
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0
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
// 销毁队列
void QueueDestroy(Queue* q)
{
	free(q);
	q = NULL;
}
