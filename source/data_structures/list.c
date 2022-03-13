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
    i_node_s* previous = NULL;
    i_node_s* iter = *list;
    i_node_s* next = NULL;

    // Iterate through list and reverse it in every point
    while (iter != NULL)
    {
        next = iter->next;
        iter->next = previous;
        previous = iter;
        iter = next;
    }
    
    // Update list to point to new first element
    *list = previous;
}

i_list_s merge_ls(i_list_s lhs, i_list_s rhs, i_operator_c comp)
{
    // Handle edge case: attempting empty list merge
    if (lhs == NULL)
        return rhs;
    if (rhs == NULL)
        return lhs;

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

    // Save first element of merged part
    tmp = result;

    // After the merge list is in reversed order, so reverse it again
    reverse_ls(&result);

    // Append to the end of new list what remained
    if (lhs == NULL)
        tmp->next = rhs;
    if (rhs == NULL)
        tmp->next = lhs;

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

i_node_s* merging_ls(i_list_s lhs, i_list_s rhs)
{
    // Calculate lengths of both lists
    int ll = length_ls(lhs);
    int rl = length_ls(rhs);

    // Move pointer of longer list difference times
    if (ll > rl)
    {
        for (int i = 0; i < ll - rl; ++i)
            lhs = lhs->next;
    } else
    {
        for (int i = 0; i < rl - ll; ++i)
            rhs = rhs->next;
    }

    // Find merging point
    while (lhs != NULL)
    {
        if (lhs == rhs)
            return lhs;
        lhs = lhs->next;
        rhs = rhs->next;
    }

    // No merging point, return NULL
    return NULL;
}

int length_ls(i_list_s list)
{
    // Compute length of the list
    int length = 0;
    while (list != NULL)
    {
        list = list->next;
        length++;
    }

    // Return length
    return length;
}