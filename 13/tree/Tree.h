/*
 * 树的基类，不实现任何功能，仅作为一个最顶层的基类；
 * 不要用来存储任何数据，要使用其合适的派生类处理数据；
 *
 * by wareric@163.com
 * 2018-04-16
 */
#ifndef TREE_H_
#define TREE_H_
#include"Node.h"

template <typename T> class Tree{
	public:
		Tree():root(nullptr){}
		Tree(const Tree&);
		inline virtual ~Tree(){}

		virtual bool insert(Node<T> *node);
		virtual bool insert(T key);

		virtual bool del(Node<T> *node);
		virtual bool del(T key);

		virtual Node<T>* min();
		virtual Node<T>* max();
		virtual Node<T>* search(T key);

		virtual Node<T>* predecessor(){return nullptr;}
		virtual Node<T>* successor(){return nullptr;}

		//delete all nodes 
		virtual bool destroy();
		virtual Node<T>* copy(Node<T>* root);

		Tree<T>& operator=(const Tree &orig);
		bool operator==(const Tree &tree);
		bool operator!=(const Tree &tree);
	private:
		Node<T> *root;
};

template <typename T>
Tree<T>::Tree(const Tree &tree)
{
	root = tree.root;
}

template <typename T>
bool Tree<T>::insert(Node<T> *node)
{
	if(root != nullptr) 
		return false;
	root = node;
	return true;
}

template <typename T>
bool Tree<T>::insert(T key)
{
	if(root != nullptr) 
		return false;
	Node<T> *ptr = new Node<T>(key);
	return insert(ptr);
}

template <typename T>
bool Tree<T>::del(Node<T> *node)
{
	if(root == nullptr) return false;
	if(root->getKey() != node->getKey()) return false;
	delete root;
	root = nullptr;
	return true;
}

template <typename T>
bool Tree<T>::del(T key)
{
	Node<T> *ptr = search(key);
	if(ptr == nullptr) 
		return false;
	return del(ptr);
}

template <typename T>
Node<T>* Tree<T>::min()
{
	if(root == nullptr) 
		return nullptr;
	return root;
}

template <typename T>
Node<T>* Tree<T>::max()
{
	if(root == nullptr) 
		return nullptr;
	return root;
}

template <typename T>
Node<T>* Tree<T>::search(T key)
{
	if(root == nullptr)
	       	return nullptr;
	if(root->getKey() != key)
	       	return nullptr;
	return root;
}

template<typename T>
bool Tree<T>::destroy()
{
	if(root != nullptr) delete root;

}

template<typename T>
Node<T>* Tree<T>::copy(Node<T>* root)
{
	if(root == nullptr)
		return nullptr;
	return new Node<T>(root->getKey());
}

template <typename T>
Tree<T>&  Tree<T>::operator=(const Tree &orig)
{
	root = orig.root;
}

template <typename T>
bool Tree<T>::operator==(const Tree &tree)
{
	if(root != tree.root)
		return false;
	return true;
}

template <typename T>
bool Tree<T>::operator!=(const Tree &tree)
{
	return !(this == tree);
}
#endif
