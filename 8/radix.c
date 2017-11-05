/*
 * 对基数排序所对应数据结构的读入
 * 和输出的实现
 * by wareric@163.com
 * 2017-11-5
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "radix.h"

void show_array(Data *head, Data *end)
{
     int count = 0;
    
     printf("The length of the array is: %ld\n", (end-head) );
     puts("The array is:");

     Data *ptr;
     for (ptr = head; ptr != end; ptr++)
     {
         printf("%6ld", ptr->num);
         if(0 == (++count)%4)
            putchar('\n');
     }
     putchar('\n');

}

Data* load_array(char *file, Data **first)
{
    FILE *fp;
    if((fp = fopen(file,"r")) == NULL)
    {
        printf("Can't open %s\n", file);
        exit(EXIT_FAILURE);
    }
    
    int size = 50, count = 0;
    Data *ptr,*head;

    head = malloc(sizeof(Data)*size);
    if(head == NULL){
        printf("load_array():malloc failure!");
        exit(EXIT_FAILURE);
    }
    ptr = head;
    int j, temp;

    while(fscanf(fp, "%d", &temp) >= 0)
    {
	    ptr->num = temp;
	    for(j = (DIGIT-1); j >= 0; j--)
	    {
		    (ptr->digit)[j] = temp%10;
		    temp /= 10;
	    }

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

    return ptr;
}
