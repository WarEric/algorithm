/*
 * 队列相关操作的实现
 * by wareric@163.com
 * 2018-1-9
 */
#include "queue.h"

Queue* queue_init(int length)
{
	Queue *q;
	q = malloc(sizeof(Queue));
	q->array = malloc(sizeof(int)*length);
	q->head = 0;
	q->tail = 0;
	q->length = length;

	return q;
}

void queue_free(Queue *q)
{
	free(q->array);
	free(q);
}

bool isempty(Queue *q)
{
	if((q->head) == (q->tail))
		return true;
	else
		return false;
}

void enqueue(Queue *q, int x)
{
	if(add_one_test(q->tail, q->length) == (q->head))
	{
		printf("overflow, enqueue fail !!!\n");
		return;
	}else{
		(q->array)[q->tail] = x;
		if((q->tail) == ( (q->length) - 1))
			q->tail = 0;
		else
			q->tail = ((q->tail) + 1);
	}
}

int dequeue(Queue *q)
{
	if((q->head) == (q->tail))
	{
		printf("underflow, dequeue fail !!!\n");
		return -1;
	}else{
		int x;
		x = (q->array)[q->head];
		if((q->head) == ((q->length) - 1))
			q->head = 0;
		else
			q->head = ((q->head) + 1);

		return x;
	}
}

int add_one_test(int pos, int length)
{
	if(pos == (length -1 ))
		return 0;
	else
		return pos+1;
}
