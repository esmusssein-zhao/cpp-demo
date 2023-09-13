#include "Stack.h"

int main()
{
	Stack a;
	StackInit(&a);
	StackPush(&a, 1);
	StackPush(&a, 2);
	StackPush(&a, 4);
	StackPush(&a, 3);
	StackPop(&a);
	printf("%d\n", StackTop(&a));
	printf("%d", StackSize(&a));
	return 0;
}