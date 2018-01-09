/*
 * 对stack进行测试的程序，用以验证stack的正确性
 * 已经演示如何使用
 * by wareric@163.com
 * 2018-1-9
 */
#include <stdio.h>
#include "stack.h"

int main()
{
	Stack *s;
	s = stack_init(5);

	printf("after init, whether Stack is empty: %d \n\n", 
			stack_empty(s));

	printf("push(s, 1)\n");
	push(s, 1);
	printf("push(s, 2)\n");
	push(s, 2);
	printf("push(s, 3)\n");
	push(s, 3);
	printf("push(s, 4)\n");
	push(s, 4);
	printf("push(s, 5)\n");
	push(s, 5);
	printf("push(s, 6)\n");
	push(s, 6);

	printf("\n");

	printf("pop(s) = %d\n", pop(s));
	printf("pop(s) = %d\n", pop(s));
	printf("pop(s) = %d\n", pop(s));
	printf("pop(s) = %d\n", pop(s));
	printf("pop(s) = %d\n", pop(s));
	printf("pop(s) = %d\n", pop(s));
	printf("\n");

	printf("after pop, whether Stack is empty: %d \n\n", 
			stack_empty(s));

	stack_del(s);

	return 0;
}
