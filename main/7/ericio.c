#include "ericio.h"

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

}

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
