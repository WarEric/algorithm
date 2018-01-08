/*
 * 桶排序，通过将数据划分到不同的桶中，再给每一个桶应用一个算法
 * 算法复杂度为O(n),但是由于我这里在每一个桶中使用了性能较差的
 * 冒泡式提取，将最后的合并操作与对每个桶排序操作合并在了一起。
 * 浪费了较多的地址空间，实现的不是很好
 *
 * by wareric@163.com
 * 2018-1-8
 */
#include "bucket.h"
#include "ericio.h"
#include<stdio.h>
int extract_min(Node *head);
void bucketsort(int *head, int *end, int **head_sorted, int **end_sorted, int n, int size);

int main(int argc, char *argv[])
{
	if(argc < 2){
		printf("input should be %s datafile\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	int *head, *tail, *head_sorted, *end_sorted;
	tail = load_array(argv[1], &head);

	printf("排序之前的数据为：\n");
	show_array(head, tail);

	bucketsort(head, tail+1, &head_sorted, &end_sorted, 10, 100);

	printf("排序之后的数据：\n");
	show_array(head_sorted, end_sorted-1);
}

/*
 * size 代表 输入数据/size 归一化到(0,1]内
 * n 表示将0-1分为多少段
 * head 表示输入数据的起始位置
 * end 输入数据的结束位置
 * head_sorted 排好序后数据的起始位置
 * end_sorted 排好序后数据的结束位置
 */
void bucketsort(int *head, int *end, int **head_sorted, int **end_sorted, int n, int size)
{
	int i, length;
	length = end - head;

	Bucket* buckets;
	buckets = malloc(sizeof(Bucket)*n);

	for(i = 0; i < n; i++)
	{
		buckets[i].head = malloc(sizeof(Node));
		buckets[i].tail = buckets[i].head;
		buckets[i].tail->next = NULL;
	}

	int pos;
	for(i = 0; i < length; i++)
	{
		pos = n * head[i] / size;
		buckets[pos].tail->next = malloc(sizeof(Node));
		buckets[pos].tail = buckets[pos].tail->next;
		buckets[pos].tail->num = head[i];
		buckets[pos].tail->next = NULL;
	}


	//这里直接将一个桶中的数据按顺序放到最终的合并集合中去了
	Node *node;
	int *ptr;
	*head_sorted = malloc(sizeof(int)*size);
	ptr = *head_sorted;
	for(i = 0; i < n; i++)//do sort for every bucket
	{
		node = buckets[i].head;
		while(node->next != NULL)
		{
			*ptr = extract_min(node);
			ptr++;
		}
	}
	*end_sorted = ptr;
}

/*
 * 每次从链表中提取最小的一个
 */
int extract_min(Node *head)
{
	Node *temp, *ptr;
	ptr = head->next;
	temp = ptr;
	while(ptr != NULL)
	{
		if((temp->num) > (ptr->num))
			temp = ptr;
		ptr = ptr->next;
	}

	ptr = head;
	while(ptr->next != temp)
		ptr = ptr->next;
	ptr->next = temp->next;

	return temp->num;
}
