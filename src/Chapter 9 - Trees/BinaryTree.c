#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
/*
 * Implementation of a Binary Tree, for simplicity every node stores an integer.
 * visit_tree_recursive implements a pre-order recursive traversal of the tree.
 * function build_tree adds some nodes to the tree
 */
typedef struct Node {
    int value;
    struct Node *left_child;
    struct Node *right_child;
} Node;

Node *create_node(int value)
{
    Node *new_node = calloc(1, sizeof(Node));
    new_node->value = value;
    new_node->left_child = NULL;
    new_node->right_child = NULL;
    return new_node;
}

bool visit_tree_recursive(Node *node)
{
    if(node == NULL) return true;
    printf("Value: %d\n", node->value);
    visit_tree_recursive(node->left_child);
    visit_tree_recursive(node->right_child);
    return true;
}

bool build_tree(Node *root)
{
    root->left_child = create_node(4);
    root->right_child = create_node(5);
    root->right_child->left_child = create_node(3);
    root->right_child->right_child = create_node(1);
    return true;
}

int main()
{
    Node *root = create_node(2);
    build_tree(root);
    visit_tree_recursive(root);
    return 0;
}
