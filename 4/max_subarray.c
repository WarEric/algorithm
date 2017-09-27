/*
 * 这是分治算法求解最大子数组的程序
 * 该算法利用了递归求解，复杂度为O(nlgn)
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
struct subarray max_subarray(int *low, int *high);
struct subarray crossing_subarray(int *low, int *mid,int *high);

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
 * 计算横跨mid节点的最大子数组
 */
struct subarray crossing_subarray(int *low, int *mid,int *high)
{
    long long left_sum = LONG_MIN, sum = 0;
    int *max_left;
//this is used to record the position of start point
//when we find the max subarrary.

    int *ptr, *head = low-1;
    for (ptr = mid; ptr != head; ptr--)
    {
        sum += *ptr;
        if (sum > left_sum)
        {
            left_sum = sum;
            max_left = ptr;
        }
    }

    long long right_sum = LONG_MIN;
    int *max_right;
    int *end = high + 1;
    sum = 0;
    for(ptr = mid + 1; ptr != end; ptr++ )
    {
        sum += *ptr;
        if(sum > right_sum)
        {
            right_sum = sum;
            max_right = ptr;
        }
    }

   return (struct subarray){max_left, max_right, left_sum + right_sum};
}

/*
 * 采用分治法求解最大子数组问题
 */
struct subarray max_subarray(int *low, int *high)
{
    if(high == low){
       return (struct subarray){low, high, *low};
    }else{
       int *mid = low + ((high - low) / 2);
  
       struct subarray left = max_subarray(low, mid);
       struct subarray right = max_subarray(mid+1, high);
       struct subarray crossing = crossing_subarray(low, mid, high);

       if ((left.sum >= right.sum) && (left.sum >= crossing.sum))
            return left;
       else if((right.sum >= left.sum) && (right.sum >= crossing.sum))
            return right;
       else
            return crossing;
    }
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
