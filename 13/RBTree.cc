#include <limits.h>
#include<string>
#include "RBTree.h"
#include "Node.h"

using std::string;

RBTree::RBTree()
{
	this->nil = new Node(INT_MIN, string("BLACK"), NULL, NULL, NULL);//默认取最小值
}

void leftRotate(RBTree *T, Node *x)
{
	Node *y = x->right;
	x->right = y->left;

	if(y->left != T->nil)
		y->left->parent = x;
	y->parent = x->parent;

	if(x->parent == T->nil)
		T->root = y;
	else if(x == x->parent->left)
		x->parent->left = y;
	else
		x->parent->right = y;

	y->left = x;
	x->parent = y;
}

void rightRotate(RBTree *T, Node *x)
{
	Node *y = x->left;
	x->left = y->right;

	if(y->right != T->nil)
		y->right->parent = x;
	y->parent = x->parent;

	if(x->parent == T->nil)
		T->root = y;
	else if(x == x->parent->right)
		x->parent->right = y;
	else
		x->parent->left = y;

	y->right = x;
	x->parent = y;
}

void rbInsertKey(RBTree *T, const int key)
{
	Node *z = new Node(key,string("RED"));
	rbInsert(T, z);
}

void rbInsert(RBTree *T, Node *z)
{
	Node *y = T->nil;
	x = T->root;
	while(x != T.nil)
	{
		y = x;
		if(z->key < x->key)
			x = x->left;
		else
			x = x->right;
	}
	z->parent = y;
	if(y == T.nil)
		T->root = z;
	else if(z->key < y->key)
		y->left = z;
	else
		y->right = z;
	z->left = T->nil;
	z->right = T->nil;
	z->setColor(string("RED"));
	rbInsertFixUp(T, z);
}

void rbInsertFixUp(RBTree *T, Node *z)
{
	while(z->parent->getColor() == string("RED"))
	{
		if(z->parent == z->parent->parent->left)
		{
			y = z->parent->parent->right;
			if(y.getColor == string("RED"))				//case 1
			{
				z->parent->setColor(string("BLACK"));
				y->setColor(string("BLACK"));
				z->parent->parent->setColor(string("RED"));
				z = z->parent->parent;
			}else{
				if(z == z->parent->right)			//case 2
				{
					z = z->parent;
					leftRotate(T, z);
				}
				z->parent->setColor(string("BLACK"));		//case 3
				z->parent->parent->setColor(string("RED"));
				rightRotate(T, z->parent->parent);
			}
		}else{								//还未检查是否正确
			y = z->parent->parent->left;
			if(y.getColor == string("RED"))				//case 1
			{
				z->parent->setColor(string("BLACK"));
				y->setColor(string("BLACK"));
				z->parent->parent->setColor(string("RED"));
				z = z->parent->parent;
			}else{
				if(z == z->parent->left)			//case 2
				{
					z = z->parent;
					rightRotate(T, z);
				}
				z->parent->setColor(string("BLACK"));		//case 3
				z->parent->parent->setColor(string("RED"));
				leftRotate(T, z->parent->parent);
			}
		}

	}
	T->root->setColor(string("BLACK"));
}
