#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
/*
 * Implementation of a Queue using a singly linked list
 * for simplicity every node stores an integer
 * fill_queue and empty_queue are functions used for testing in order to avoid writing too many
 * extra lines of code.
 */
typedef struct Node {
    int val;
    struct Node *next;
} Node;

typedef struct Queue {
    Node *head;
    Node *tail;
} Queue;

Node *create_node(int val)
{
    Node *new_node = calloc(1, sizeof(Node));
    new_node->val = val;
    new_node->next = NULL;
    return new_node;
}

// Technically this function doesn't do anything, but I believe it's good to have as it helps with scalability
Queue *init_queue()
{
    Queue *new_queue = calloc(1, sizeof(Queue));
    new_queue->head = NULL;
    new_queue->tail = NULL;
    return new_queue;
}

bool enqueue(Queue *q, int val)
{
    Node *new_node = create_node(val);
    if(q->tail != NULL) {
        q->tail->next = new_node;
    }
    q->tail = new_node;
    if(q->head == NULL) {
        q->head = new_node;
        q->head->next = q->tail;
    }
    return true;
}

bool dequeue(Queue *q, int *val)
{
    if(q->head == NULL) {
        printf("The queue is empty.\n");
        return false;
    }
    *val = q->head->val;
    Node *tmp = q->head;
    q->head = q->head->next;
    free(tmp);
    return true;
}

bool fill_queue(Queue *q)
{
    for(int i = 0; i < 10; i++) {
        enqueue(q, i);
    }
    return true;
}

bool empty_queue(Queue *q)
{
    int val;
    while(dequeue(q, &val)) {
        printf("Value: %d.\n", val);
    }
    return true;
}

int main()
{
    Queue *queue = init_queue();
    fill_queue(queue);
    empty_queue(queue);

    return 0;
}
