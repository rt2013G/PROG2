#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
/*
 * Implementation of the Heapsort algorithm. The heap implementation is the same as "Chapter 9/Heap.c".
 * The heapify function takes O(log n), and is called once for every parent node when first building the heap,
 * then n - 1 times to repair the heap property in the heapsort() function.
 * Therefore, the time complexity of the Heapsort algorithm is O(n * log n).
 */
typedef struct Heap {
    int size;
    int *items;
} Heap;

Heap *create_heap(int size)
{
    Heap *new_heap = calloc(1, sizeof(Heap));
    new_heap->size = size;
    new_heap->items = calloc(new_heap->size, sizeof(int));
    return new_heap;
}

bool swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
    return true;
}

bool heapify(Heap *heap, int size, int index_of_parent)
{
    int max = index_of_parent;
    int left_child = index_of_parent * 2 + 1;
    int right_child = index_of_parent * 2 + 2;
    if(left_child < size && heap->items[left_child] > heap->items[max]) {
        max = left_child;
    }
    if(right_child < size && heap->items[right_child] > heap->items[max]) {
        max = right_child;
    }
    if(max != index_of_parent) {
        swap(&heap->items[index_of_parent], &heap->items[max]);
        heapify(heap, size, max);
    }
    return true;
}

bool fill_heap(Heap *heap)
{
    for(int i = 0; i < heap->size; i++) {
        heap->items[i] = rand() % 100;
    }
    return true;
}

bool print_heap(Heap *heap)
{
    for(int i = 0; i < heap->size; i++) {
        printf("Value: %d.\n", heap->items[i]);
    }
    return true;
}

bool heap_sort(Heap *heap)
{
    for(int i = heap->size / 2 - 1; i >= 0; i--) {
        heapify(heap, heap->size, i);
    }
    for(int i = heap->size - 1; i >= 0; i--) {
        swap(&heap->items[0], &heap->items[i]);
        heapify(heap, i, 0);
    }
    return true;
}

int main()
{
    Heap *heap = create_heap(10);
    fill_heap(heap);
    print_heap(heap);
    heap_sort(heap);
    printf("\n");
    print_heap(heap);

    return 0;
}
