#include "heapstd.h"

void max_heapify(Heap *h, int i)
{
	int l = 2*i;
	int r = 2*i + 1;
	int largest;

	if((l <= h->size) && (getkey(h,l) > getkey(h,i)) )
	{
		largest = l;
	}else{
		largest = i;
	}

	if((r <= h->size) && (getkey(h,r) > getkey(h,largest)))
		largest = r;

	if(largest != i)
	{
		node_exchange(h, i, largest);
		max_heapify(h, largest);
	}
}

void build_max_heap(Heap *h)
{
	int i;
	for(i = (h->size)/2; i > 0; i--)
		max_heapify(h, i);
}

void heap_sort(Heap *h)
{
	build_max_heap(h);
	int i, size = h->size;
	for(i = h->size; i > 1; i--)
	{
		node_exchange(h, 1, i);
		h->size -= 1;
		max_heapify(h, 1);
	}
	h->size = size;
}

Node heap_maximum(Heap *h)
{
	return *(h->array);
}

Node heap_extract_max(Heap *h)
{
	int size = h->size;
	if(size < 1)
	{
		printf("heap underflow\n");
		printf("this program will exit now\n");
		exit(EXIT_FAILURE);
	}

	Node node;
	node = *(h->array);
	node_exchange(h, 1, size);
	h->size = size - 1;
	max_heapify(h, 1);
	return node;
}

void heap_increase_key(Heap *h, int i, int key)
{
	if(key < getkey(h, i))
	{
		printf("new key is smaller than current key\n");
		return;
	}

	(h->array+i-1)->key = key;

	while((i > 1) && (getkey(h, i/2) < getkey(h, i)))
	{
		node_exchange(h, i/2, i);
		i = i/2;
	}
}

void max_heap_insert(Heap *h, int key)
{
	Node *ptr;
	int size = h->size + 1; 
	ptr = realloc(h->array, sizeof(Node)*size);
	if(ptr == NULL)
	{
		printf("realloc failure!\n");
		exit(EXIT_FAILURE);
	}
	h->array = ptr;
	h->size = size;

	(h->array+size-1)->key = INT_MIN;
	heap_increase_key(h, h->size, key);
}

void node_exchange(Heap *h, int i, int j)
{
	Node temp;
	temp = *(h->array+i-1);
	*(h->array+i-1) = *(h->array+j-1);
	*(h->array+j-1) = temp;
}

int getkey(Heap *h, int i)
{
	return (h->array+i-1)->key;
}
