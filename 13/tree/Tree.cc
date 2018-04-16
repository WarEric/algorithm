#include"Tree.h"
#include"Node.h"

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
	return nullptr;
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
