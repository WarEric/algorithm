/*
 * 这是对最大子数组的一种改进
 * 复杂度为O(nlgn)
 * 算法来源于算法导论
 * by wareric@163.com  2017-9-24
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct subarray{
    int *low;
    int *high;
    long long sum;
};

void show_array(int *head,int *tail);
void show_result(struct subarray result,int *head);
int* load_array(char *file,int **first);
struct subarray max_subarray(int *first, int *last);

int main(int argc,char *argv[])
{
    int *A_first, *A_last;
    struct subarray result;

    if(argc < 2)
    {
        printf("Your input should be:%s argv1\n",argv[0]);
        exit(EXIT_FAILURE);
    }else{
        A_last = load_array(argv[1], &A_first);
    }

    show_array(A_first,A_last);
    result =  max_subarray(A_first,A_last);
    show_result(result,A_first);
    free(A_first);

    puts("Done!\n");
    return 0;
}

/*
 * 使用线性算法求解
 * 最大子数组问题
 */
struct subarray max_subarray(int *first, int *last)
{
	long long max_sum = LONG_MIN;
	long long ending_here_sum = LONG_MIN;
	
	int *ending_here_high, *ending_here_low;
	int *low, *high;
        int *ptr, *end = last+1;
	for(ptr = first; ptr != end; ptr++)
	{
	    ending_here_high = ptr;
  	    if(ending_here_sum > 0)
		   ending_here_sum = ending_here_sum + *ptr;
	    else
            {
                ending_here_low = ptr;
		ending_here_sum = *ptr;
	    }
	    if(ending_here_sum > max_sum)
	    {
		max_sum = ending_here_sum;
		low = ending_here_low;
		high = ending_here_high;
	    }
        }
	
	return (struct subarray){low, high, max_sum};
}

/*
 * 输入数组的头部和尾部
 * 将数组数据打印出来
 */
void show_array(int *head,int *tail)
{
     int count = 0;
    
     printf("The length of the array is: %ld\n", (tail-head)+1);
     puts("The array is:");

     int *ptr = head, *end = tail+1;
     for (; ptr != end; ptr++)
     {
         printf("%6d", *ptr);
         if(0 == (++count)%4)
            putchar('\n');
     }
     putchar('\n');

    if(count != (tail-head)+1 )
       printf("count = %d, this isn\'t consistent with %ld\n", count, (tail-head)+1);
}

/*
 * 输入解出来的子数组和原数组的起始点
 * 打印出最大的和，以及起始和结束点的位置
 */
void show_result(struct subarray result,int *head)
{
    int *ptr, *end = result.high+1;
    int count = 0;
  
    printf("The max sum of the array is: %lld\n", result.sum);
    printf("The subarray is from A[%ld] to A[%ld] \n", (result.low - head) + 1,\
            (result.high - head) + 1);
    printf("The following is the selected subarray:\n");

    for(ptr = result.low; ptr != end; ptr++)
    {
        printf("%6d", *ptr);
        if(0 == (++count)%4)
           putchar('\n');
    }
    putchar('\n');
}

/* 从文件中读取数据，并且将输入的指针置为数组的起始点
 * 同时返回数组最后一位数的指针
 */
int* load_array(char *file,int **first)
{
    FILE *fp;
    if((fp = fopen(file,"r")) == NULL)
    {
        printf("Can't open %s\n", file);
        exit(EXIT_FAILURE);
    }
    
    int size = 50, count = 0;
    int *ptr,*head;

    head = malloc(sizeof(int)*size);
    if(head == NULL){
        printf("load_array():malloc failure!");
        exit(EXIT_FAILURE);
    }
    ptr = head;

    while(fscanf(fp, "%d", ptr) >= 0)
    {
        count++;
        if(count == size)
        {
            size *= 2;
            head = realloc(head, size);
            if(head == NULL)
            {
                printf("realloc failure!\n");
                exit(EXIT_FAILURE);
            }
        }
        ptr++;
    }
    fclose(fp);
    *first = head;    

    return (ptr-1);
}
