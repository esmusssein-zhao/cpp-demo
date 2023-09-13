#include "Stack.h"

// 初始化栈
void StackInit(Stack* ps)
{
	ps->_a  = (STDataType*)malloc(sizeof(STDataType)*4);
	ps->_top = 0;
	ps->_capacity = 4;
}
// 入栈
void StackPush(Stack* ps, STDataType data)
{
	CheckCapacity(ps);
	ps->_a[ps->_top] = data;
	ps->_top++;
}
// 出栈
void StackPop(Stack* ps)
{
	ps->_top--;
}
// 获取栈顶元素
STDataType StackTop(Stack* ps)
{
	return ps->_a[--ps->_top];
}
// 获取栈中有效元素个数
int StackSize(Stack* ps)
{
	return ps->_top+1;
}
// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0
int StackEmpty(Stack* ps)
{
	if (ps->_top > 0)
	{
		return 0;
	}
	else
		return -1;
}
// 销毁栈
void StackDestroy(Stack* ps)
{
	free(ps);
	ps = NULL;
}
// 检查空间，如果满了，进行增容
void CheckCapacity(Stack* ps)
{
	if (ps->_capacity <= ps->_top)
	{
		ps->_capacity *= 2;
		ps->_a = (STDataType*)realloc(ps->_a, sizeof(STDataType) * ps->_capacity);//重新分配空空间为原来的2倍，此处的*为乘
		assert(ps->_a);
	}
	else
	{
		return 0;
	}
}
