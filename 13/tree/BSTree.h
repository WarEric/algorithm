/*
 * BST二叉搜索树的实现
 *
 * by wareric@163.com
 * 2018-4-18
 */
#ifndef BSTREE_H_
#define BSTREE_H_
#include<iostream>
#include<stack>
#include"BSTNode.h"
using std::cout;
using std::endl;
using std::stack;

template<typename T> class BSTree{
	public:
		BSTree():root(nullptr){}
		BSTree(const BSTree&);
		~BSTree();

		bool insert(T key);
		bool del(T key);

		BSTNode<T>* min();
		BSTNode<T>* min(BSTNode<T> *x);
		BSTNode<T>* max();
		BSTNode<T>* max(BSTNode<T> *x);
		BSTNode<T>* search(T key);
		BSTNode<T>* predecessor(BSTNode<T> *x);
		BSTNode<T>* successor(BSTNode<T> *x);

		void preorderTreeWalk();
		void preorderTreeWalk(BSTNode<T> *x);
		void inorderTreeWalk();
		void inorderTreeWalk(BSTNode<T> *x);
		void postorderTreeWalk();
		void postorderTreeWalk(BSTNode<T> *x);

		//delete all nodes
		bool destroy();
		//recursive copy 
		BSTNode<T>* copy(BSTNode<T>* root);

		BSTree<T>& operator=(const BSTree &orig);
		bool operator==(const BSTree &tree);
		bool operator!=(const BSTree &tree);
	private:
		bool insert(BSTNode<T> *node);
		bool del(BSTNode<T> *node);
		// subtree of v replaces that of u
		void transplant(BSTNode<T> *u, BSTNode<T> *v);
		BSTNode<T> *root;
};

template<typename T>
BSTree<T>::BSTree(const BSTree &orig)
{
	cout << "this is copy construct !!! "<< endl;
	root = copy(orig.root);
}

template<typename T>
BSTree<T>::~BSTree()
{
	destroy();
}

template<typename T>
bool BSTree<T>::insert(BSTNode<T> *node)
{
	BSTNode<T> *y = nullptr;
	BSTNode<T> *x = root;
	while(x != nullptr)
	{
		y = x;
		if(node->getKey() < x->key)
			x = x->l;
		else
			x = x->r;
	}
	node->p = y;
	if(y == nullptr)
		root = node;
	else if(node->getKey() < y->getKey())
		y->l = node;
	else
		y->r = node;

	return true;
}

template<typename T>
bool BSTree<T>::insert(T key)
{
	BSTNode<T> *node = new BSTNode<T>(key);
	return insert(node);
}

template<typename T>
bool BSTree<T>::del(BSTNode<T> *node)
{
	if(node->l == nullptr)
		transplant(node, node->r);
	else if(node->r == nullptr)
		transplant(node, node->l);
	else{
		BSTNode<T> *y = min(node->r);
		if(y->p != node)
		{
			transplant(y, y->r);
			y->r = node->r;
			y->r->p = y;
		}
		transplant(node, y);
		y->l = node->l;
		y->l->p = y;
	}
	return true;
}

template<typename T>
bool BSTree<T>::del(T key)
{
	BSTNode<T> *x = search(key);
	if(x == nullptr)
		return false;
	if(del(x) == true)
	{
		delete x;
		return true;
	}else
		return false;
}

template<typename T>
void BSTree<T>::transplant(BSTNode<T> *u, BSTNode<T> *v)
{
	if(u->p == nullptr)
		root = v;
	else if(u == u->p->l)
		u->p->l = v;
	else
		u->p->r = v;
	if(v != nullptr)
		v->p = u->p;
}

template<typename T>
BSTNode<T>* BSTree<T>::min()
{
	if(root == nullptr)
		return nullptr;
	BSTNode<T> *x = root;
	while(x->l != nullptr)
		x = x->l;
	return x;
}

template<typename T>
BSTNode<T>* BSTree<T>::min(BSTNode<T> *x)
{
	if(x == nullptr)
		return nullptr;
	while(x->l != nullptr)
		x = x->l;
	return x;
}

template<typename T>
BSTNode<T>* BSTree<T>::max()
{
	if(root == nullptr)
		return nullptr;
	BSTNode<T> *x = root;
	while(x->r != nullptr)
		x = x->r;
	return x;
}

template<typename T>
BSTNode<T>* BSTree<T>::max(BSTNode<T> *x)
{
	if(x == nullptr)
		return nullptr;
	while(x->r != nullptr)
		x = x->r;
	return x;
}

template<typename T>
BSTNode<T>* BSTree<T>::search(T key)
{
	BSTNode<T> *x = root;
	while(x != nullptr)
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
BSTNode<T>* BSTree<T>::predecessor(BSTNode<T> *x)
{
	if(x->l != nullptr)
		return max(x->l);
	BSTNode<T> *y = x->p;
	while(y != nullptr && x == y->l)
	{
		x = y;
		y = y->p;
	}
	return y;
}

template<typename T>
BSTNode<T>* BSTree<T>::successor(BSTNode<T> *x)
{
	if(x->r != nullptr)
		return min(x->r);
	BSTNode<T> *y = x->p;
	while(y != nullptr && x == y->r)
	{
		x = y;
		y = y->p;
	}
	return y;
}

template<typename T>
void BSTree<T>::preorderTreeWalk()
{
	BSTNode<T> *x = root;
	if(x != nullptr)
	{
		cout << x->getKey() << endl;
		preorderTreeWalk(x->l);
		preorderTreeWalk(x->r);
	}
}

template<typename T>
void BSTree<T>::preorderTreeWalk(BSTNode<T> *x)
{
	if(x != nullptr)
	{
		cout << x->getKey() << endl;
		preorderTreeWalk(x->l);
		preorderTreeWalk(x->r);
	}
}

template<typename T>
void BSTree<T>::inorderTreeWalk()
{
	BSTNode<T> *x = root;
	if(x != nullptr)
	{
		inorderTreeWalk(x->l);
		cout << x->getKey() << endl;
		inorderTreeWalk(x->r);
	}
}

template<typename T>
void BSTree<T>::inorderTreeWalk(BSTNode<T> *x)
{
	if(x != nullptr)
	{
		inorderTreeWalk(x->l);
		cout << x->getKey() << endl;
		inorderTreeWalk(x->r);
	}
}

template<typename T>
void BSTree<T>::postorderTreeWalk()
{
	BSTNode<T> *x = root;
	if(x != nullptr)
	{
		postorderTreeWalk(x->l);
		postorderTreeWalk(x->r);
		cout << x->getKey() << endl;
	}
}

template<typename T>
void BSTree<T>::postorderTreeWalk(BSTNode<T> *x)
{
	if(x != nullptr)
	{
		postorderTreeWalk(x->l);
		postorderTreeWalk(x->r);
		cout << x->getKey() << endl;
	}
}

template<typename T>
bool BSTree<T>::destroy()
{
	
	if(root == nullptr)
		return true;

	BSTNode<T> *rt = root;
	stack<BSTNode<T> *> stk;
	stk.push(rt);

	while(!stk.empty())
	{
		BSTNode<T> *ptr = stk.top();
		stk.pop();

		if(ptr->r != nullptr)
			stk.push(ptr->r);
		if(ptr->l != nullptr)
			stk.push(ptr->l);
		delete ptr;
	}
	root = nullptr;
	return true;
}
template<typename T>
BSTNode<T>* BSTree<T>::copy(BSTNode<T> *root)
{
	BSTNode<T> *node;
	BSTNode<T> *left;
	BSTNode<T> *right;

	if(root == nullptr)
		return nullptr;
	if(root->l != nullptr)
		left = copy(root->l);
	if(root->r != nullptr)
		right = copy(root->r);

	node = new BSTNode<T>(root->getKey(), nullptr, left, right);
	cout << "copying " << root->getKey() << endl;

	if(left != nullptr)
		left->p = node;
	if(right != nullptr)
		right->p = node;

	return node;
}

#endif
