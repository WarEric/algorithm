/*
 * 桶排序所需要的数据结构
 * 主要是一个桶的链表结构
 * 这个链表实现的不好，
 * 应该用双向链表加哨兵
 * by wareric@163.com
 * 2018-1-8
 */
#ifndef __BUCKET__H
#define __BUCKET__H

typedef struct	bucket	Bucket;
typedef struct	data	Node;

struct data{
	int	num;
	Node*	next;
};

struct bucket{
	Node*	head;
	Node*	tail;
};

#endif
