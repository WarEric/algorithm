/*
 * 堆相关的一些算法和
 * 优先队列用堆实现的一些算法
 * by wareric@163.com
 * 2017-10-2
 */
#ifndef HEAPSTD_H_
#define HEAPSTD_H_

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct element{
	int key;
};

typedef struct element Node;

struct heapdata{
	Node *array;
	int size;
};

typedef struct heapdata Heap;

/*
 * 维护最大堆的性质，前提是该节点的子树已经
 * 符合最大堆的性质,复杂度为O(lgn)
 */
void max_heapify(Heap *h, int i);

/*
 * 建立最大堆,复杂度为O(n)
 */
void build_max_heap(Heap *h);

/*
 * 对堆进行排序,复杂度为O(nlgn)
 */
void heap_sort(Heap *h);

/*
 * 返回最大堆中key值最大的节点，
 * 前提是该堆已经满足最大堆的条件
 * 复杂度为O(1)
 */
Node heap_maximum(Heap *h);

/*
 * 从堆中拿走key值最大的节点,
 * 复杂度为O(lgn)
 */
Node heap_extract_max(Heap *h);

/*
 * 增加第i个节点的key值为输入的值
 * 新输入的值要比之前的key大,复杂度
 * 为O(lgn)
 */
void heap_increase_key(Heap *h, int i, int key);

/*
 * 向一个最大堆中插入一个新的元素,
 * 使新的堆继是最大堆，复杂度为
 * O(lgn)
 */
void max_heap_insert(Heap *h,int key);

/*
 * 交换两个节点之间的值
 */
void node_exchange(Heap *h, int i, int j);

/*
 * 方便获取第i号节点处的key值
 */
int getkey(Heap *h, int i);
#endif
