#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
/*
 *  Implementation of a stack using a dynamically allocated array.
 *  Function create_stack acts similarly as a constructor would in an object-oriented language.
 *  Functions push and pop perform the basic operations of push and pop on the stack,
 *  they return false if the operation fails, otherwise they return true.
 *  print_stack and fill_stack are test functions used to empty and fill the whole stack
 *  without having to write too many extra lines of code.
 */
typedef struct Stack {
    int size;
    int *items;
    int head;
} Stack;

Stack *create_stack(int len)
{
    Stack *new_stack = calloc(1, sizeof(Stack));
    new_stack->size = len;
    new_stack->items = calloc(new_stack->size, sizeof(int));
    new_stack->head = -1;
    return new_stack;
}

bool push(Stack *s, int value)
{
    if(s->head >= s->size - 1) {
        printf("The stack is full.\n");
        return false;
    }
    (s->head)++;
    s->items[s->head] = value;
    return true;
}

bool pop(Stack *s, int *value)
{
    if(s->head == -1) {
        printf("The stack is empty.\n");
        return false;
    }
    *value = s->items[s->head];
    (s->head)--;
    return true;
}

bool print_stack(Stack *s)
{
    int val;
    while(pop(s, &val)) {
        printf("Value: %d.\n", val);
    }
    return true;
}

bool fill_stack(Stack *s)
{
    for(int i = 0; i < s->size; i++) {
        push(s, i);
    }
    return true;
}

int main()
{
    Stack *stack = create_stack(5);
    fill_stack(stack);
    print_stack(stack);

    return 0;
}
