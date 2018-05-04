/*
 * 区间树interval tree的头文件，这是对红黑树数据结构的
 * 一种扩张, 注意区间的最小值不能低于MIN_TEMPLATE,为了
 * 更好的实现，这里应该使用模板特例化，将nil的max值置为
 * 对应数据类型能取到的最小值。
 * by wareric@163.com
 * 2018-05-04
 */
#ifndef ITVTREE_H_
#define ITVTREE_H_
#include<iostream>
#include<iomanip>
#include<stack>
#include"ITVNode.h"
#define MIN_TEMPLATE -10000
using std::cout;
using std::endl;
using std::left;
using std::setw;
using std::stack;

template<typename T> class ITVTree{
	public:
		ITVTree():root(nil){}
		ITVTree(const RBTree&);
		~ITVTree();

		bool insert(T low, T high);
		bool del(ITVNode<T> *node);

		ITVNode<T>* min();
		ITVNode<T>* min(ITVNode<T> *x);
		ITVNode<T>* max();
		ITVNode<T>* max(ITVNode<T> *x);
		ITVNode<T>* search(T low, T high);
		ITVNode<T>* predecessor(ITVNode<T> *x);
		ITVNode<T>* successor(ITVNode<T> *x);

		void preorderTreeWalk();
		void preorderTreeWalk(ITVNode<T> *x);
		void inorderTreeWalk();
		void inorderTreeWalk(ITVNode<T> *x);
		void postorderTreeWalk();
		void postorderTreeWalk(ITVNode<T> *x);

		//delete all nodes
		bool destroy();
		//recursive copy
		ITVNode<T>* copy(ITVNode<T>* root);

		ITVTree<T>& operator=(const RBTree &tree);
		bool operator==(const ITVTree &tree);
		bool operator!=(const ITVTree &tree);

		static ITVNode<T> *nil;
	private:
		bool insert(ITVNode<T> *node);
		void insertFixUp(ITVNode<T> *z);
		void delFixUp(ITVNode<T> *x);
		//subtree of v repalces that of u
		void transplant(ITVNode<T> *u, ITVNode<T> *v);

		void leftRotate(ITVNode<T> *x);
		void rightRotate(ITVNode<T> *x);

		T max(T a, T b, T c);

		ITVNode<T> *root;
};

template<typename T>
ITVNode<T>* ITVTree<T>::nil = new ITVNode<T>(0, 0, MIN_TEMPLATE, BLACK);

template<typename T>
ITVTree<T>::RBTree(const RBTree &orig)
{
	root = copy(orig.root);
}

template<typename T>
ITVTree<T>::~RBTree()
{
	destroy();
}

template<typename T>
bool ITVTree<T>::insert(T low, T high)
{
	ITVNode<T> *node = new ITVNode<T>(low, high, high, RED);
	return insert(node);
}

template<typename T>
ITVNode<T>* ITVTree<T>::min()
{
	ITVNode<T> *x = root;
	while(x->l != nil)
		x = x->l;
	return x;
}

template<typename T>
ITVNode<T>* ITVTree<T>::min(ITVNode<T> *x)
{
	if(x == nullptr)
		return nil;
	while(x->l != nil)
		x = x->l;
	return x;
}

template<typename T>
ITVNode<T>* ITVTree<T>::max()
{
	ITVNode<T> *x = root;
	while(x->r != nil)
		x = x->r;
	return x;
}

template<typename T>
ITVNode<T>* ITVTree<T>::max(ITVNode<T> *x)
{
	if(x == nullptr)
		return nil;
	while(x->r != nil)
		x = x->r;
	return x;
}

template<typename T>
ITVNode<T>* ITVTree<T>::search(T low, T high)
{
	ITVNode<T> *x = root;
	ITVNode<T> s(low, high, -1, BLACK);
	while((x != nil) && (*x != s))
	{
		if((x->l != nil) && (x->l->max >= low) )
			x = x->l;
		else
			x = x->r;
	}
	return x;
}

template<typename T>
ITVNode<T>* ITVTree<T>::predecessor(ITVNode<T> *x)
{
	if(x->l != nil)
		return max(x->l);
	ITVNode<T> *y = x->p;
	while(y != nil && x == y->l)
	{
		x = y;
		y = y->p;
	}
	return y;
}

template<typename T>
ITVNode<T>* ITVTree<T>::successor(ITVNode<T> *x)
{
	if(x->r != nil)
		return min(x->r);
	ITVNode<T> *y = x->p;
	while(y != nil && x == y->r)
	{
		x = y;
		y = y->p;
	}
	return y;
}

template<typename T>
void ITVTree<T>::preorderTreeWalk()
{
	ITVNode<T> *x = root;
	if(x != nil)
	{
		cout << left << "low = " << setw(4) << x->low << " high = " << setw(4) << x->high
			<< " max = " << setw(4) << x->max
		       	<< " color =  "	<< setw(8) << (x->getColor() == RED ? "RED":"BLACK") << endl;
		preorderTreeWalk(x->l);
		preorderTreeWalk(x->r);
	}
}

template<typename T>
void ITVTree<T>::preorderTreeWalk(ITVNode<T> *x)
{
	if(x != nil)
	{
		cout << left << "low = " << setw(4) << x->low << " high = " << setw(4) << x->high
			<< " max = " << setw(4) << x->max
		       	<< " color =  "	<< setw(8) << (x->getColor() == RED ? "RED":"BLACK") << endl;
		preorderTreeWalk(x->l);
		preorderTreeWalk(x->r);
	}
}

template<typename T>
void ITVTree<T>::inorderTreeWalk()
{
	ITVNode<T> *x = root;
	if(x != nil)
	{
		inorderTreeWalk(x->l);
		cout << left << "low = " << setw(4) << x->low << " high = " << setw(4) << x->high
			<< " max = " << setw(4) << x->max
		       	<< " color =  "	<< setw(8) << (x->getColor() == RED ? "RED":"BLACK") << endl;
		inorderTreeWalk(x->r);
	}
}

template<typename T>
void ITVTree<T>::inorderTreeWalk(ITVNode<T> *x)
{
	if(x != nil)
	{
		inorderTreeWalk(x->l);
		cout << left << "low = " << setw(4) << x->low << " high = " << setw(4) << x->high
			<< " max = " << setw(4) << x->max
		       	<< " color =  "	<< setw(8) << (x->getColor() == RED ? "RED":"BLACK") << endl;
		inorderTreeWalk(x->r);
	}
}

template<typename T>
void ITVTree<T>::postorderTreeWalk()
{
	ITVNode<T> *x = root;
	if(x != nil)
	{
		postorderTreeWalk(x->l);
		postorderTreeWalk(x->r);
		cout << left << "low = " << setw(4) << x->low << " high = " << setw(4) << x->high
			<< " max = " << setw(4) << x->max
		       	<< " color =  "	<< setw(8) << (x->getColor() == RED ? "RED":"BLACK") << endl;
	}
}

template<typename T>
void ITVTree<T>::postorderTreeWalk(ITVNode<T> *x)
{
	if(x != nil)
	{
		postorderTreeWalk(x->l);
		postorderTreeWalk(x->r);
		cout << left << "low = " << setw(4) << x->low << " high = " << setw(4) << x->high
			<< " max = " << setw(4) << x->max
		       	<< " color =  "	<< setw(8) << (x->getColor() == RED ? "RED":"BLACK") << endl;
	}
}

template<typename T>
bool ITVTree<T>::destroy()
{
	
	if(root == nil)
		return true;

	ITVNode<T> *rt = root;
	stack<ITVNode<T> *> stk;
	stk.push(rt);

	while(!stk.empty())
	{
		ITVNode<T> *ptr = stk.top();
		stk.pop();

		if(ptr->r != nil)
			stk.push(ptr->r);
		if(ptr->l != nil)
			stk.push(ptr->l);
		delete ptr;
	}
	root = nil;
	return true;
}

template<typename T>
ITVNode<T>* ITVTree<T>::copy(ITVNode<T> *root)
{
	ITVNode<T> *node = nil;
	ITVNode<T> *left = nil;
	ITVNode<T> *right = nil;

	if(root == nil)
		return nil;
	if(root->l != nil)
		left = copy(root->l);
	if(root->r != nil)
		right = copy(root->r);

	node = new ITVNode<T>(root->low, root->high, root->max, root->color,  nil, left, right);

	if(left != nil)
		left->p = node;
	if(right != nil)
		right->p = node;

	return node;
}

template<typename T>
ITVTree<T>& RBTree<T>::operator=(const RBTree &orig)
{
	destroy();
	root = copy(orig.root);
}

template<typename T>
bool ITVTree<T>::operator==(const RBTree &dst)
{
	stack<ITVNode<T> *> stkd, stks;
	ITVNode<T> *d = dst.root;
	ITVNode<T> *s = root;
	if(d == nil)
	{
		if(s == nil)
			return true;
		else
			return false;
	}else{
		if(s ==  nil)
			return false;
	}

	stkd.push(d);
	stks.push(s);
	while((!stkd.empty()) && (!stks.empty()))
	{
		d = stkd.top();
		stkd.pop();

		s = stks.top();
		stks.pop();

		if((d->low != s->low) || (d->high != s->high)
			|| (d->max != s->max) || (d->color != s->color))
			return false;

		if(d->r != nil)
			stkd.push(d->r);
		if(d->l != nil)
			stkd.push(d->l);

		if(s->r != nil)
			stks.push(s->r);
		if(s->l != nil)
			stks.push(s->l);
	}

	//both equal to zero
	if(stkd.size() != stks.size())
		return false;
	return true;
}

template<typename T>
bool ITVTree<T>::operator!=(const RBTree &tree)
{
	return !(*this == tree);
}

template<typename T>
bool ITVTree<T>::insert(ITVNode<T> *z)
{
	ITVNode<T> *y = nil;
	ITVNode<T> *x = root;
	while(x != nil)
	{
		y = x;
		if(z->getKey() < x->getKey())
			x = x->l;
		else
			x = x->r;
	}
	z->p = y;
	if(y == nil)
		root = z;
	else if(z->getKey() < y->getKey())
		y->l = z;
	else
		y->r = z;
	z->l = nil;
	z->r = nil;
	z->setColor(RED);

	//fix max
	ITVNode<T> *fixmax = z->p;
	while(fixmax != nil)
	{
		fixmax->max = max(fixmax->high, fixmax->l->max, fixmax->r->max);
	}

	insertFixUp(z);
	return true;
}

template<typename T>
void ITVTree<T>::insertFixUp(ITVNode<T> *z)
{
	while(z->p->getColor() == RED)
	{
		if(z->p == z->p->p->l)
		{
			ITVNode<T> *y = z->p->p->r;
			if(y->getColor() == RED)				//case 1
			{
				z->p->setColor(BLACK);
				y->setColor(BLACK);
				z->p->p->setColor(RED);
				z = z->p->p;
			}else{
				if(z == z->p->r)				//case 2
				{
					z = z->p;
					leftRotate(z);
					z->p->max = z->max;
					z->max = max(z->high, z->l->max, z->r->max);
				}
				z->p->setColor(BLACK);				//case 3
				z->p->p->setColor(RED);
				OSTNode<T> *temp = z->p->p;
				rightRotate(z->p->p);
				temp->p->max = temp->max;
				temp->max = max(temp->high, temp->l->max, temp->r->max);
			}
		}else{									
			ITVNode<T> *y = z->p->p->l;
			if(y->getColor() == RED)				//case 1
			{
				z->p->setColor(BLACK);
				y->setColor(BLACK);
				z->p->p->setColor(RED);
				z = z->p->p;
			}else{
				if(z == z->p->l)				//case 2
				{
					z = z->p;
					rightRotate(z);
					z->p->max = z->max;
					z->max = max(z->high, z->l->max, z->r->max);
				}
				z->p->setColor(BLACK);				//case 3
				z->p->p->setColor(RED);
				ITVTree<T> *temp = z->p->p;
				leftRotate(z->p->p);
				temp->p->max = temp->max;
				temp->max = max(temp->high, temp->l->max, temp->r->max);
			}
		}

	}
	root->setColor(BLACK);
}

template<typename T>
bool ITVTree<T>::del(ITVNode<T> *z)
{
	ITVNode<T> *y = z, *fixmax = nil;
	ITVNode<T> *x;
	Color y_original_color = y->getColor();
	if(z->l == nil)
	{
		x = z->r;
		fixmax = z->p;
		transplant(z, z->r);	
	}else if(z->r == nil){
		x = z->l;
		fixmax = z->p;
		transplant(z, z->l);	
	}else{
		y = min(z->r);	
		y_original_color = y->getColor();
		x = y->r;
		if(y->p == z)
		{	
			fixmax = y;
			x->p = y;
		}else{
			fixmax = y->p;
			transplant(y, y->r);
			y->r = z->r;
			y->r->p = y;
		}
		transplant(z, y);
		y->l = z->l;
		y->l->p = y;
		y->setColor(z->getColor());
	}

	//fixup max
	while(fixmax != nil)
	{
		fixmax->max = max(fixmax->high, fixmax->l->max, fixmax->r->max);
		fixmax = fixmax->p;
	}

	if(y_original_color == BLACK)
		delFixUp(x);
	return true;
}

template<typename T>
void ITVTree<T>::delFixUp(ITVNode<T> *x)
{
	while(x != root && x->getColor() == BLACK)
	{
		if(x == x->p->l)
		{
			ITVNode<T> *w = x->p->r;
			if(w->getColor() == RED)				//case 1
			{
				w->setColor(BLACK);
				x->p->setColor(RED);
				ITVNode<T> *temp = x->p;
				leftRotate(x->p);
				temp->p->max = temp->max;
				temp->max = max(temp->high, temp->l->max, temp->r->max);
				w = x->p->r;
			}

			if(w->l->getColor() == BLACK 
					&& w->r->getColor() == BLACK)		//case 2
			{
				w->setColor(RED);
				x = x->p;
			}else{
				if(w->r->getColor() == BLACK)			//case 3
				{
					w->l->setColor(BLACK);
					w->setColor(RED);
					rightRotate(w);
					ITVNode<T> *temp = w;
					temp->p->max = temp->max;
					temp->max = max(temp->high, temp->l->max, temp->r->max);
					w = x->p->r;
				}
				w->setColor(x->p->getColor());			//case 4
				x->p->setColor(BLACK);
				w->r->setColor(BLACK);
				ITVNode<T> *temp = x->p;
				leftRotate(x->p);
				temp->p->max = temp->max;
				temp->max = max(temp->high, temp->l->max, temp->r->max);
				x = root;
			}
		}else{
			ITVNode<T> *w = x->p->l;
			if(w->getColor() == RED)				//case 1
			{
				w->setColor(BLACK);
				x->p->setColor(RED);
				ITVNode<T> *temp = x->p;
				rightRotate(x->p);
				temp->p->max = temp->max;
				temp->max = max(temp->high, temp->l->max, temp->r->max);
				w = x->p->l;
			}

			if(w->l->getColor() == BLACK 
					&& w->r->getColor() == BLACK)		//case 2
			{
				w->setColor(RED);
				x = x->p;
			}else{
				if(w->l->getColor() == BLACK)			//case 3
				{
					w->r->setColor(BLACK);
					w->setColor(RED);
					leftRotate(w);
					ITVNode<T> *temp = w;
					temp->p->max = temp->max;
					temp->max = max(temp->high, temp->l->max, temp->r->max);
					w = x->p->l;
				}
				w->setColor(x->p->getColor());			//case 4
				x->p->setColor(BLACK);
				w->l->setColor(BLACK);
				ITVNode<T> *temp = x->p;
				rightRotate(x->p);
				temp->p->max = temp->max;
				temp->max = max(temp->high, temp->l->max, temp->r->max);
				x = root;
			}
		}
	}
	x->setColor(BLACK);
}

template<typename T>
void ITVTree<T>::transplant(ITVNode<T> *u, ITVNode<T> *v)
{
	if(u->p == nil)
		root = v;
	else if(u == u->p->l)
		u->p->l = v;
	else
		u->p->r = v;
	v->p = u->p;
}


template<typename T>
void ITVTree<T>::leftRotate(ITVNode<T> *x)
{
	ITVNode<T> *y = x->r;
	x->r = y->l;
	if(y->l != nil)
		y->l->p = x;
	y->p = x->p;
	if(x->p == nil)
		root = y;
	else if(x == x->p->l)
		x->p->l = y;
	else
		x->p->r = y;
	y->l = x;
	x->p = y;
}

template<typename T>
void ITVTree<T>::rightRotate(ITVNode<T> *x)
{
	ITVNode<T> *y = x->l;
	x->l = y->r;
	if(y->r != nil)
		y->r->p = x;
	y->p = x->p;
	if(x->p == nil)
		root = y;
	else if(x == x->p->r)
		x->p->r = y;
	else
		x->p->l = y;
	y->r = x;
	x->p = y;
}

template<typename T> 
T ITVTree<T>::max(T a, T b, T c)
{
	int max = a>b ? a:b;
	return max>c ? max:c;
}
#endif
