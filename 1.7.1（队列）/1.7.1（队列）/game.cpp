#include"game.h"
void QueueInit(Queue* pq)
{
	pq->_front = NULL;
	pq->_last  = NULL;
}

void QueueDestory(Queue* pq)
{
	pq->_front->_data = 0;
	pq->_front->_next = NULL;
	free(pq->_front);
	pq->_last->_data = 0;
	pq->_last->_next = NULL;
	free(pq->_last);
}

QueueNode* BuyQueueNode(QUDataType x)
{
	QueueNode* newlast = (QueueNode*)malloc(sizeof(QueueNode));
	newlast->_data = x;
	newlast->_next = NULL;
	return newlast;

}

void QueuePush(Queue* pq, QUDataType x)
{
	QueueNode* next = pq->_front;
	if (pq->_front == NULL)
	{
		pq->_last = pq->_front = BuyQueueNode(x);
	}
	else
	{

		pq->_last->_next = BuyQueueNode(x);
		pq->_last = pq->_last->_next;
	}
}

void QueuePop(Queue* pq)
{
	if (pq->_last == NULL)
	{
		return;
	}
	QueueNode* head = pq->_front;
	pq->_front = pq->_front->_next;
	free(head);
	

}

QUDataType QueueFront(Queue* pq)
{
	return pq->_front->_data;
}

QUDataType QueueBack(Queue* pq)
{
	return pq->_last->_data;
}

int QueueEmpty(Queue* pq)
{
	return pq->_front == NULL ? 1 : 0;
}

int QueueSize(Queue* pq)
{
	QueueNode* head = pq->_front ;
	int size = 0;
	while (head)
	{
		head = head->_next;
		size++;
	}
	return size;
}

void QueuePrintf(Queue* pq)
{
	QueueNode* head = pq->_front;
	while (head)
	{
		printf("%d", head->_data );
		head = head->_next ;
	}
}