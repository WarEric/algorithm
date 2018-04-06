/*
 * 红黑树节点相关的类，包括节点的一些基本操作，不能有重复节点存在。
 * 来自算法导论第13章，中间还有很多可以优化的地方。比如颜色使用枚举
 * 类型，树可以实现成模板类型，这里对类的抽象也不够，函数式的风格还
 * 很明显，另外对析构，拷贝构造，拷贝赋值等都没有进行处理。在树的
 * 生命结束时未对动态分配的树进行内存的回收。有待优化。
 * 
 * by wareric@163.com
 * 2018-4-3 
 */
#ifndef NODE_H
#define NODE_H
#include<string>

#define RED string("RED")
#define BLACK string("BLACK")

class Node{
	friend bool operator==(const Node &n1, const Node &n2);
	friend bool operator!=(const Node &n1, const Node &n2);
	public:
		Node(int key, std::string color, Node *parent, Node *left, Node *right);
		Node(int key, std::string color);
		~Node(){};
		int getKey();
		std::string getColor();
		void setKey(int key);
		void setColor(std::string color);
		Node *parent, *left, *right;
	private:
		int key;
		std::string color;
};

inline
bool operator==(const Node &n1, const Node &n2)
{
	if(n1.key != n2.key) return false;
	if(n1.color != n2.color) return false;
	return true;
}

inline
bool operator!=(const Node &n1, const Node &n2)
{
	return !(n1 == n2);
}
#endif
