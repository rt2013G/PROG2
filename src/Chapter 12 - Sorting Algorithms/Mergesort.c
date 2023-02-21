#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
/*
 * Implementation of the Mergesort algorithm.
 * The algorithm is not in-place as it needs an extra array for merging.
 * The algorithm performs log2n merges. Since the merge() function has a time complexity of O(n),
 * the time complexity of mergesort() is O(n * log2n).
 */
bool merge(int *array, int left, int mid, int right)
{
    int len_array_a = mid - left + 1;
    int len_array_b = right - mid;
    int *array_a = calloc(len_array_a, sizeof(int));
    int *array_b = calloc(len_array_b, sizeof(int));
    for(int i = 0; i < len_array_a; i++) {
        array_a[i] = array[left + i];
    }
    for(int i = 0; i < len_array_b; i++) {
        array_b[i] = array[mid + 1 + i];
    }
    int i = 0;
    int j = 0;
    int k = left;
    while(i < len_array_a && j < len_array_b) {
        if(array_a[i] <= array_b[j]) {
            array[k++] = array_a[i++];
        } else {
            array[k++] = array_b[j++];
        }
    }
    while(i < len_array_a) {
        array[k++] = array_a[i++];
    }
    while(j < len_array_b) {
        array[k++] = array_b[j++];
    }
    return true;
}

bool mergesort(int *array, int left, int right)
{
    if(left < right) {
        int mid = (left + right - 1) / 2;
        mergesort(array, left, mid);
        mergesort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
    return true;
}

bool print_array(int array[], int size)
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
    mergesort(array, 0, size - 1);
    print_array(array, size);
    return 0;
}
