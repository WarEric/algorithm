/*
 * 红黑树头文件
 *
 * by wareric@163.com
 * 2018-04-19
 */
#ifndef RBTREE_H_
#define RBTREE_H_
#include<iostream>
#include<iomanip>
#include<stack>
#include"RBTNode.h"
using std::cout;
using std::endl;
using std::left;
using std::setw;
using std::stack;

template<typename T> class RBTree{
	public:
		RBTree():root(nil){}
		RBTree(const RBTree&);
		~RBTree();

		bool insert(T key);
		bool del(T key);

		RBTNode<T>* min();
		RBTNode<T>* min(RBTNode<T> *x);
		RBTNode<T>* max();
		RBTNode<T>* max(RBTNode<T> *x);
		RBTNode<T>* search(T key);
		RBTNode<T>* predecessor(RBTNode<T> *x);
		RBTNode<T>* successor(RBTNode<T> *x);

		void preorderTreeWalk();
		void preorderTreeWalk(RBTNode<T> *x);
		void inorderTreeWalk();
		void inorderTreeWalk(RBTNode<T> *x);
		void postorderTreeWalk();
		void postorderTreeWalk(RBTNode<T> *x);

		//delete all nodes
		bool destroy();
		//recursive copy
		RBTNode<T>* copy(RBTNode<T>* root);

		RBTree<T>& operator=(const RBTree &tree);
		bool operator==(const RBTree &tree);
		bool operator!=(const RBTree &tree);

		static RBTNode<T> *nil;
	private:
		bool insert(RBTNode<T> *node);
		void insertFixUp(RBTNode<T> *z);

		bool del(RBTNode<T> *node);
		void delFixUp(RBTNode<T> *x);
		//subtree of v repalces that of u
		void transplant(RBTNode<T> *u, RBTNode<T> *v);

		void leftRotate(RBTNode<T> *x);
		void rightRotate(RBTNode<T> *x);

		RBTNode<T> *root;
};

template<typename T>
RBTNode<T>* RBTree<T>::nil = new RBTNode<T>(0, BLACK);

template<typename T>
RBTree<T>::RBTree(const RBTree &orig)
{
	root = copy(orig.root);
}

template<typename T>
RBTree<T>::~RBTree()
{
	destroy();
}

template<typename T>
bool RBTree<T>::insert(T key)
{
	RBTNode<T> *node = new RBTNode<T>(key, RED);
	return insert(node);
}


template<typename T>
bool RBTree<T>::del(T key)
{
	RBTNode<T> *x = search(key);
	if(x == nil)
		return false;
	if(del(x) == true)
	{
		delete x;
		return true;
	}else
		return false;
}

template<typename T>
RBTNode<T>* RBTree<T>::min()
{
	RBTNode<T> *x = root;
	while(x->l != nil)
		x = x->l;
	return x;
}

template<typename T>
RBTNode<T>* RBTree<T>::min(RBTNode<T> *x)
{
	if(x == nullptr)
		return nil;
	while(x->l != nil)
		x = x->l;
	return x;
}

template<typename T>
RBTNode<T>* RBTree<T>::max()
{
	RBTNode<T> *x = root;
	while(x->r != nil)
		x = x->r;
	return x;
}

template<typename T>
RBTNode<T>* RBTree<T>::max(RBTNode<T> *x)
{
	if(x == nullptr)
		return nil;
	while(x->r != nil)
		x = x->r;
	return x;
}

template<typename T>
RBTNode<T>* RBTree<T>::search(T key)
{
	RBTNode<T> *x = root;
	while(x != nil)
	{
		if(x->getKey() == key)
			return x;
		else if(x->getKey() < key)
			x = x->r;
		else
			x = x->l;
	}
	return x;
}

template<typename T>
RBTNode<T>* RBTree<T>::predecessor(RBTNode<T> *x)
{
	if(x->l != nil)
		return max(x->l);
	RBTNode<T> *y = x->p;
	while(y != nil && x == y->l)
	{
		x = y;
		y = y->p;
	}
	return y;
}

template<typename T>
RBTNode<T>* RBTree<T>::successor(RBTNode<T> *x)
{
	if(x->r != nil)
		return min(x->r);
	RBTNode<T> *y = x->p;
	while(y != nil && x == y->r)
	{
		x = y;
		y = y->p;
	}
	return y;
}

template<typename T>
void RBTree<T>::preorderTreeWalk()
{
	RBTNode<T> *x = root;
	if(x != nil)
	{
		cout << left << "key = " << setw(4) << x->getKey() << " color =  "
			<< setw(8) << (x->getColor() == RED ? "RED":"BLACK") << endl;
		preorderTreeWalk(x->l);
		preorderTreeWalk(x->r);
	}
}

template<typename T>
void RBTree<T>::preorderTreeWalk(RBTNode<T> *x)
{
	if(x != nil)
	{
		cout << left << "key = " << setw(4) << x->getKey() << " color =  "
			<< setw(8) << (x->getColor() == RED ? "RED":"BLACK") << endl;
		preorderTreeWalk(x->l);
		preorderTreeWalk(x->r);
	}
}

template<typename T>
void RBTree<T>::inorderTreeWalk()
{
	RBTNode<T> *x = root;
	if(x != nil)
	{
		inorderTreeWalk(x->l);
		cout << left << "key = " << setw(4) << x->getKey() << " color =  "
			<< setw(8) << (x->getColor() == RED ? "RED":"BLACK") << endl;
		inorderTreeWalk(x->r);
	}
}

template<typename T>
void RBTree<T>::inorderTreeWalk(RBTNode<T> *x)
{
	if(x != nil)
	{
		inorderTreeWalk(x->l);
		cout << left << "key = " << setw(4) << x->getKey() << " color =  "
			<< setw(8) << (x->getColor() == RED ? "RED":"BLACK") << endl;
		inorderTreeWalk(x->r);
	}
}

template<typename T>
void RBTree<T>::postorderTreeWalk()
{
	RBTNode<T> *x = root;
	if(x != nil)
	{
		postorderTreeWalk(x->l);
		postorderTreeWalk(x->r);
		cout << left << "key = " << setw(4) << x->getKey() << " color =  "
			<< setw(8) << (x->getColor() == RED ? "RED":"BLACK") << endl;
	}
}

template<typename T>
void RBTree<T>::postorderTreeWalk(RBTNode<T> *x)
{
	if(x != nil)
	{
		postorderTreeWalk(x->l);
		postorderTreeWalk(x->r);
		cout << left << "key = " << setw(4) << x->getKey() << " color =  "
			<< setw(8) << (x->getColor() == RED ? "RED":"BLACK") << endl;
	}
}

template<typename T>
bool RBTree<T>::destroy()
{
	
	if(root == nil)
		return true;

	RBTNode<T> *rt = root;
	stack<RBTNode<T> *> stk;
	stk.push(rt);

	while(!stk.empty())
	{
		RBTNode<T> *ptr = stk.top();
		stk.pop();

		if(ptr->r != nil)
			stk.push(ptr->r);
		if(ptr->l != nil)
			stk.push(ptr->l);
		delete ptr;
	}
	root = nil;
	return true;
}

template<typename T>
RBTNode<T>* RBTree<T>::copy(RBTNode<T> *root)
{
	RBTNode<T> *node = nil;
	RBTNode<T> *left = nil;
	RBTNode<T> *right = nil;

	if(root == nil)
		return nil;
	if(root->l != nil)
		left = copy(root->l);
	if(root->r != nil)
		right = copy(root->r);

	node = new RBTNode<T>(root->getKey(), root->getColor(), nil, left, right);

	if(left != nil)
		left->p = node;
	if(right != nil)
		right->p = node;

	return node;
}

template<typename T>
RBTree<T>& RBTree<T>::operator=(const RBTree &orig)
{
	destroy();
	root = copy(orig.root);
}

template<typename T>
bool RBTree<T>::operator==(const RBTree &dst)
{
	stack<RBTNode<T> *> stkd, stks;
	RBTNode<T> *d = dst.root;
	RBTNode<T> *s = root;
	if(d == nil)
	{
		if(s == nil)
			return true;
		else
			return false;
	}else{
		if(s ==  nil)
			return false;
	}

	stkd.push(d);
	stks.push(s);
	while((!stkd.empty()) && (!stks.empty()))
	{
		d = stkd.top();
		stkd.pop();

		s = stks.top();
		stks.pop();

		if(*d != *s)
			return false;

		if(d->r != nil)
			stkd.push(d->r);
		if(d->l != nil)
			stkd.push(d->l);

		if(s->r != nil)
			stks.push(s->r);
		if(s->l != nil)
			stks.push(s->l);
	}

	//both equal to zero
	if(stkd.size() != stks.size())
		return false;
	return true;
}

template<typename T>
bool RBTree<T>::operator!=(const RBTree &tree)
{
	return !(*this == tree);
}

template<typename T>
bool RBTree<T>::insert(RBTNode<T> *z)
{
	RBTNode<T> *y = nil;
	RBTNode<T> *x = root;
	while(x != nil)
	{
		y = x;
		if(z->getKey() < x->getKey())
			x = x->l;
		else
			x = x->r;
	}
	z->p = y;
	if(y == nil)
		root = z;
	else if(z->getKey() < y->getKey())
		y->l = z;
	else
		y->r = z;
	z->l = nil;
	z->r = nil;
	z->setColor(RED);
	insertFixUp(z);
	return true;
}

template<typename T>
void RBTree<T>::insertFixUp(RBTNode<T> *z)
{
	while(z->p->getColor() == RED)
	{
		if(z->p == z->p->p->l)
		{
			RBTNode<T> *y = z->p->p->r;
			if(y->getColor() == RED)				//case 1
			{
				z->p->setColor(BLACK);
				y->setColor(BLACK);
				z->p->p->setColor(RED);
				z = z->p->p;
			}else{
				if(z == z->p->r)				//case 2
				{
					z = z->p;
					leftRotate(z);
				}
				z->p->setColor(BLACK);				//case 3
				z->p->p->setColor(RED);
				rightRotate(z->p->p);
			}
		}else{									
			RBTNode<T> *y = z->p->p->l;
			if(y->getColor() == RED)				//case 1
			{
				z->p->setColor(BLACK);
				y->setColor(BLACK);
				z->p->p->setColor(RED);
				z = z->p->p;
			}else{
				if(z == z->p->l)				//case 2
				{
					z = z->p;
					rightRotate(z);
				}
				z->p->setColor(BLACK);				//case 3
				z->p->p->setColor(RED);
				leftRotate(z->p->p);
			}
		}

	}
	root->setColor(BLACK);
}

template<typename T>
bool RBTree<T>::del(RBTNode<T> *z)
{
	RBTNode<T> *y = z;
	RBTNode<T> *x;
	Color y_original_color = y->getColor();
	if(z->l == nil)
	{
		x = z->r;
		transplant(z, z->r);	
	}else if(z->r == nil){
		x = z->l;
		transplant(z, z->l);	
	}else{
		y = min(z->r);	
		y_original_color = y->getColor();
		x = y->r;
		if(y->p == z)
		{	
			x->p = y;
		}else{
			transplant(y, y->r);
			y->r = z->r;
			y->r->p = y;
		}
		transplant(z, y);
		y->l = z->l;
		y->l->p = y;
		y->setColor(z->getColor());
	}

	if(y_original_color == BLACK)
		delFixUp(x);
	return true;
}

template<typename T>
void RBTree<T>::delFixUp(RBTNode<T> *x)
{
	while(x != root && x->getColor() == BLACK)
	{
		if(x == x->p->l)
		{
			RBTNode<T> *w = x->p->r;
			if(w->getColor() == RED)				//case 1
			{
				w->setColor(BLACK);
				x->p->setColor(RED);
				leftRotate(x->p);
				w = x->p->r;
			}

			if(w->l->getColor() == BLACK 
					&& w->r->getColor() == BLACK)		//case 2
			{
				w->setColor(RED);
				x = x->p;
			}else{
				if(w->r->getColor() == BLACK)			//case 3
				{
					w->l->setColor(BLACK);
					w->setColor(RED);
					rightRotate(w);
					w = x->p->r;
				}
				w->setColor(x->p->getColor());			//case 4
				x->p->setColor(BLACK);
				w->r->setColor(BLACK);
				leftRotate(x->p);
				x = root;
			}
		}else{
			RBTNode<T> *w = x->p->l;
			if(w->getColor() == RED)				//case 1
			{
				w->setColor(BLACK);
				x->p->setColor(RED);
				rightRotate(x->p);
				w = x->p->l;
			}

			if(w->l->getColor() == BLACK 
					&& w->r->getColor() == BLACK)		//case 2
			{
				w->setColor(RED);
				x = x->p;
			}else{
				if(w->l->getColor() == BLACK)			//case 3
				{
					w->r->setColor(BLACK);
					w->setColor(RED);
					leftRotate(w);
					w = x->p->l;
				}
				w->setColor(x->p->getColor());			//case 4
				x->p->setColor(BLACK);
				w->l->setColor(BLACK);
				rightRotate(x->p);
				x = root;
			}
		}
	}
	x->setColor(BLACK);
}

template<typename T>
void RBTree<T>::transplant(RBTNode<T> *u, RBTNode<T> *v)
{
	if(u->p == nil)
		root = v;
	else if(u == u->p->l)
		u->p->l = v;
	else
		u->p->r = v;
	v->p = u->p;
}


template<typename T>
void RBTree<T>::leftRotate(RBTNode<T> *x)
{
	RBTNode<T> *y = x->r;
	x->r = y->l;
	if(y->l != nil)
		y->l->p = x;
	y->p = x->p;
	if(x->p == nil)
		root = y;
	else if(x == x->p->l)
		x->p->l = y;
	else
		x->p->r = y;
	y->l = x;
	x->p = y;
}

template<typename T>
void RBTree<T>::rightRotate(RBTNode<T> *x)
{
	RBTNode<T> *y = x->l;
	x->l = y->r;
	if(y->r != nil)
		y->r->p = x;
	y->p = x->p;
	if(x->p == nil)
		root = y;
	else if(x == x->p->r)
		x->p->r = y;
	else
		x->p->l = y;
	y->r = x;
	x->p = y;
}

#endif
