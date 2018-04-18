/*
 * BST二叉搜索树的实现，继承自Tree.需要实现其中的虚函数，
 * 并且增加了新的函数
 *
 * by wareric@163.com
 * 2018-4-18
 */
#ifndef BSTREE_H_
#define BSTREE_H_
#include<iostream>
#include<stack>
#include"Tree.h"
#include"BSTNode.h"
using std::cout;
using std::endl;
using std::stack;

template<typename T> class BSTree : public Tree<T>{
	public:
		BSTree(){}
		BSTree(const BSTree&);
		inline virtual ~BSTree(){}

		virtual bool insert(BSTNode<T> *node) override;
		virtual bool insert(T key) override;

		virtual bool del(BSTNode<T> *node) override;
		virtual bool del(T key) override;
		// subtree of v replaces that of u
		void transplant(BSTNode<T> *u, BSTNode<T> *v);

		virtual BSTNode<T>* min() override;
		virtual BSTNode<T>* min(BSTNode<T> *x);
		virtual BSTNode<T>* max() override;
		virtual BSTNode<T>* max(BSTNode<T> *x);
		virtual BSTNode<T>* search(T key) override;
		virtual BSTNode<T>* predecessor(BSTNode<T> *x) override;
		virtual BSTNode<T>* successor(BSTNode<T> *x) override;

		virtual void preorderTreeWalk();
		virtual void preorderTreeWalk(BSTNode<T> *x);
		virtual void inorderTreeWalk();
		virtual void inorderTreeWalk(BSTNode<T> *x);
		virtual void postorderTreeWalk();
		virtual void postorderTreeWalk(BSTNode<T> *x);

		//delete all nodes
		virtual bool destroy() override;
		//recursive copy 
		virtual BSTNode<T>* copy(BSTNode<T>* root) override;

		Tree<T>& operator=(const BSTree &orig);
		bool operator==(const BSTree &tree);
		bool operator!=(const BSTree &tree);
};

template<typename T>
BSTree<T>::BSTree(const BSTree &orig)
{
	Tree<T>::root = copy(orig.root);
}

template<typename T>
bool BSTree<T>::insert(BSTNode<T> *node)
{
	BSTNode<T> *y = nullptr;
	BSTNode<T> *x = Tree<T>::root;
	while(x != nullptr)
	{
		y = x;
		if(node->getKey() < Node<T>::getKey())
			x = x->l;
		else
			x = x->r;
	}
	node->p = y;
	if(y == nullptr)
		Tree<T>::root = y;
	else if(node->getKey() < y->getKey)
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
		transplant(node, node->l);
	else if(node->r == nullptr)
		transplant(node, node->r);
	else{
		BSTree<T> *y = min(node->r);
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
	BSTree<T> *x = search(key);
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
		Tree<T> root = v;
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
	if(Tree<T>::root == nullptr)
		return nullptr;
	BSTNode<T> *x = Tree<T>::root;
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
	if(Tree<T>::root == nullptr)
		return nullptr;
	BSTNode<T> *x = Tree<T>::root;
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
	BSTNode<T> *x = Tree<T>::root;
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
	BSTNode<T> *x = Tree<T>::root;
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
	BSTNode<T> *x = Tree<T>::root;
	if(x != nullptr)
	{
		preorderTreeWalk(x->l);
		cout << x->getKey() << endl;
		preorderTreeWalk(x->r);
	}
}

template<typename T>
void BSTree<T>::inorderTreeWalk(BSTNode<T> *x)
{
	if(x != nullptr)
	{
		preorderTreeWalk(x->l);
		cout << x->getKey() << endl;
		preorderTreeWalk(x->r);
	}
}

template<typename T>
void BSTree<T>::postorderTreeWalk()
{
	BSTNode<T> *x = Tree<T>::root;
	if(x != nullptr)
	{
		preorderTreeWalk(x->l);
		preorderTreeWalk(x->r);
		cout << x->getKey() << endl;
	}
}

template<typename T>
void BSTree<T>::postorderTreeWalk(BSTNode<T> *x)
{
	if(x != nullptr)
	{
		preorderTreeWalk(x->l);
		preorderTreeWalk(x->r);
		cout << x->getKey() << endl;
	}
}

template<typename T>
bool BSTree<T>::destroy()
{
	
	if(Tree<T>::root == nullptr)
		return true;

	BSTNode<T> *rt = dynamic_cast<BSTNode<T> *>(Tree<T>::root);
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
	Tree<T>::root = nullptr;
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

	if(left != nullptr)
		left->p = node;
	if(right != nullptr)
		right->p = node;

	return node;
}

#endif
