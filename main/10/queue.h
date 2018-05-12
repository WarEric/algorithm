/*
 * 队列相关的结构体和操作的头文件,
 * 这里使用时要注意满队列中会存在
 * 一个空的位置，所真正队列能存储
 * 的数据个数位length-1
 * by wareric@163.com
 * 2018-1-9
 */
#ifndef QUEUE_H_
#define QUEUE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct queue{
	int* array;
	int head;
	int tail;
	int length;
};

typedef struct queue Queue;

/*
 * 对queue进行初始化，得到一个queue,
 * 但是应当注意到由于tail指向的位置
 * 不存储任何东西，所以满队列中会存
 * 在一个空位置，所以真正能存储的数
 * 据个数位length-1;销毁队列时要使用
 * 对应的queue_free函数
 *
 * length   队列的长度
 */
Queue* queue_init(int length);

/*
 * 释放queue的内存，销毁queue
 */
void queue_free(Queue *q);

/*
 * 判断队列是否为空
 * false 不为空
 * true  空队列
 */
bool isempty(Queue *q);

/*
 * 入队操作，若队列已满则操作失败
 */
void enqueue(Queue *q, int x);

/*
 * 离队操作，若队列为空则操作失败
 * return -1 表示队列为空 
 */
int dequeue(Queue *q);

/*
 * 测试pos对应的位置在队列中向后移动1位后
 * 的正确位置,实际上并没有真正的移动。
 * pos    目前的位置
 * length 队列的长度
 *
 * return
 * int    移动后对应的位置
 */
int add_one_test(int pos, int length);
#endif
