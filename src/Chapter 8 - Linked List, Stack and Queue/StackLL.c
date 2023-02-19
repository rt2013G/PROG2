#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
/*
 * Implementation of a stack using a singly linked list,
 * for simplicity every node stores an integer.
 * fill_stack and empty_stack are functions used for testing in order to avoid writing too many
 * extra lines of code.
 */
typedef struct Node {
    int val;
    struct Node *next;
} Node;

Node *create_node(int val)
{
    Node *new_node = calloc(1, sizeof(Node));
    new_node->val = val;
    new_node->next = NULL;
    return new_node;
}

bool push(Node **head, int val)
{
    Node *new_node = create_node(val);
    new_node->next = (*head);
    *head = new_node;
    return true;
}

bool pop(Node **head, int *val)
{
    if(*head == NULL) {
        printf("The stack is empty.\n");
        return false;
    }
    *val = (*head)->val;
    Node *tmp = (*head);
    (*head) = (*head)->next;
    free(tmp);
    return true;
}

bool fill_stack(Node **head)
{
    int t = 0;
    for(int i = 0; i < 10; i++) {
        push(head, t = rand() % 100);
    }
    return true;
}

bool empty_stack(Node **head)
{
    int val = 0;
    while(pop(head, &val)) {
           printf("Value: %d.\n", val);
    }
    return true;
}

int main()
{
    Node *head = create_node(5);
    fill_stack(&head);
    empty_stack(&head);
    return 0;
}
