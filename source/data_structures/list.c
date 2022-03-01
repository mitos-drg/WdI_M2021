//
// Created by mitos on 28.02.2022.
//

#include <stdlib.h>
#include <i_node.h>
#include <list.h>

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