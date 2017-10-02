/*
 * 这是关于堆的一些相关算法,主要包含
 * 堆排序，优先队列
 * by wareric@163.com
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "heapstd.h"

Heap* load_data(char *file);
void show_heap(Heap *heap);
void heapfree(Heap *heap);

int main(int argc, char *argv[])
{
	Heap *heap;
	if(argc < 2)
	{
		printf("Program should be run: ./%s argv\n", argv[0]);
		exit(EXIT_FAILURE);
	}else{
		heap = load_data(argv[1]);
	}

	printf("initial heap---------------------------\n");
	show_heap(heap);

	max_heapify(heap, 4);
	printf("after max_heapify at 4------------------\n");
	show_heap(heap);

	build_max_heap(heap);
	printf("after build_max_heap-------------------\n");
	show_heap(heap);
/*
	heap_sort(heap);
	printf("after heap_sort------------------------\n");
	show_heap(heap);
*/
	printf("after heap_maximum---------------------\n");
	printf("Node.key = %-6d-----------------------\n", \
			(heap_maximum(heap)).key );
	show_heap(heap);

	printf("after heap_extract_max---------------------\n");
	printf("Node.key = %6d----------------------------\n", \
			(heap_extract_max(heap)).key);
	show_heap(heap);

	printf("after increase node 4's key to 70-----------\n");
	heap_increase_key(heap, 4, 70);
	show_heap(heap);

	printf("after max_heap_insert 新插入的key=80--------\n");
	max_heap_insert(heap, 80);
	show_heap(heap);

	printf("free heap-------------------------\n");
	heapfree(heap);
	printf("-------------done!!!--------------\n");

	return 0;
}

Heap* load_data(char *file)
{
	Heap *heap = malloc(sizeof(Heap));
        FILE *fp;
	int heapsize=0;

        if((fp = fopen(file,"r")) == NULL)
        {
            printf("Can't open %s\n", file);
            exit(EXIT_FAILURE);
        }
        
        int size = 50, count = 0;
        Node *ptr, *array;
        
        array = malloc(sizeof(Node)*size);
        if(array == NULL){
            printf("load_array():malloc failure!");
            exit(EXIT_FAILURE);
        }
        ptr = array;
        
        while(fscanf(fp, "%d", &(ptr->key)) >= 0)
        {
	    heapsize++;
            count++;
            if(count == size)
            {
                size *= 2;
                array = realloc(array, size);
                if(array == NULL)
                {
                    printf("realloc failure!\n");
                    exit(EXIT_FAILURE);
                }
            }
            ptr++;
        }
        fclose(fp);

	heap->array = array;
	heap->size = heapsize;
	return heap;
}

void show_heap(Heap *heap)
{
	int i,linecount;
	for(int i = 0, linecount = 0; i < heap->size; i++, linecount++)
	{
		printf("%6d", (*(heap->array+i)).key);
		if(linecount == 4)
		{
			linecount = 0;
			putchar('\n');
		}
	}

	putchar('\n');
}

void heapfree(Heap *heap)
{
	free(heap->array);
	free(heap);
}
