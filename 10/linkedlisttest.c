/*
 * 用来对链表结构进行测试
 * by wareric@163.com
 */
#include <stdio.h>
#include "linkedlist.h"

int main()
{
	LinkedList *l;
	l = list_init();

	printf("向list中插入 1\n");
	list_insert(l, list_node_entry(1));
	printf("向list中插入 2\n");
	list_insert(l, list_node_entry(2));
	printf("向list中插入 3\n");
	list_insert(l, list_node_entry(3));

	printf("\n查询2\n");
	Node* x = list_search(l, 2);
	if(x == NULL)
		printf("x.key==2 不存在\n");
	else
		printf("x.key = %d\n", x->key);

	printf("\n删除2\n");
	list_delete(l, x);
	printf("\n查询2\n");
	x = list_search(l, 2);
	if(x == NULL)
		printf("x.key==2 不存在\n");
	else
		printf("x.key = %d\n", x->key);

	list_free(l);

	return 0;
}
