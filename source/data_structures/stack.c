//
// Created by mitos on 28.02.2022.
//

#include <stdlib.h>
#include <i_node.h>
#include <stack.h>

int empty_s(i_stack_t stack)
{
    return stack == NULL;
}

void push_s(i_stack_t* stack, int value)
{
    // Create new node and initialize its fields
    i_node_s* item = malloc(sizeof(i_node_s));
    item->data = value;
    item->next = *stack;

    // Add newly created item to the top of the stack
    *stack = item;
}

int pop_s(i_stack_t* stack)
{
    // Get pointer to topmost element and value stored in it
    i_node_s* item = *stack;
    int value = item->data;

    // Remove topmost element from the stack
    *stack = (*stack)->next;

    // Delete item
    free(item);

    // Return value from deleted element
    return value;
}