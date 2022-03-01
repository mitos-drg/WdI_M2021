//
// Created by mitos on 28.02.2022.
//

#include <stdlib.h>
#include <i_node.h>
#include <queue.h>

int empty_q(i_queue_o queue)
{
    return queue.head == NULL && queue.tail == NULL;
}

void push_q(i_queue_o* queue, int value)
{
    // Create new node and initialize its fields
    i_node_s* item = malloc(sizeof(i_node_s));
    item->data = value;
    item->next = NULL;

    // Check if queue is empty
    if (queue->tail != NULL)
    {
        // It's not, add new item to the end of it and move tail to point to it
        queue->tail->next = item;
        queue->tail = item;
    } else
    {
        // Cause queue is empty its head and tail should both point to the only (new) element
        queue->tail = queue->head = item;
    }
}

int pop_q(i_queue_o* queue)
{
    // Get pointer to the first element and remove it from queue
    i_node_s* item = queue->head;
    queue->head = queue->head->next;

    // If queue is empty set tail to NULL
    if (queue->head == NULL) queue->tail = NULL;

    // Get data from removed element and delete it
    int value = item->data;
    free(item);

    // Return value from removed element
    return value;
}