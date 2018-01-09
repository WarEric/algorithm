/*
 * randomized select是一个随机算法,其中利用了
 * random quick sort中的random partition进行
 * 递归查找，算法的最坏复杂度是O(n^2)，
 * 期望复杂度是O(n)
 * by wareric@163.com
 * 2018-1-9
 */
#include "ericio.h"
#include <time.h>

int randomized_select(int *head, int *end, int p, int r, int i);
int random_partition(int *head, int *end, int p, int r);
int partition(int *head, int *end, int p, int r);
void exchange(int *head, int i, int j);

int main(int argc, char *argv[])
{
	int *head, *last, p, r, i;
	if(argc < 2)
	{
		printf("input should be %s filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	last = load_array(argv[1], &head);
	
	printf("the array is:\n");
	show_array(head, last);
	srand((unsigned)time(NULL));
	while(1)
	{
		printf("input the range from p to r and the i's minium number in the form * * * \n");
		printf("if i is negative, program will exit!\n");
		scanf("%d %d %d", &p ,&r, &i);
		if(r < p)
		{
			printf("r should be largger than p\n");
			continue;
		}
		if(i < 0)
			break;
		else
			printf("the %d's minium number is %d\n\n\n", i, randomized_select(head, last+1, p, r, i));
	};

	free(head);
	return 0;
}

/*
 * 从给定数据范围内选出第i小的数
 * p 从p个下标开始
 * r 到r个下标结束
 * i 第i小的元素
 */
int randomized_select(int *head, int *end, int p, int r, int i)
{
	if(p == r)
		return head[p-1];
	int q, k;
	q = random_partition(head, end, p, r);
	k = q - p + 1;
	if(i == k)
		return head[q-1];
	else if(i < k)
		return randomized_select(head, end, p, q-1, i);
	else
		return randomized_select(head, end, q+1, r, i-k);
}

int random_partition(int *head, int *end, int p, int r)
{
	int i = rand()%(r-p+1);
	exchange(head, p+i, r);
	return partition(head, end, p ,r);
}

int partition(int *head, int *end, int p, int r)
{
	int x, i, j;
	x = *(head+r-1);
	i = p - 1;

	for(j = p; j < r; j++)
	{
		if(*(head+j-1) <= x)
		{
			i = i + 1;
			exchange(head, i, j);
		}
	}
	exchange(head, i+1, r);
	return i+1;
}

void exchange(int *head, int i, int j)
{
	int temp;
	temp = *(head+i-1);
	*(head+i-1) = *(head+j-1);
	*(head+j-1) = temp;
}
