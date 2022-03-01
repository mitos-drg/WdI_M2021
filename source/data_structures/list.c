//
// Created by mitos on 28.02.2022.
//

#include <stdlib.h>
#include <i_node.h>
#include <list.h>
#include <function.h>

void push_back_ls(i_list_s list, int value)
{
    // Create new list node and initialize its fields
    i_node_s* item = malloc(sizeof(i_node_s));
    item->data = value;
    item->next = NULL;

    // Travers list to find last node
    while (list->next)
        list = list->next;

    // Append new node at the end of the list
    list->next = item;
}

void push_front_ls(i_list_s* list, int value)
{
    // Create new list node and initialize its fields
    i_node_s* item = malloc(sizeof(i_node_s));
    item->data = value;
    item->next = *list;

    // Move list pointer to new beginning of the list
    *list = item;
}

int pop_front_ls(i_list_s* list)
{
    // Get pointer to element to delete and its value
    i_node_s* item = *list;
    int value = item->data;

    // Move list forward
    *list = (*list)->next;

    // Delete item
    free(item);

    // Return value from deleted element
    return value;
}

void reverse_ls(i_list_s* list)
{
    // If list contains only one element return, as it is reversed (kind of)
    if ((*list)->next == NULL)
        return;

    // Create node pointers to store previous element, current one and the next one and initialize their values
    // respectfully to: first element, second one and to nothing (NULL)
    i_node_s* previous = *list;
    i_node_s* iter = previous->next;
    i_node_s* next = NULL;

    // Iterate through list and reverse it in every point
    while (iter->next != NULL)
    {
        next = iter->next;
        iter->next = previous;
        iter = next;
    }
}

i_list_s merge_ls(i_list_s lhs, i_list_s rhs, i_operator_c comp)
{
    // Create new list and temporary node pointer
    i_list_s result = NULL;
    i_node_s* tmp = NULL;

    // While both list aren't empty
    while (lhs != NULL && rhs != NULL)
    {
        // Store current first item
        tmp = result;
        // Compare elements from both list and add whichever win the comparison, then move appropriate list pointer
        if (comp(lhs->data, rhs->data))
        {
            result = lhs;
            lhs = lhs->next;
        }
        else
        {
            result = rhs;
            rhs = rhs->next;
        }

        // Add new element to result list
        result->next = tmp;
    }

    // Append remaining elements from left list
    while (lhs != NULL)
    {
        tmp = result;
        result = lhs;
        lhs = lhs->next;
        result->next = tmp;
    }

    // Append remaining elements from right list
    while (rhs != NULL)
    {
        tmp = result;
        result = rhs;
        rhs = rhs->next;
        result->next = tmp;
    }

    // After the merge list is in reversed order, so reverse it again
    reverse_ls(&result);

    // Return resulting list
    return result;
}

int is_ordered_ls(i_list_s list)
{
    // Check if list is not empty
    if (list != NULL)
    {
        // Iterate through list to the second but last element
        while (list->next != NULL)
        {
            // If next is smaller than this, then list isn't ordered (ascending), so return false
            if (list->data > list->next->data)
                return 0;
        }
    }

    // List is ordered, return true
    return 1;
}

void foreach_ls_const(i_list_s list, i_method_c operation)
{
    // Get list iterator, could use list just as well, but for sake of future possible expansions to the list we do
    // it that way
    i_node_s* iter = list;

    // Iterate through list and execute the operation on every element
    while (iter != NULL)
    {
        operation(iter->data);
        iter = iter->next;
    }
}

void foreach_ls(i_list_s list, i_method operation)
{
    // Get list iterator, could use list just as well, but for sake of future possible expansions to the list we do
    // it that way
    i_node_s* iter = list;

    // Iterate through list and execute the operation on every element
    while (iter != NULL)
    {
        operation(&iter->data);
        iter = iter->next;
    }
}