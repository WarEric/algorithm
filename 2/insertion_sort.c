/*
 * 插入排序
 * 算法复杂度O(n^2)
 * by wareric@163.com
 * 2017-9-29
 */
#include "ericio.h"

void sort(int *fisrt, int *end);

int main(int argc,char *argv[])
{
    int *array_first, *array_last;

    if(argc < 2){
       printf("your input should be: ./%s argv", argv[0]);
       exit(EXIT_FAILURE);
    }else{
       array_last = load_array(argv[1], &array_first);
    }

    show_array(array_first, array_last);
    sort(array_first, array_last + 1);

    printf("finish insertion-sort !!!\n");
    show_array(array_first, array_last);

    return 0;
}

/*
 * 对数组使用插入排序进行排序
 * fisrt 输入数组的一个数
 * last 数组最后一位数的后一位
 */
void sort(int *first, int *end)
{
	int *ptr, *i;
	int temp;

	for (ptr = (first+1); ptr != end; ptr++)
	{
		temp = *ptr;
		i = ptr - 1;
		while((i >= first) && (*i > temp))
		{
			*(i+1) = *i;
			i--;
		}
		*(i+1) = temp;
	}
}
