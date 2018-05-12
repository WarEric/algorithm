/*
 * 计数排序，不是原址性的排序，耗费了额外的地址空间
 * 但是具有稳定性，但时间复杂度为O(n)，用地址空间换
 * 取了时间,算法来自于算法导论第8章
 * by wareric@163.com
 * 2017-11-5
 */
#include "ericio.h"

void counting_sort(int *head, int *tail, int *head_s, int *tail_s, int k);
int extract_max(int *head, int *tail);

int main(int argc, char *argv[])
{
	if(argc < 2)
	{
		printf("input should be %s datafile\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	int *head, *tail, *head_s, *tail_s;
	tail = load_array(argv[1], &head);
	head_s = malloc(sizeof(int)*(tail-head+1));
	tail_s = head_s + (tail-head);

	counting_sort(head, tail, head_s, tail_s, extract_max(head, tail));

	printf("before sort:\n");
	show_array(head, tail);

	printf("after sort:\n");
	show_array(head_s, tail_s);

	free(head);
	free(head_s);

	return 0;
}

/*
 * 使用计数排序输入的数据进行排序,
 * 要求排好序后数据存放的位置是已
 * 经分配好内存的
 * *head输入数据起始位置
 * *tail输入数据结束位置
 * *head_s排好序后存放的起始位置
 * *tail_s排好序后存放的结束位置
 */
void counting_sort(int *head, int *tail, int *head_s, int *tail_s, int k)
{
	int *c;
	int i;

	c = malloc(sizeof(int)*(k+1));
	for(i = 0; i <= k; i++)
		c[i] = 0;

	for(i = 0; i < (tail-head+1); i++ )
	{
		*(c + head[i]) = *(c + head[i]) + 1;
	}

	for(i = 1; i <= k; i++)
	{
		c[i] = c[i] + c[i-1];
	}

	for(i = (tail-head); i >= 0; i--)
	{
		*(head_s + *(c + head[i]) - 1) = head[i];
		*(c + head[i]) = *(c + head[i]) - 1;
	}

	free(c);
}

/*
 * 获取给定数组中最大的数
 */
int extract_max(int *head, int *tail)
{
	int *ptr = head, *end = tail+1;
	int k = 0;
	for( ; ptr != end; ptr++)
		if(*ptr > k)
			k = *ptr;

	return k;
}
