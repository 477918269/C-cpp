#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int STDataType;

typedef struct Stack 
{
	STDataType* _a;
	int _top;       // Õ»¶¥
	int _capacity;  // ÈÝÁ¿ 
}Stack;

	void StackInit(Stack* ps);
	void StackDestory(Stack* ps);

	void StackPush(Stack* ps, STDataType x);
	void StackPop(Stack* ps);
	STDataType StackTop(Stack* ps);
	int StackEmpty(Stack* ps);
	int StackSize(Stack* ps);
	void StackPrint(Stack* ps);


	