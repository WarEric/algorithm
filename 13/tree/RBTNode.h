/*
 * 红黑树的节点, 使用模板实现.
 *
 * by wareric@163.com
 * 2018-04-19
 */
#ifndef RBTNODE_H_
#define RBTNODE_H_
enum Color {RED, BLACK};
template<typename T> class RBTree;

template<typename T> class RBTNode{
	friend class RBTree<T>;
	public:
		RBTNode(T k, Color clr):key(k),color(clr),p(nullptr),l(nullptr),
					r(nullptr){}
		RBTNode(T k, Color clr, RBTNode *parent, RBTNode *left, RBTNode *right):
			key(k), color(clr), p(parent), l(left), r(right){}
		RBTNode(const RBTNode&);
		~RBTNode(){}

		void setKey(T key){this.key = key;}
		T getKey(){return key;}
		void setColor(Color color){this->color = color;}
		Color getColor(){return color;}

		RBTNode<T>& operator=(const RBTNode &orig);
		bool operator==(const RBTNode &node);
		bool operator!=(const RBTNode &node);
		bool operator<(const RBTNode &node);
		bool operator>(const RBTNode &node);
	private:
		T key;
		Color color;
		RBTNode<T> *p;
		RBTNode<T> *l;
		RBTNode<T> *r;
};

template<typename T>
RBTNode<T>::RBTNode(const RBTNode<T> &orig)
{
	key = orig.key;
	color = orig.color;
	p = orig.p;
	l = orig.l;
	r = orig.r;
}

template<typename T>
RBTNode<T>& RBTNode<T>::operator=(const RBTNode &node)
{
	key = node.key;
	color = node.color;
	p = node.p;
	l = node.l;
	r = node.r;
}

template<typename T>
bool RBTNode<T>::operator==(const RBTNode &node)
{
	if((key == node.key) && (color == node.color))
		return true;
	return false;
}

template<typename T>
bool RBTNode<T>::operator!=(const RBTNode &node)
{
	return !(*this == node);
}

template<typename T>
bool RBTNode<T>::operator<(const RBTNode &node)
{
	if(key < node.key)
		return true;
	return false;
}

template<typename T>
bool RBTNode<T>::operator>(const RBTNode &node)
{
	if(key > node.key)
		return true;
	return false;
}
#endif
