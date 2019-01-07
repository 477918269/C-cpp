#include"game.h"
int main()
{
	Queue pq;
	QueueInit(&pq);
	
	QueuePush(&pq, 2);
	QueuePush(&pq, 3);
	QueuePush(&pq, 4);
	QueuePrintf(&pq);
	QueueDestory(&pq);
	system("pause");

	return 0;
}