/*
 * 二叉搜索树节点的头文件
 *
 * by wareric@163.com
 * 2017-04-17
 */
#ifndef BSTNODE_H_
#define BSTNODE_H_
template<typename T> class BSTree;

template<typename T> class BSTNode{
	friend class BSTree<T>;
	public:
		BSTNode(T k):key(k), p(nullptr), l(nullptr), r(nullptr){}
		BSTNode(T k, BSTNode *parent, BSTNode *left, BSTNode *right):
			key(k), p(parent), l(left), r(right){}
		BSTNode(const BSTNode<T>&);
		~BSTNode(){}

		void setKey(T key){ this.key = key;}
		T getKey(){ return key;}

		BSTNode<T>& operator=(const BSTNode &orig);
		bool operator==(const BSTNode<T> &node);
		bool operator!=(const BSTNode &node);
		bool operator<(const BSTNode &node);
		bool operator>(const BSTNode &node);
	private:
		T key;
		BSTNode<T> *p;
		BSTNode<T> *l;
		BSTNode<T> *r;
};

template<typename T>
BSTNode<T>::BSTNode(const BSTNode &node)
{
	key = node.key;
	p = node.p;
	l = node.l;
	r = node.r;
}

template<typename T>
BSTNode<T>& BSTNode<T>::operator=(const BSTNode &orig)
{
	key = orig.key;
	p = orig.p;
	l = orig.l;
	r = orig.r;
}

template<typename T>
bool BSTNode<T>::operator==(const BSTNode &node)
{
	if(key != node.key)
	       	return false;
	return true;
}

template<typename T>
bool BSTNode<T>::operator!=(const BSTNode<T> &node)
{
	if(key != node.key)
		return true;
	return false;
}

template<typename T>
bool BSTNode<T>::operator<(const BSTNode &node)
{
	if(key < node.key)
	       	return true;
	return false;
}

template<typename T>
bool BSTNode<T>::operator>(const BSTNode &node)
{
	if(key > node.key)
	       	return true;
	return false;
}
#endif
