/*
 * 顺序统计树的节点头文件
 * by wareric@163.com
 * 2018-05-03
 */
#ifndef OSTNODE_H_
#define OSTNODE_H_
enum Color {RED, BLACK};
template<typename T> class OSTree;

template<typename T> class OSTNode{
	friend class OSTree<T>;
	public:
		OSTNode(T k, Color clr, int s):key(k),color(clr),size(s),p(nullptr),l(nullptr),
					r(nullptr){}
		OSTNode(T k, Color clr, int s, OSTNode *parent, OSTNode *left, OSTNode *right):
			key(k), color(clr), size(s), p(parent), l(left), r(right){}
		OSTNode(const OSTNode&);
		~OSTNode(){}

		void setKey(T key){this.key = key;}
		void setColor(Color color){this->color = color;}
		void setSize(int size){this->size = size;}
		T getKey(){return key;}
		Color getColor(){return color;}
		int getSize(){return size;}

		OSTNode<T>& operator=(const OSTNode &orig);
		bool operator==(const OSTNode &node);
		bool operator!=(const OSTNode &node);
		bool operator<(const OSTNode &node);
		bool operator>(const OSTNode &node);
	private:
		T key;
		Color color;
		int size;
		OSTNode<T> *p;
		OSTNode<T> *l;
		OSTNode<T> *r;
};

template<typename T>
OSTNode<T>::OSTNode(const OSTNode<T> &orig)
{
	key = orig.key;
	color = orig.color;
	size = orig.size;
	p = orig.p;
	l = orig.l;
	r = orig.r;
}

template<typename T>
OSTNode<T>& OSTNode<T>::operator=(const OSTNode &node)
{
	key = node.key;
	color = node.color;
	size = node.size;
	p = node.p;
	l = node.l;
	r = node.r;
}

template<typename T>
bool OSTNode<T>::operator==(const OSTNode &node)
{
	if((key == node.key) && (color == node.color))
		return true;
	return false;
}

template<typename T>
bool OSTNode<T>::operator!=(const OSTNode &node)
{
	return !(*this == node);
}

template<typename T>
bool OSTNode<T>::operator<(const OSTNode &node)
{
	if(key < node.key)
		return true;
	return false;
}

template<typename T>
bool OSTNode<T>::operator>(const OSTNode &node)
{
	if(key > node.key)
		return true;
	return false;
}
#endif
