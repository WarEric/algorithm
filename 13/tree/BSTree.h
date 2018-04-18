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

		virtual bool insert(BSTNode<T> *node);
		virtual bool insert(T key);

		virtual bool del(BSTNode<T> *node);
		virtual bool del(T key);

		virtual BSTNode<T>* min();
		virtual BSTNode<T>* max();
		virtual BSTNode<T>* search(T key);

		virtual BSTNode<T>* predecessor();
		virtual BSTNode<T>* successor();

		//delete all nodes
		virtual bool destroy();
		//recursive copy 
		virtual BSTNode<T>* copy(BSTNode<T>* root);

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
