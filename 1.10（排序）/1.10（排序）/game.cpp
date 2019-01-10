#include"game.h"


void StackInit(Stack* ps)
{
	assert(ps);
	ps->_a = NULL;
	ps->_capacity = 0;
	ps->_top = NULL;
}

void StackDestory(Stack* ps)
{
	assert(ps);
	free(ps->_a);
	ps->_a = NULL;
	ps->_capacity = 0;
	ps->_top = 0;
}

void StackPush(Stack* ps, STDataType x)
{
	assert(ps);
	if (ps->_capacity == ps->_top)
	{
		int newcapacity = ps->_capacity == 0 ? 4 : ps->_capacity * 2;
		ps->_a = (STDataType*)realloc(ps->_a, sizeof(STDataType)*newcapacity);
		ps->_capacity = newcapacity;
	}
	ps->_a[ps->_top] = x;
	ps->_top++;
}

void StackPop(Stack* ps)
{
	assert(ps && ps->_top > 0);
	ps->_top--;
}

STDataType StackTop(Stack* ps)
{
	assert(ps);
	return ps->_a[ps->_top-1];//取上一个，而不是--。
}
int StackEmpty(Stack* ps)
{
	return ps->_top == 0 ? 0 : 1;
}
int StackSize(Stack* ps)
{
	return ps->_top;
}

void StackPrint(Stack* ps)
{
	int i = 0;
	for (int i = 0; i < ps->_top; i++)
	{
		printf("%d\n", ps->_a[i]);
	}
}