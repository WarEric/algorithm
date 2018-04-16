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
		Node(T key);
		virtual ~Node(){}

		inline T getKey();
		inline bool setKey(T key);
	private:
		T key;
};

template<typename T> inline
Node<T>::Node(T key)
{
	this.key = key;
}

template<typename T> inline
T Node<T>::getKey()
{
	return key;
}

template<typename T> inline
bool Node<T>::setKey(T key)
{
	this.key = key;
}
#endif
