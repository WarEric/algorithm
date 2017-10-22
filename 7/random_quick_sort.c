/*
 * random quick sort 是对quick sort的改进
 * 将每一次取最后一位作为主元的情况改为随
 * 机取其中的一位作为主元,算法的最坏复杂度
 * 还是O(n^2)，平均复杂度是O(nlgn)
 * by wareric@163.com
 * 2017-10-22
 */
#include "ericio.h"
#include <time.h>

void random_quick_sort(int *head, int* end, int p, int r);
int random_partition(int *head, int *end, int p, int r);
int partition(int *head, int *end, int p, int r);
void exchange(int *head, int i, int j);

int main(int argc, char *argv[])
{
	int *head, *last;
	if(argc < 2)
	{
		printf("input should be %s filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	last = load_array(argv[1], &head);
	printf("before sort:\n");
	show_array(head, last);

	srand((unsigned)time(NULL));
	random_quick_sort(head, last+1, 1, last-head+1);
	printf("afer random_quick_sort:\n");
	show_array(head, last);
	free(head);
	 
	return 0;
}

void random_quick_sort(int *head, int* end, int p, int r)
{
	int q;
	if(p < r)
	{
		q = random_partition(head, end, p, r);
		random_quick_sort(head, end, p, q-1);
		random_quick_sort(head, end, q+1, r);
	}
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
