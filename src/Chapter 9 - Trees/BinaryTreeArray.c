#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
/*
 * Implementation of a Binary Tree using an array of integers.
 * Given a binary tree represented as an array, the index of the left child is 2*n,
 * while the index of the right child is 2*n+1. Since arrays start at index 0, the actual indexes are shifted by +1.
 * visit_tree_recursive implements a pre-order recursive traversal of the tree.
 * fill_tree is a function used to test the algorithm by filling the tree with some numbers.
 */
typedef struct Tree {
    int size;
    int *items;
} Tree;

Tree *create_tree(int size)
{
    Tree *new_tree = calloc(1, sizeof(Tree));
    new_tree->size = size;
    new_tree->items = calloc(new_tree->size, sizeof(int));
    return new_tree;
}

bool visit_tree_recursive(Tree *tree, int index)
{
    if(index >= tree->size) return false;
    printf("Value: %d.\n", tree->items[index]);
    visit_tree_recursive(tree, 2 * index + 1);
    visit_tree_recursive(tree, 2 * index + 2);
    return true;
}

bool fill_tree(Tree *tree)
{
    for(int i = 0; i < tree->size; i++) {
        tree->items[i] = i;
    }
    return true;
}

int main()
{
    Tree *tree = create_tree(10);
    fill_tree(tree);
    visit_tree_recursive(tree, 0);
    return 0;
}
