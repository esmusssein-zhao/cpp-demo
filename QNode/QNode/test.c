#include "QNode.h"

int main()
{
	QNode a;
	QueueInit(&a);
	QueuePush(&a, 1);
	QueuePush(&a, 2);
	QueuePush(&a, 3);
	QueuePop(&a);
	printf("%d ",QueueFront(&a)); 
	printf("%d ",QueueBack(&a));
	printf("%d ",QueueSize(&a));
	return 0;
}