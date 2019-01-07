
#include"game.h"
int main()
{
	Stack ps;

	StackInit(&ps);
	StackPush(&ps, 1);
	StackPush(&ps, 2);
	StackPush(&ps, 3);
	StackPush(&ps, 4);
	StackPush(&ps, 5);
	StackTop(&ps);
	StackPop(&ps);

	StackPrint(&ps);

	StackDestory(&ps);
	system("pause");
	return 0;
}