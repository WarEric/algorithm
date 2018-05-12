/*
 * 归并排序，算法复杂度为O(nlgn)
 * by wareric@163.com
 * 2017-9-29
 */
#include "ericio.h"

void sort(int *p, int *r);
void merge(int *p, int *q, int *r);

int main(int argc, char *argv[])
{
	int *array_first, *array_last;

	if(argc < 2)
	{
		printf("input should be: ./%s argv\n", argv[0]);
		exit(EXIT_FAILURE);
	}else{
		array_last = load_array(argv[1], &array_first);
	}

	show_array(array_first, array_last);
	sort(array_first, array_last);

	printf("After merge-sort !!!\n\n");
	show_array(array_first, array_last);

	return 0;
}

/*
 * 使用递归的方式进行排序
 */
void sort(int *p, int *r)
{
	if(p < r)
	{
		int *q = p+(int)((r-p)/2);
		sort(p, q);
		sort(q + 1, r);
		merge(p, q, r);
	}
}

/*
 * 对p--q,和(q+1)--r这两个已经排好序的数组进行合并
 */
void merge(int *p, int *q, int *r)
{
	int array_sorted[r - p +1];
	int * end1 = q + 1, * end2 = r + 1;
	int *i = p, *j = q + 1;
	int count;

	for(count = 0; (i != end1) && (j != end2); count++)
	{
		if(*i < *j)
		{
			array_sorted[count] = *i;
			i++;
		}else{
			array_sorted[count] = *j;
			j++;
		}
	}
	count--;

	if(i == end1)//如果i先到达了末尾，那么j一定没有先到末尾
	{
		while(j != end2)
		{
			count++;
			array_sorted[count] = *j;
			j++;
		}
	}else{
		while(i != end1)
		{
			count++;
			array_sorted[count] = *i;
			i++;
		}
	}

	if(count != (r-p))
	{
		printf("merge之后的数据长度与输入长度不符!!!\n");
		printf("count = %d, r-p = %ld\n", count, r-p);
		printf("this program will exit.\n");
		exit(EXIT_FAILURE);
	}

	int m;
	for(m = 0; (m <= count) && (p != end2); m++, p++)
	{
		*p = array_sorted[m];
	}

}
