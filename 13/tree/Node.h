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
		Node(const Node<T>&);
		virtual ~Node(){}

		T getKey();
		bool setKey(T key);

		Node<T>& operator=(const Node<T> &orig); 
		bool operator==(const Node<T> &node);
		bool operator!=(const Node<T> &node);
		bool operator<(const Node<T> &node);
		bool operator>(const Node<T> &node);
	private:
		T key;
};
#endif
