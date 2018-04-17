/*
 * 树节点的基类，仅包含key值，由于树可能是n叉树，
 * 所以具体孩子的个数应在其派生类内部定义，这里
 * 只是一个基类，使用时应实现所需要的派生类
 *
 * by wareric@163.com
 * 2018-04-16
 */
#ifndef NODE_H_
#define NODE_H_

template <typename T> class Node{
	public:
		Node(T key):key(key){}
		Node(const Node &);
		virtual ~Node(){}

		T getKey()const;
		bool setKey(T key);

		Node<T>& operator=(const Node &orig); 
		bool operator==(const Node &node);
		bool operator!=(const Node &node);
		bool operator<(const Node &node);
		bool operator>(const Node &node);
	private:
		T key;
};

template<typename T>
Node<T>::Node(const Node &orig)
{
	key(orig.key);
}

template<typename T>
T Node<T>::getKey() const
{
	return key;
}

template<typename T>
bool Node<T>::setKey(T key)
{
	this->key = key;
}

template<typename T>
Node<T>& Node<T>::operator=(const Node &orig)
{
	key = orig.key;
}

template<typename T>
bool Node<T>::operator==(const Node &node)
{
	if(key != node.key)
		return false;
	return true;
}

template<typename T>
bool Node<T>::operator!=(const Node &node)
{
	if(key != node.key)
		return true;
	return false;
}

template<typename T>
bool Node<T>::operator<(const Node &node)
{
	if(key < node.key) 
		return true;
	return false;
}

template<typename T>
bool Node<T>::operator>(const Node &node)
{
	if(key > node.key) 
		return true;
	return false;
}
#endif
