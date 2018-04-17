/*
 * 二叉树节点的头文件，继承自Node
 *
 * by wareric@163.com
 * 2017-04-17
 */
#ifndef BSTNODE_H_
#define BSTNODE_H_
#include<iostream>
#include"Node.h"
template<typename T> class BSTNode : public Node<T>{
	public:
		BSTNode(T key):Node<T>(key), p(nullptr), l(nullptr), r(nullptr){}
		BSTNode(T key, BSTNode *parent, BSTNode *left, BSTNode *right):
			Node<T>(key), p(parent), l(left), r(right){}
		BSTNode(const BSTNode<T>&);
		virtual ~BSTNode(){}

		BSTNode<T>& operator=(const BSTNode &orig);
		bool operator==(const BSTNode<T> &node);
		bool operator!=(const BSTNode &node);
		bool operator<(const BSTNode &node);
		bool operator>(const BSTNode &node);
	protected:
		BSTNode *p;
		BSTNode *l;
		BSTNode *r;
};

template<typename T>
BSTNode<T>::BSTNode(const BSTNode &node)
{
	setKey(node.getKey());
	p = node.p;
	l = node.l;
	r = node.r;
}

template<typename T>
BSTNode<T>& BSTNode<T>::operator=(const BSTNode &orig)
{
	setKey(orig.getKey());
	p = orig.p;
	l = orig.l;
	r = orig.r;
}

template<typename T>
bool BSTNode<T>::operator==(const BSTNode &node)
{
	if(Node<T>::getKey() != node.getKey())
	       	return false;
	return true;
}

template<typename T>
bool BSTNode<T>::operator!=(const BSTNode<T> &node)
{
	if(Node<T>::getKey() != node.getKey())
		return true;
	return false;
}

template<typename T>
bool BSTNode<T>::operator<(const BSTNode &node)
{
	if(Node<T>::getKey() < node.getKey())
	       	return true;
	return false;
}

template<typename T>
bool BSTNode<T>::operator>(const BSTNode &node)
{
	if(Node<T>::getKey() > node.getKey())
	       	return true;
	return false;
}
#endif
