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
	RBTNode<T> *node = new RBTNode<T>(key);
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
	//maybe need run destroy
	root = copy(orig.root);
	root->p = nil;
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

#endif
