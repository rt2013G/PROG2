#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
/*
 * Implementation of a MaxHeap using an array of integers.
 * heapify() transforms a given BinaryTree represented with an array to a MaxHeap.
 * Since leaf nodes are already heaps, build_heap performs heapify on every non-leaf node.
 * fill_heap() fills the tree with some random numbers.
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

bool heapify(Heap *heap, int index_of_parent)
{
    int max = index_of_parent;
    int left_child = index_of_parent * 2 + 1;
    int right_child = index_of_parent * 2 + 2;
    if(left_child < heap->size && heap->items[left_child] > heap->items[max]) {
        max = left_child;
    }
    if(right_child < heap->size && heap->items[right_child] > heap->items[max]) {
        max = right_child;
    }
    if(max != index_of_parent) {
        swap(&heap->items[index_of_parent], &heap->items[max]);
        heapify(heap, max);
    }
    return true;
}

bool build_heap(Heap *heap)
{
    for(int i = heap->size / 2 - 1; i >= 0; i--) {
        heapify(heap, i);
    }
    return true;
}

bool fill_heap(Heap *heap)
{
    for(int i = 0; i < heap->size; i++) {
        heap->items[i] = i;
    }
    return true;
}

bool visit_heap_recursive(Heap *heap, int index) {
    if(index >= heap->size) return true;
    printf("Value: %d.\n", heap->items[index]);
    visit_heap_recursive(heap, index * 2 + 1);
    visit_heap_recursive(heap, index * 2 + 2);
    return true;
}

int main()
{
    Heap *heap = create_heap(10);
    fill_heap(heap);
    build_heap(heap);
    visit_heap_recursive(heap, 0);
    return 0;
}
