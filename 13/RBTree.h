#ifndef RBTREE_H
#define RBTREE_H
#include "Node.h"

class RBTree{
	public:
		RBTree();
		Node *root;
		Node *nil;
};

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
#endif
