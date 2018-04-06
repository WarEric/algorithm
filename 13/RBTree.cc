/*
 * 红黑树数据结构树相关的成员函数和非成员函数的实现.
 *
 * by wareric@163.com
 * 2018-04-06 
 */
#include<iostream>
#include<limits.h>
#include<string>
#include<iomanip>
#include"RBTree.h"
#include"Node.h"

using std::string;
using std::cout;
using std::endl;
using std::left;
using std::setw;

RBTree::RBTree()
{
	this->nil = new Node(INT_MIN, BLACK, NULL, NULL, NULL);//默认取最小值
	root = nil;
}

RBTree::RBTree(Node *root)
{
	this->nil = new Node(INT_MIN, BLACK, NULL, NULL, NULL);//默认取最小值
	this->root = root;
	this->root->parent = nil;
	this->root->left = nil;
	this->root->right = nil;
}

Node* treeMinmum(Node *x, Node *nil)
{
	while(x->left != nil)
		x = x->left;
	return x;
}

Node* rbFind(RBTree *T, int key)
{
	if(T->root == T->getNil()) return T->getNil();

	Node *cur = T->root;
	while(cur != T->getNil())
	{
		if(cur->getKey() == key)
			break;
		else if(cur->getKey() < key)
			cur = cur->right;
		else
			cur = cur->left;
	}

	return cur;
}

void leftRotate(RBTree *T, Node *x)
{
	Node *y = x->right;
	x->right = y->left;

	if(y->left != T->getNil())
		y->left->parent = x;
	y->parent = x->parent;

	if(x->parent == T->getNil())
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

	if(y->right != T->getNil())
		y->right->parent = x;
	y->parent = x->parent;

	if(x->parent == T->getNil())
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
	Node *z = new Node(key, RED);
	rbInsert(T, z);
}

void rbInsert(RBTree *T, Node *z)
{
	Node *y = T->getNil();
	Node *x = T->root;
	while(x != T->getNil())
	{
		y = x;
		if(z->getKey() < x->getKey())
			x = x->left;
		else
			x = x->right;
	}
	z->parent = y;
	if(y == T->getNil())
		T->root = z;
	else if(z->getKey() < y->getKey())
		y->left = z;
	else
		y->right = z;
	z->left = T->getNil();
	z->right = T->getNil();
	z->setColor(RED);
	rbInsertFixUp(T, z);
}

void rbInsertFixUp(RBTree *T, Node *z)
{
	while(z->parent->getColor() == RED)
	{
		if(z->parent == z->parent->parent->left)
		{
			Node *y = z->parent->parent->right;
			if(y->getColor() == RED)				//case 1
			{
				z->parent->setColor(BLACK);
				y->setColor(BLACK);
				z->parent->parent->setColor(RED);
				z = z->parent->parent;
			}else{
				if(z == z->parent->right)			//case 2
				{
					z = z->parent;
					leftRotate(T, z);
				}
				z->parent->setColor(BLACK);		//case 3
				z->parent->parent->setColor(RED);
				rightRotate(T, z->parent->parent);
			}
		}else{									
			Node *y = z->parent->parent->left;
			if(y->getColor() == RED)				//case 1
			{
				z->parent->setColor(BLACK);
				y->setColor(BLACK);
				z->parent->parent->setColor(RED);
				z = z->parent->parent;
			}else{
				if(z == z->parent->left)			//case 2
				{
					z = z->parent;
					rightRotate(T, z);
				}
				z->parent->setColor(BLACK);		//case 3
				z->parent->parent->setColor(RED);
				leftRotate(T, z->parent->parent);
			}
		}

	}
	T->root->setColor(BLACK);
}

void rbDeleteKey(RBTree *T, const int key)
{
	Node* it = rbFind(T, key);
	if(it == T->getNil()) return;
	else rbDelete(T, it);

}

void rbDelete(RBTree *T, Node *z)
{
	Node *y = z;
	Node *x;
	string y_original_color = y->getColor();
	if(z->left == T->getNil())
	{
		x = z->right;
		rbTransplant(T, z, z->right);	
	}else if(z->right == T->getNil()){
		x = z->left;
		rbTransplant(T, z, z->left);	
	}else{
		y = treeMinmum(z->right, T->getNil());	
		y_original_color = y->getColor();
		x = y->right;
		if(y->parent == z)
		{	
			x->parent = y;
		}else{
			rbTransplant(T, y, y->right);
			y->right = z->right;
			y->right->parent = y;
		}
		rbTransplant(T, z, y);
		y->left = z->left;
		y->left->parent = y;
		y->setColor(z->getColor());
	}
	delete z;

	if(y_original_color == BLACK)
		rbDeleteFixUp(T, x);
}

void rbTransplant(RBTree *T, Node *u, Node *v)
{
	if(u->parent == T->getNil())
		T->root = v;
	else if(u == u->parent->left)
		u->parent->left = v;
	else
		u->parent->right = v;
	v->parent = u->parent;
}

void rbDeleteFixUp(RBTree *T, Node *x)
{
	while(x != T->root && x->getColor() == BLACK)
	{
		if(x == x->parent->left)
		{
			Node *w = x->parent->right;
			if(w->getColor() == RED)				//case 1
			{
				w->setColor(BLACK);
				x->parent->setColor(RED);
				leftRotate(T, x->parent);
				w = x->parent->right;
			}

			if(w->left->getColor() == BLACK 
					&& w->right->getColor() == BLACK)	//case 2
			{
				w->setColor(RED);
				x = x->parent;
			}else{
				if(w->right->getColor() == BLACK)			//case 3
				{
					w->left->setColor(BLACK);
					w->setColor(RED);
					rightRotate(T, w);
					w = x->parent->right;
				}
				w->setColor(x->parent->getColor());			//case 4
				x->parent->setColor(BLACK);
				w->right->setColor(BLACK);
				leftRotate(T, x->parent);
				x = T->root;
			}
		}else{
			Node *w = x->parent->left;
			if(w->getColor() == RED)				//case 1
			{
				w->setColor(BLACK);
				x->parent->setColor(RED);
				rightRotate(T, x->parent);
				w = x->parent->left;
			}

			if(w->left->getColor() == BLACK 
					&& w->right->getColor() == BLACK)	//case 2
			{
				w->setColor(RED);
				x = x->parent;
			}else{
				if(w->left->getColor() == BLACK)			//case 3
				{
					w->right->setColor(BLACK);
					w->setColor(RED);
					leftRotate(T, w);
					w = x->parent->left;
				}
				w->setColor(x->parent->getColor());			//case 4
				x->parent->setColor(BLACK);
				w->left->setColor(BLACK);
				rightRotate(T, x->parent);
				x = T->root;
			}
		}
	}

	x->setColor(BLACK);
}

void inorderTreeWalk(Node *x, const Node *nil)
{
	if(x != nil)
	{
		inorderTreeWalk(x->left, nil);
		cout << left << "key = " << setw(4) << x->getKey() << " color = "
		       	<< setw(8) << x->getColor() << endl;
		inorderTreeWalk(x->right, nil);
	}
}
