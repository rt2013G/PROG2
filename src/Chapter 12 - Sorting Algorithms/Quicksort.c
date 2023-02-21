#include "stdio.h"
#include "stdbool.h"
/*
 * Implementation of the QuickSort algorithm, the pivot is chosen as the last element of the array.
 * The Quicksort algorithm has a time complexity in the average and best case of O(n * log n),
 * this happens when the pivot chosen is the middle element of the sorted array or close to the middle.
 * When the pivot is either the smallest or greatest element of the array,
 * the algorithm divides the array in two sub-arrays, one of which is empty while the other contains n - 1 elements.
 * Thus, in the worst case, Quicksort has a time complexity of O(n^2).
 */
bool swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
    return true;
}

int partition(int *array, int left, int right)
{
    int pivot = array[right];
    int i = left - 1;
    for(int j = left; j < right; j++) {
        if(array[j] < pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[right]);
    return i + 1;
}

bool quicksort(int *array, int left, int right)
{
    if(left < right) {
        int part = partition(array, left, right);
        quicksort(array, left, part - 1);
        quicksort(array, part + 1, right);
    }
    return true;
}

bool print_array(int *array, int size)
{
    for(int i = 0; i < size; i++) {
        printf("Value: %d.\n", array[i]);
    }
    return true;
}

int main()
{
    int size = 8;
    int array[] = {12, 5, 7, 17, 83, 11, 6, 3};
    quicksort(array, 0, size - 1);
    print_array(array, size);
    return 0;
}
