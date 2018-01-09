/*
 * 栈的相关数据结构和对应的
 * 头文件,初始化时要采用init
 * 函数来生成指定深度的栈
 * by wareric@163.com
 * 2018-1-9
 */
#ifndef STACK_H_
#define STACK_H_

#include <stdbool.h>
#include <stdlib.h>

struct stack{
	int* array;
	int top;
	int deep;//栈深度
};

typedef struct stack Stack;

/*
 * 初始化一个栈，栈对应的指针,
 * 栈使用结束时要调用对应的del
 * 函数回收
 */
Stack* stack_init(int deep);

/*
 * 回收一个栈
 */
void stack_del(Stack *s);

/*
 * 判断栈是否为空，
 * s     要判断的栈
 *
 * return 
 * true  表示栈为空
 * false 表示栈不为空
 */
bool stack_empty(Stack *s);

/*
 * 向栈中写入一个数据
 * s     要写入的栈
 * x     要写的数据
 */
void push(Stack *s, int x);

/*
 * 弹出栈中的一个数据
 * s     要弹出的栈
 * 
 * return
 * -1    表示underflow
 */
int pop(Stack *s);

#endif
