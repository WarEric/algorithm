/*
 * 快速排序
 * 算法复杂度最坏情况下O(n2)
 * 平均情况O(nlgn)
 * by wareric@163.com
 * 2017-10-15
 */
#include "ericio.h"

void quick_sort(int *head, int *end, int p, int r);
int partition(int *head, int *end, int p, int r);
void exchange(int *head, int i, int j);

int main(int argc, char *argv[])
{
	int *array_first, *array_last;

	if(argc < 2){
		printf("your input should be: ./%s argv", argv[0]);
		exit(EXIT_FAILURE);
	}else{
		array_last = load_array(argv[1], &array_first);
	}

	printf("before sort:\n");
	show_array(array_first, array_last);

	quick_sort(array_first, array_last + 1, 1, array_last-array_first+1);
	printf("finish quick-sort:\n");
	show_array(array_first, array_last);

	return 0;
}

void quick_sort(int *head, int *end, int p, int r)
{
	int q;
	if(p < r)
	{
		q = partition(head, end, p, r);
		quick_sort(head, end, p, q-1);
		quick_sort(head, end, q+1, r);
	}
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
