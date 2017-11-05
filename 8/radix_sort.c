/*
 * radix_sort基数排序，以前用于卡片机上
 * 同样的是不原址性排序，但是由于使用了
 * 计数排序，可以保证稳定性,算法复杂度为
 * O(b/r(n+2^n)) b表示位数 r<= b 
 * 其中稳定排序算法复杂度为O(n+k)
 * 当b为常数，复杂度为O(n)
 *
 * 该算法中的位数长度在radix.h中用宏进行了定义
 * 使用时记得修改为符合数据结构的大小
 *
 * by wareric@163.com
 * 2017-11-5
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "radix.h"

void radix_sort(Data **head, Data **end, int k, int d);
void counting_sort(Data *head, Data *end, Data *head_s, Data *end_s, int k, int d);

int main(int argc, char *argv[])
{
	if(argc < 2)
	{
		printf("input should be %s datafile d", argv[0]);
		exit(EXIT_FAILURE);
	}

	Data *head, *end;
	end = load_array(argv[1], &head);

	printf("before sort:\n");
	show_array(head, end);

	radix_sort(&head, &end, 9, DIGIT);
	printf("after sort:\n");
	show_array(head, end);

	free(head);
	return 0;
}

/*
 * 使用基数排序输入的数据进行排序,
 * *head输入数据起始位置
 * *tail输入数据结束位置
 * k 每个位置元素范围
 * d 位数长度
 */
void radix_sort(Data **head, Data **end, int k, int d)
{
	int i;
	int length = (*end - *head);
	Data *temp_h, *temp_e, *temp;
	temp_h = malloc(sizeof(Data)*length);
	temp_e = temp_h+length;
	for(i = d-1; i >= 0; i--)
	{
		counting_sort(*head, *end, temp_h, temp_e, k, i);
		//交换位置，重复利用这两块堆
		temp = *head;
		*head = temp_h;
		temp_h = temp;
		temp = *end;
		*end = temp_e;
		temp_e = temp;
	}

	free(temp_h);
}

/*
 * 使用计数排序输入的数据进行排序,
 * 要求排好序后数据存放的位置是已
 * 经分配好内存的
 * *head输入数据起始位置
 * *tail输入数据结束位置
 * *head_s排好序后存放的起始位置
 * *tail_s排好序后存放的结束位置
 * k 元素范围
 * d 对第几个位置排序
 */
void counting_sort(Data *head, Data *end, Data *head_s, Data *end_s, int k, int d)
{
	int *c;
	int i;

	c = malloc(sizeof(int)*(k+1));
	for(i = 0; i <= k; i++)
		c[i] = 0;

	for(i = 0; i < (end - head); i++ )
	{
		*(c + (head+i)->digit[d]) = *(c + (head+i)->digit[d]) + 1;
	}

	for(i = 1; i <= k; i++)
	{
		c[i] = c[i] + c[i-1];
	}

	for(i = end-head-1; i >= 0; i--)
	{
		memcpy( head_s + *(c + (head+i)->digit[d]) - 1, head+i, sizeof(Data));
		*(c + (head+i)->digit[d]) = *(c + (head+i)->digit[d]) - 1;
	}

	free(c);
}
