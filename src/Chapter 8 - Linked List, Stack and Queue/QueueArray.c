#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
/*
 * Implementation of a Queue using a dynamically allocated circular array.
 * Function create_queue acts similarly as a constructor would in an object-oriented language.
 * Functions enqueue and dequeue implement the operations of enqueue and dequeue,
 * they return false if the operation fail, otherwise they return true.
 * print_queue and fill_queue are test functions used to empty and fill the whole queue
 * without having to write too many extra lines of code.
 */
typedef struct Queue {
    int size;
    int *items;
    int head;
    int tail;
    int num_of_elems;
} Queue;

Queue *create_queue(int len)
{
    Queue *new_queue = calloc(1, sizeof(Queue));
    new_queue->size = len;
    new_queue->items = calloc(new_queue->size, sizeof(int));
    new_queue->head = -1;
    new_queue->tail = -1;
    new_queue->num_of_elems = 0;
    return new_queue;
}

bool enqueue(Queue *q, int val)
{
    if(q->num_of_elems >= q->size) {
        printf("The queue is full.\n");
        return false;
    }
    q->tail = q->head + q->num_of_elems;
    q->tail = q->tail % q->size;
    q->items[q->tail] = val;
    (q->num_of_elems)++;
    return true;
}

bool dequeue(Queue *q, int *val)
{
    if(q->num_of_elems == 0) {
        printf("The queue is empty.\n");
        return false;
    }
    *val = q->items[q->head];
    (q->head)++;
    q->head = q->head % q->size;
    (q->num_of_elems)--;
    return true;
}

bool print_queue(Queue *q)
{
    int val;
    while(dequeue(q, &val)) {
        printf("Value: %d.\n", val);
    }
    return true;
}

bool fill_queue(Queue *q)
{
    int t = 0;
    while(enqueue(q, t = rand() % 100));
    return true;
}

int main()
{
    Queue *q = create_queue(5);
    fill_queue(q);
    print_queue(q);
    return 0;
}
