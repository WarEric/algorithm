/*
 * 二叉树相关操作的实现
 * by wareric@163.com
 * 2018-3-17
 */
#include<stdio.h>
#include"mytree.h"

void	tree_insert(T *t, Node *z)
{
	Node *pre = NULL, *cur = t->root;
	while(cur != NULL)
	{
		pre = cur;
		if(z->key <  cur->key)
			cur = cur->left;
		else
			cur = cur->right;
	}

	z->parent = pre;
	if(pre == NULL)
		t->root = z;
	else if(z->key < pre->key)
		pre->left = z;
	else
		pre->right = z;
}

Node*	iterative_tree_search(Node *x, int key)
{
	while( (x != NULL) && (key != x->key) )
	{
		if(key < x->key)
			x = x->left;
		else
			x = x->right;
	}
	return x;
}

Node*	tree_search(Node *x, int key)
{
	if( (x == NULL) || (key == x->key) )
		return x;
	if(key < x->key)
		return tree_search(x->left, key);
	else
		return tree_search(x->right, key);
}

void	inorder_tree_walk(Node *x)
{
	if(x != NULL)
	{
		inorder_tree_walk(x->left);
		printf("%d\n", x->key);
		inorder_tree_walk(x->right);
	}
}

Node*	tree_minimum(Node *x)
{
	while(x->left != NULL)
		x = x->left;
	return x;
}

Node*	tree_maximum(Node *x)
{
	while(x->right != NULL)
		x = x->right;
	return x;
}

Node*	tree_successor(Node *x)
{
	if(x->right != NULL)
		return tree_minimum(x->right);
	Node *y = x->parent;
	while((y != NULL) && (x == y->right))
	{
		x = y;
		y = y->parent;
	}
	return y;
}

Node*	tree_predecessor(Node *x)
{
	if(x->left != NULL)
		return tree_maximum(x->left);
	Node *y = x->parent;
	while((y != NULL) && (x == y->left))
	{
		x = y;
		y = y->parent;
	}
	return y;
}

void	transplant(T *t, Node *u, Node *v)
{
	if(u->parent == NULL)
		t->root = v;
	else if(u == u->parent->left)
		u->parent->left = v;
	else
		u->parent->right = v;

	if(v != NULL)
		v->parent = u->parent;
}

void	tree_delete(T *t, Node *z)
{
	if(z->left == NULL)
		transplant(t, z, z->right);
	else if(z->right == NULL)
		transplant(t, z, z->left);
	else
	{
		Node *y = tree_minimum(z->right);
		if(y->parent != z)
		{
			transplant(t, y, y->right);
			y->right = z->right;
			y->right->parent = y;
		}
		transplant(t, z, y);
		y->left = z->left;
		y->left->parent = y;
	}
}
