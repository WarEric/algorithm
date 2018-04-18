/*
 * BST二叉搜索树的实现，继承自Tree.需要实现其中的虚函数，
 * 并且增加了新的函数
 *
 * by wareric@163.com
 * 2018-4-18
 */
#ifndef BSTREE_H_
#define BSTREE_H_
#include"Tree.h"
#include"BSTNode.h"
template<typename T> class BSTree : public Tree<T>{
	public:
		BSTree():Tree<T>(nullptr){}
		BSTree(const BSTree&);
		inline virtual ~BSTree(){}

		virtual bool insert(BSTNode<T> *node) override;
		virtual bool insert(T key) override;

		virtual bool del(BSTNode<T> *node) override;
		virtual bool del(T key) override;

		virtual BSTNode<T>* min() override;
		virtual BSTNode<T>* max() override;
		virtual BSTNode<T>* search(T key) override;

		virtual BSTNode<T>* predecessor() override;
		virtual BSTNode<T>* successor() override;

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
