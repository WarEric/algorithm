/*
 * 红黑树数据的类，来自算法导论第13章，中间还有很多可以优化的地方。
 * 比如颜色使用枚举类型，树可以实现成模板类型，这里对类的抽象也不够，
 * 函数式的风格还很明显，另外对析构，拷贝构造，拷贝赋值等都没有进行
 * 处理。在树的生命结束时未对动态分配的树进行内存的回收。有待优化。
 * 大部分操作复杂度为O(lgn).
 *
 * by wareric@163.com
 * 2018-04-03 
 */
#ifndef RBTREE_H
#define RBTREE_H
#include "Node.h"

class RBTree{
	public:
		RBTree();
		RBTree(Node *root);
		Node* getNil();
		Node *root;
	private:
		Node *nil;
};

inline
Node* RBTree::getNil()
{
	return nil;
}

/*
 * 获取树中最小的节点
 */
Node* treeMinmum(Node *z, Node *nil);

/*
 * 查找树中是否存在key对应的节点
 */
Node* rbFind(RBTree *T, int key);

/*
 * 左旋
 */
void leftRotate(RBTree *T, Node *x);

/*
 * 右旋
 */
void rightRotate(RBTree *T, Node *x);

/*
 * 供外部使用，自动处理内存的分配,之后调用
 * rbInsert(RBTree *T, Node *z)
 */

void rbInsertKey(RBTree *T, const int key);
/*
 * 已经初始化好节点，只需插入正确的位置
 */
void rbInsert(RBTree *T, Node *z);

/*
 * 在insert完后修正红黑树的性质
 */
void rbInsertFixUp(RBTree *T, Node *z);

/*
 * 删除指定key的节点
 */
void rbDeleteKey(RBTree *T, const int key);

/*
 * 删除指定的节点
 */
void rbDelete(RBTree *T, Node *z);

/*
 * 将v节点取代u
 */
void rbTransplant(RBTree *T, Node *u, Node *v);

/*
 * 恢复红黑树的性质
 */
void rbDeleteFixUp(RBTree *T, Node *x);

/*
 * 中序遍历树中的节点
 */
void inorderTreeWalk(Node *x, const Node *nil);

#endif
