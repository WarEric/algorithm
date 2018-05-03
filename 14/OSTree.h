/*
 * 顺序统计树的头文件，还是沿用模板的实现方式
 * by wareric@163.com
 * 2018-05-03
 */
#ifndef OSTREE_H_
#define OSTREE_H_
#include<iostream>
#include<iomanip>
#include<stack>
#include"OSTNode.h"
using std::cout;
using std::endl;
using std::left;
using std::setw;
using std::stack;

template<typename T> class OSTree{
	public:
		OSTree():root(nil){}
		OSTree(const OSTree&);
		~OSTree();

		bool insert(T key);
		bool del(T key);
		OSTNode<T>* select(int i);
		OSTNode<T>* select(OSTNode<T> *x, int i);
		int rank(OSTNode<T> *x);

		OSTNode<T>* min();
		OSTNode<T>* min(OSTNode<T> *x);
		OSTNode<T>* max();
		OSTNode<T>* max(OSTNode<T> *x);
		OSTNode<T>* search(T key);
		OSTNode<T>* predecessor(OSTNode<T> *x);
		OSTNode<T>* successor(OSTNode<T> *x);

		void preorderTreeWalk();
		void preorderTreeWalk(OSTNode<T> *x);
		void inorderTreeWalk();
		void inorderTreeWalk(OSTNode<T> *x);
		void postorderTreeWalk();
		void postorderTreeWalk(OSTNode<T> *x);

		//delete all nodes
		bool destroy();
		//recursive copy
		OSTNode<T>* copy(OSTNode<T>* root);

		OSTree<T>& operator=(const OSTree &tree);
		bool operator==(const OSTree &tree);
		bool operator!=(const OSTree &tree);

		static OSTNode<T> *nil;
	private:
		bool insert(OSTNode<T> *node);
		void insertFixUp(OSTNode<T> *z);

		bool del(OSTNode<T> *node);
		void delFixUp(OSTNode<T> *x);
		//subtree of v repalces that of u
		void transplant(OSTNode<T> *u, OSTNode<T> *v);

		void leftRotate(OSTNode<T> *x);
		void rightRotate(OSTNode<T> *x);

		OSTNode<T> *root;
};

template<typename T>
OSTNode<T>* OSTree<T>::nil = new OSTNode<T>(0, BLACK);

template<typename T>
OSTree<T>::OSTree(const OSTree &orig)
{
	root = copy(orig.root);
}

template<typename T>
OSTree<T>::~OSTree()
{
	destroy();
}

template<typename T>
bool OSTree<T>::insert(T key)
{
	OSTNode<T> *node = new OSTNode<T>(key, RED, 1);
	return insert(node);
}


template<typename T>
bool OSTree<T>::del(T key)
{
	OSTNode<T> *x = search(key);
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
OSTNode<T>* OSTree<T>::select(int i)
{
	return select(root, i);
}

template<typename T>
OSTNode<T>* OSTree<T>::select(OSTNode<T> *x, int i)
{
	if(x == nullptr) return nil;
	if( (i <= 0) || (i > x->getSize()) )
		return nil;

	int r = x->l->getSize() + 1;
	if(i == r)
		return x;
	else if(i < r)
		return select(x->l, i);
	else
		return select(x->r, i-r);

}

template<typename T>
int OSTree<T>::rank(OSTNode<T> *x)
{
	int r = x->l->getSize() + 1;
	OSTNode<T> *y = x;
	while(y != root)
	{
		if(y == y->p->r)
			r += y->p->l->getSize() + 1;
		y = y->p;
	}
	return r;
}

template<typename T>
OSTNode<T>* OSTree<T>::min()
{
	OSTNode<T> *x = root;
	while(x->l != nil)
		x = x->l;
	return x;
}

template<typename T>
OSTNode<T>* OSTree<T>::min(OSTNode<T> *x)
{
	if(x == nullptr)
		return nil;
	while(x->l != nil)
		x = x->l;
	return x;
}

template<typename T>
OSTNode<T>* OSTree<T>::max()
{
	OSTNode<T> *x = root;
	while(x->r != nil)
		x = x->r;
	return x;
}

template<typename T>
OSTNode<T>* OSTree<T>::max(OSTNode<T> *x)
{
	if(x == nullptr)
		return nil;
	while(x->r != nil)
		x = x->r;
	return x;
}

template<typename T>
OSTNode<T>* OSTree<T>::search(T key)
{
	OSTNode<T> *x = root;
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
OSTNode<T>* OSTree<T>::predecessor(OSTNode<T> *x)
{
	if(x->l != nil)
		return max(x->l);
	OSTNode<T> *y = x->p;
	while(y != nil && x == y->l)
	{
		x = y;
		y = y->p;
	}
	return y;
}

template<typename T>
OSTNode<T>* OSTree<T>::successor(OSTNode<T> *x)
{
	if(x->r != nil)
		return min(x->r);
	OSTNode<T> *y = x->p;
	while(y != nil && x == y->r)
	{
		x = y;
		y = y->p;
	}
	return y;
}

template<typename T>
void OSTree<T>::preorderTreeWalk()
{
	OSTNode<T> *x = root;
	if(x != nil)
	{
		cout << left << "key = " << setw(4) << x->getKey() << " color =  "
			<< setw(8) << (x->getColor() == RED ? "RED":"BLACK") 
			<< "  size =  " << setw(4) << x->getSize() << endl;
		preorderTreeWalk(x->l);
		preorderTreeWalk(x->r);
	}
}

template<typename T>
void OSTree<T>::preorderTreeWalk(OSTNode<T> *x)
{
	if(x != nil)
	{
		cout << left << "key = " << setw(4) << x->getKey() << " color =  "
			<< setw(8) << (x->getColor() == RED ? "RED":"BLACK")
			<< "  size =  " << setw(4) << x->getSize() << endl;
		preorderTreeWalk(x->l);
		preorderTreeWalk(x->r);
	}
}

template<typename T>
void OSTree<T>::inorderTreeWalk()
{
	OSTNode<T> *x = root;
	if(x != nil)
	{
		inorderTreeWalk(x->l);
		cout << left << "key = " << setw(4) << x->getKey() << " color =  "
			<< setw(8) << (x->getColor() == RED ? "RED":"BLACK")
			<< "  size =  " << setw(4) << x->getSize() << endl;
		inorderTreeWalk(x->r);
	}
}

template<typename T>
void OSTree<T>::inorderTreeWalk(OSTNode<T> *x)
{
	if(x != nil)
	{
		inorderTreeWalk(x->l);
		cout << left << "key = " << setw(4) << x->getKey() << " color =  "
			<< setw(8) << (x->getColor() == RED ? "RED":"BLACK")
			<< "  size =  " << setw(4) << x->getSize() << endl;
		inorderTreeWalk(x->r);
	}
}

template<typename T>
void OSTree<T>::postorderTreeWalk()
{
	OSTNode<T> *x = root;
	if(x != nil)
	{
		postorderTreeWalk(x->l);
		postorderTreeWalk(x->r);
		cout << left << "key = " << setw(4) << x->getKey() << " color =  "
			<< setw(8) << (x->getColor() == RED ? "RED":"BLACK")
			<< "  size =  " << setw(4) << x->getSize() << endl;
	}
}

template<typename T>
void OSTree<T>::postorderTreeWalk(OSTNode<T> *x)
{
	if(x != nil)
	{
		postorderTreeWalk(x->l);
		postorderTreeWalk(x->r);
		cout << left << "key = " << setw(4) << x->getKey() << " color =  "
			<< setw(8) << (x->getColor() == RED ? "RED":"BLACK")
			<< "  size =  " << setw(4) << x->getSize() << endl;
	}
}

template<typename T>
bool OSTree<T>::destroy()
{
	
	if(root == nil)
		return true;

	OSTNode<T> *rt = root;
	stack<OSTNode<T> *> stk;
	stk.push(rt);

	while(!stk.empty())
	{
		OSTNode<T> *ptr = stk.top();
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
OSTNode<T>* OSTree<T>::copy(OSTNode<T> *root)
{
	OSTNode<T> *node = nil;
	OSTNode<T> *left = nil;
	OSTNode<T> *right = nil;

	if(root == nil)
		return nil;
	if(root->l != nil)
		left = copy(root->l);
	if(root->r != nil)
		right = copy(root->r);

	node = new OSTNode<T>(root->getKey(), root->getColor(), root->getSize(), nil, left, right);

	if(left != nil)
		left->p = node;
	if(right != nil)
		right->p = node;

	return node;
}

template<typename T>
OSTree<T>& OSTree<T>::operator=(const OSTree &orig)
{
	destroy();
	root = copy(orig.root);
}

template<typename T>
bool OSTree<T>::operator==(const OSTree &dst)
{
	stack<OSTNode<T> *> stkd, stks;
	OSTNode<T> *d = dst.root;
	OSTNode<T> *s = root;
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
bool OSTree<T>::operator!=(const OSTree &tree)
{
	return !(*this == tree);
}

template<typename T>
bool OSTree<T>::insert(OSTNode<T> *z)
{
	OSTNode<T> *y = nil;
	OSTNode<T> *x = root;
	while(x != nil)
	{
		y = x;
		if(z->getKey() < x->getKey())a
		{
			x->setSize( x->getSize() + 1 );
			x = x->l;
		}else{
			x->setSize( x->getSize() + 1 );
			x = x->r;
		}
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
void OSTree<T>::insertFixUp(OSTNode<T> *z)
{
	while(z->p->getColor() == RED)
	{
		if(z->p == z->p->p->l)
		{
			OSTNode<T> *y = z->p->p->r;
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
					z->p->setSize(z->getSize());
					z->setSize( z->l->getSize() + z->r->getSize() + 1 );
				}
				z->p->setColor(BLACK);				//case 3
				z->p->p->setColor(RED);
				OSTNode<T> *temp = z->p->p;
				rightRotate(z->p->p);
				temp->p->setSize(temp->getSize());
				temp->setSize( temp->l->getSize() + temp->r->getSize() + 1 );
			}
		}else{									
			OSTNode<T> *y = z->p->p->l;
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
					z->p->setSize(z->getSize());
					z->setSize( z->l->getSize() + z->r->getSize() + 1 );
				}
				z->p->setColor(BLACK);				//case 3
				z->p->p->setColor(RED);
				OSTNode<T> *temp = z->p->p;
				leftRotate(z->p->p);
				temp->p->setSize(temp->getSize());
				temp->setSize( temp->l->getSize() + temp->r->getSize() + 1 );
			}
		}
	}
	root->setColor(BLACK);
}

template<typename T>
bool OSTree<T>::del(OSTNode<T> *z)
{
	OSTNode<T> *y = z;
	OSTNode<T> *x;
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
void OSTree<T>::delFixUp(OSTNode<T> *x)
{
	while(x != root && x->getColor() == BLACK)
	{
		if(x == x->p->l)
		{
			OSTNode<T> *w = x->p->r;
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
			OSTNode<T> *w = x->p->l;
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
void OSTree<T>::transplant(OSTNode<T> *u, OSTNode<T> *v)
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
void OSTree<T>::leftRotate(OSTNode<T> *x)
{
	OSTNode<T> *y = x->r;
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
void OSTree<T>::rightRotate(OSTNode<T> *x)
{
	OSTNode<T> *y = x->l;
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
