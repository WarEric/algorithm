/*
 * 对队列结构进行测试
 * by wareric@163.com
 * 2018-1-9
 */
#include <stdio.h>
#include "queue.h"
int main()
{
	Queue *q;
	q = queue_init(5);

	printf("after init, whether queue is empty : %d \n\n", isempty(q));
	
	printf("enqueue(q,1)\n");
	enqueue(q, 1);
	printf("enqueue(q,2)\n");
	enqueue(q, 2);
	printf("enqueue(q,3)\n");
	enqueue(q, 3);
	printf("enqueue(q,4)\n");
	enqueue(q, 4);
	printf("enqueue(q,5)\n");
	enqueue(q, 5);
	printf("enqueue(q,6)\n");
	enqueue(q, 6);

	printf("\n\n");

	printf("dequeue(q) = %d\n", dequeue(q));
	printf("dequeue(q) = %d\n", dequeue(q));
	printf("dequeue(q) = %d\n", dequeue(q));
	printf("dequeue(q) = %d\n", dequeue(q));
	printf("dequeue(q) = %d\n", dequeue(q));
	printf("dequeue(q) = %d\n", dequeue(q));

	printf("\n\n");

	printf("after dequeue, whether queue is empty : %d \n", isempty(q));

	return 0;
}
