/*
 * 用来测试二叉树的相关函数是否写的正确
 * by wareric@163.com
 * 2018-3-17
 */
#include<stdio.h>
#include<stdlib.h>
#include"mytree.h"

int main(void)
{
	T t;
	t.root = NULL;

	Node *ptr;
	Node *res;
	int test[] = {1, 32, 2, 41, 51, 4, 52};
	int i;
	for(i = 0; i < 7; i++)
	{
		ptr = malloc(sizeof(Node));
		ptr->key = test[i];
		ptr->parent = NULL;
		ptr->left = NULL;
		ptr->right = NULL;
		tree_insert(&t, ptr);
	}

	printf("二叉树的原始数据:\n");
	inorder_tree_walk(t.root);

	printf("\n------查找51是否在二叉树中------\n");
	res = tree_search(t.root, 51);
	if(res != NULL)
		printf("递归查找：51在二叉树中\n");
	else
		printf("递归查找：51不在二叉树中\n");
	res = iterative_tree_search(t.root, 51);
	if(res != NULL)
		printf("循环查找：51在二叉树中\n");
	else
		printf("循环查找：51不在二叉树中\n");

	printf("\n------查找40是否在二叉树中------\n");
	res = tree_search(t.root, 40);
	if(res != NULL)
		printf("递归查找：40在二叉树中\n");
	else
		printf("递归查找：40不在二叉树中\n");
	res = iterative_tree_search(t.root, 40);
	if(res != NULL)
		printf("循环查找：40在二叉树中\n");
	else
		printf("循环查找：40不在二叉树中\n");

	printf("\n开始查找最小元素\n");
	res = tree_minimum(t.root);
	if(res != NULL)
		printf("二叉树中最小的值为%d\n", res->key);
	else
		printf("二叉树为空\n");

	printf("\n开始查找最大元素\n");
	res = tree_maximum(t.root);
	if(res != NULL)
		printf("二叉树中最大的值为%d\n", res->key);
	else
		printf("二叉树为空\n");

	printf("\n查找41的后继\n");
	res = tree_successor(tree_search(t.root, 41));
	if(res != NULL)
		printf("41的后继为%d\n", res->key);
	else
		printf("41没有后继\n");
	
	printf("\n查找41的前驱\n");
	res = tree_predecessor(tree_search(t.root, 41));
	if(res != NULL)
		printf("41的前驱为%d\n", res->key);
	else
		printf("41没有前驱\n");

	printf("\n删除节点41\n");
	tree_delete(&t, tree_search(t.root,41));
	printf("二叉树删除41后:\n");
	inorder_tree_walk(t.root);

	return 0;
}
