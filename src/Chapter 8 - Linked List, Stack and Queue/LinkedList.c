#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
/*
 * Implementation of a doubly linked list, for simplicity every node stores an integer.
 * visit_list and fill_list are functions used for testing in order to avoid writing too many
 * extra lines of code.
 */
typedef struct Node {
    int val;
    struct Node *next;
    struct Node *prev;
} Node;

Node *create_node(int val)
{
    Node *new_node = calloc(1, sizeof(Node));
    new_node->val = val;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

bool insert_node_after(Node **node_prev, Node *node_to_insert)
{
    if((*node_prev) == NULL) {
        (*node_prev) = node_to_insert;
        return true;
    }
    if((*node_prev)->next == NULL) {
        (*node_prev)->next = node_to_insert;
        return true;
    }
    (*node_prev)->next->prev = node_to_insert;
    node_to_insert->next = (*node_prev)->next;
    (*node_prev)->next = node_to_insert;
    node_to_insert->prev = *node_prev;
    return true;
}

bool visit_list(Node **head)
{
    Node *curr = (*head);
    while(curr != NULL) {
        printf("Value: %d.\n", curr->val);
        curr = curr->next;
    }
    return true;
}

bool fill_list(Node **head)
{
    Node *curr = *(head);
    for(int i = 0; i < 10; i++) {
        insert_node_after(&curr, create_node(rand() % 100));
        curr = curr->next;
    }
    return true;
}

int main()
{
    Node *head = create_node(5);
    fill_list(&head);
    visit_list(&head);
    return 0;
}
