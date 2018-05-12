/*
 * 区间树的头文件，还是对红黑树数据结构的一种扩张
 * by wareric@163.com
 * 2018-05-04
 */
#ifndef ITVNODE_H_
#define ITVNODE_H_
enum Color {RED, BLACK};
template<typename T> class ITVTree;

template<typename T> class ITVNode{
	friend class ITVTree<T>;
	public:
		ITVNode(T l, T h, T m, Color clr):low(l), high(h), max(m), color(clr),
			p(nullptr),l(nullptr),r(nullptr){}
		ITVNode(T l, T h, T m, Color clr, ITVNode *parent, ITVNode *left, ITVNode *right):
			low(l), high(h), max(m), color(clr), p(parent), l(left), r(right){}
		ITVNode(const ITVNode&);
		~ITVNode(){}

		void setLow(T low){this.low = low;}
		void setHigh(T high){this.high = high;}
		void setMax(T max){this.max = max;}
		void setColor(Color color){this->color = color;}
		T getLow(){return low;}
		T getHigh(){return high;}
		T getMax(){return max;}
		Color getColor(){return color;}

		ITVNode<T>& operator=(const ITVNode &orig);
		bool operator==(const ITVNode &node);
		bool operator!=(const ITVNode &node);
		bool operator<(const ITVNode &node);
		bool operator>(const ITVNode &node);
	private:
		T low, high;
		T max;
		Color color;
		ITVNode<T> *p;
		ITVNode<T> *l;
		ITVNode<T> *r;
};

template<typename T>
ITVNode<T>::ITVNode(const ITVNode<T> &orig)
{
	low = orig.low;
	high = orig.high;
	max = orig.max;
	color = orig.color;
	p = orig.p;
	l = orig.l;
	r = orig.r;
}

template<typename T>
ITVNode<T>& ITVNode<T>::operator=(const ITVNode &node)
{
	low = node.low;
	high = node.high;
	max = node.max;
	color = node.color;
	p = node.p;
	l = node.l;
	r = node.r;
}

//这里代表的是重叠
template<typename T>
bool ITVNode<T>::operator==(const ITVNode &node)
{
	if((high < node.low) || (low > node.high))
		return false;
	return true;
}

template<typename T>
bool ITVNode<T>::operator!=(const ITVNode &node)
{
	return !(*this == node);
}

template<typename T>
bool ITVNode<T>::operator<(const ITVNode &node)
{
	if(high < node.low)
		return true;
	return false;
}

template<typename T>
bool ITVNode<T>::operator>(const ITVNode &node)
{
	if(low > node.high)
		return true;
	return false;
}
#endif
