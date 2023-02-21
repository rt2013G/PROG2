#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
/*
 * Implementation of a Binary Search Tree, for simplicity every node stores an integer
 * array_to_bst() creates a Binary Search Tree from a sorted array.
 * visit_tree_recursive() executes an in-order recursive traversal of the tree.
 */
typedef struct Node {
    int value;
    struct Node *left_child;
    struct Node *right_child;
} Node;

Node *create_node(int val)
{
    Node *new_node = calloc(1, sizeof(Node));
    new_node->value = val;
    new_node->left_child = NULL;
    new_node->right_child = NULL;
    return new_node;
}

Node *array_to_bst(int *array, int left, int right)
{
    if(left > right) return NULL;
    int mid = (left + right) / 2;
    Node *root = create_node(array[mid]);
    root->left_child = array_to_bst(array, left, mid - 1);
    root->right_child = array_to_bst(array, mid + 1, right);
    return root;
}

bool visit_tree_recursive(Node *root)
{
    if(root == NULL) return true;
    visit_tree_recursive(root->left_child);
    printf("Value: %d\n", root->value);
    visit_tree_recursive(root->right_child);
    return true;
}

int main()
{
    int size = 8;
    int test_array[] = {2, 3, 5, 12, 13, 22, 123, 992};
    Node *root = array_to_bst(test_array, 0, size - 1);
    visit_tree_recursive(root);
    return 0;
}
