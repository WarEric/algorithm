/*
 * 树的基类，不实现任何功能，仅作为一个最顶层的基类；
 * 不要用来存储任何数据，要使用其合适的派生类处理数据；
 *
 * by wareric@163.com
 * 2018-04-16
 */
#ifndef TREE_H_
#define TREE_H_
template <typename T> class Tree{
	public:
		virtual bool insert(Node<T> *node);
		virtual bool insert(T key);
		virtual bool del(Node<T> *node);
		virtual bool del(T key);
		virtual Node<T>* search(T key);
		virtual Node<T>* min();
		virtual Node<T>* max();
		virtual Node<T>* predecessor();
		virtual Node<T>* successor();
		virtual ~Tree();
		Tree();
	private:
		Node<T> *root;
};
#endif
