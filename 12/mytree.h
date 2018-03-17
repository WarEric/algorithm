/*
 * 二叉树相关操作的头文件和函数声明，数据结构的定义
 * 操作复杂度为O(n)或O(lgn)
 * by wareric@163.com
 * 2018-3-17
 */
#ifndef	MYTREE_H
#define MYTREE_H

typedef struct node	Node;
typedef struct node	Mytree;
typedef struct t	T;

struct node{
	int	key;
	Node	*parent;
	Node	*left;
	Node	*right;
};

struct t{
	Node *root;
};

/*
 * 二叉树的插入，是否支持相同的元素还有待考虑
 */
void    tree_insert(T *t, Node *z);

/*
 * 二叉树的循环迭代查找
 * return值为空则表示不存在
 */
Node*	iterative_tree_search(Node *x, int key);

/*
 * 二叉树的递归查找
 */
Node*	tree_search(Node *x, int key);

/*
 * 二叉树的中序输出，修改中间的输出位置则课变为
 * 先序或后序输出
 */
void	inorder_tree_walk(Node *x);

/*
 * 获取二叉树中最小的节点，若返回值为空说明
 * 树是一颗空树
 */
Node*	tree_minimum(Node *x);

/*
 * 获取二叉树中最大的节点，若返回值为空说明
 * 树是一颗空树
 */
Node*	tree_maximum(Node *x);

/*
 * 返回给定节点的后继
 */
Node*	tree_successor(Node *x);

/*
 * 返回给定节点的前驱
 */
Node*	tree_predecessor(Node *x);

/*
 * 将以v为根的树衔接到u上，但不负责修改u指针所指向的
 * 位置,内部函数
 */
void	transplant(T *t, Node *u, Node *v);

/*
 * 删除二叉树上指定的节点,不负责内存的回收
 */
void	tree_delete(T *t, Node *z);
#endif
