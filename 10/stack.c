/*
 * 栈的相关操作的实现
 * by wareric@163.com
 * 2018-1-9
 */
#include <stdio.h>
#include "stack.h"

Stack* stack_init(int deep)
{
	Stack *s;
	s = malloc(sizeof(Stack));
	s->array = malloc(sizeof(int)*deep);
	s->top = -1;
	s->deep = deep;
	return s;
}

void stack_del(Stack *s)
{
	free(s->array);
	free(s);
}

bool stack_empty(Stack *s)
{
	if((s->top) < 0)
		return true;
	else
		return false;
}

void push(Stack *s, int x)
{
	if((s->top) >= ((s->deep)-1))
	{
		printf("overflow !!! push fail!!!\n");
		return;
	}else{
		s->top = ((s->top)+1);
		(s->array)[s->top] = x;
	}
}

int pop(Stack *s)
{
	if((s->top) < 0)
	{
		printf("underflow!!! pop fail\n");
		return -1;
	}else{
		s->top = ((s->top)-1);
		return (s->array)[(s->top)+1];
	}
}
