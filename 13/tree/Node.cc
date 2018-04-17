#include"Node.h"

template<typename T>
Node<T>::Node(T key)
{
	this.key = key;
}

template<typename T>
Node<T>::Node(const Node<T> &orig)
{
	key(orig.key);
}

template<typename T>
T Node<T>::getKey()
{
	return key;
}

template<typename T>
bool Node<T>::setKey(T key)
{
	this.key = key;
}

template<typename T>
Node<T>& Node<T>::operator=(const Node<T> &orig)
{
	key = orig.key;
}

template<typename T>
bool Node<T>::operator==(const Node<T> &node)
{
	if(key != node.key)
		return false;
	return true;
}

template<typename T>
bool Node<T>::operator!=(const Node<T> &node)
{
	return !(this == node);
}

template<typename T>
bool Node<T>::operator<(const Node<T> &node)
{
	if(key < node.key) 
		return true;
	return false;
}

template<typename T>
bool Node<T>::operator>(const Node<T> &node)
{
	if(key > node.key) 
		return true;
	return false;
}
