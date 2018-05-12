/*
 * 链表相关操作的实现，该链表中有哨兵
 * by wareric@163.com
 * 2018-1-9
 */
#include "linkedlist.h"

LinkedList* list_init()
{
	LinkedList *l;
	l = malloc(sizeof(LinkedList));
	l->nil = malloc(sizeof(Node));
	l->nil->pre = l->nil;
	l->nil->next = l->nil;
	return l;
}

/*
 * 由于是双向链表且循环，所以第一步
 * 先将nil的上一个node->next置为null，
 * 破坏了链表的循环性之后才能删除，
 * 否则删除操作不知道何时结束
 */
void list_free(LinkedList *l)
{
	Node *ptr, *temp;
	ptr = l->nil;
	temp = ptr->next;
	l->nil->pre->next = NULL;

	for(; ptr != NULL; ptr = temp->next, temp = temp->next)
		free(ptr);

	free(l);
}

Node* list_node_entry(int key)
{
	Node *p = malloc(sizeof(Node));
	p->key = key;
	return p;
}

Node* list_search(LinkedList *l, int k)
{
	Node* ptr;
	ptr = l->nil->next;
	l->nil->key = k;
	while(k != (ptr->key))
	
		ptr = ptr->next;
	if(ptr == l->nil)
		return NULL;
	else
		return ptr;
}

void list_insert(LinkedList *l, Node *x)
{
	x->next = l->nil->next;
	l->nil->next->pre = x;
	l->nil->next = x;
	x->pre = l->nil;
}

void list_delete(LinkedList *l, Node *x)
{
	x->pre->next = x->next;
	x->next->pre = x->pre;
	free(x);
}
