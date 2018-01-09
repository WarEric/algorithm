/*
 * 链表相关的头文件和操作函数声明，
 * 该链表引入了哨兵，同时所有的节
 * 点内存在堆上分配;产生和销毁节点
 * 时一定要使用头文件提供的函数，切
 * 记不可自己操作。
 * by wareric@163.com
 * 2018-1-9
 */
#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct node		Node;
typedef struct linkedlist	LinkedList;

struct linkedlist{
	Node* nil;
};

struct node{
	int key;
	Node* pre;
	Node* next;
};

/*
 * 初始化一个空链表，里面只有一个哨兵
 */
LinkedList* list_init();

/*
 * 释放链表，切记链表中的node不能自己随意销毁
 * 要利用头文件里提供函数去销毁，因为free要释
 * 放整个链表的内存，若有一部分缺失会导致出错
 *
 * l    要销毁的链表
 */
void list_free(LinkedList *l);

/*
 * 用来产生一个新的Node，新节点的产生一定要由
 * 头文件里的函数产生，因为这个Node是分配在堆
 * 上的，最后要进行内存的回收
 * key    要产生的Node对应的key值
 *
 * return 
 * Node*  新产生的Node对应的指针
 */
Node* list_node_entry(int key);

/*
 * 查找对应的key等于k的节点，并返回该节点的指针，
 * 若是没有找到则返回NULL
 * l      要查找的链表
 * k      要查询的关键字
 *
 * return
 * Node*  查询得到的节点对应的指针，若没找到则返回NULL
 */
Node* list_search(LinkedList *l, int k);

/*
 * 向list的首部插入一个元素，该元素应该是由
 * entry函数产生的
 * l      要插入的链表
 * x      要插入的节点对应的指针
 */
void list_insert(LinkedList *l, Node *x);

/*
 * 删除链表中的元素，回收其内存，所以x指针不能
 * 再进行使用
 * l      要删除的链表
 * x      要删除节点对应的指针
 */
void list_delete(LinkedList *l, Node *x);
#endif
