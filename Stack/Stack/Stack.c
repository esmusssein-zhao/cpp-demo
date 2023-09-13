#include "Stack.h"

// ��ʼ��ջ
void StackInit(Stack* ps)
{
	ps->_a  = (STDataType*)malloc(sizeof(STDataType)*4);
	ps->_top = 0;
	ps->_capacity = 4;
}
// ��ջ
void StackPush(Stack* ps, STDataType data)
{
	CheckCapacity(ps);
	ps->_a[ps->_top] = data;
	ps->_top++;
}
// ��ջ
void StackPop(Stack* ps)
{
	ps->_top--;
}
// ��ȡջ��Ԫ��
STDataType StackTop(Stack* ps)
{
	return ps->_a[--ps->_top];
}
// ��ȡջ����ЧԪ�ظ���
int StackSize(Stack* ps)
{
	return ps->_top+1;
}
// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0
int StackEmpty(Stack* ps)
{
	if (ps->_top > 0)
	{
		return 0;
	}
	else
		return -1;
}
// ����ջ
void StackDestroy(Stack* ps)
{
	free(ps);
	ps = NULL;
}
// ���ռ䣬������ˣ���������
void CheckCapacity(Stack* ps)
{
	if (ps->_capacity <= ps->_top)
	{
		ps->_capacity *= 2;
		ps->_a = (STDataType*)realloc(ps->_a, sizeof(STDataType) * ps->_capacity);//���·���տռ�Ϊԭ����2�����˴���*Ϊ��
		assert(ps->_a);
	}
	else
	{
		return 0;
	}
}
