//
// Created by mitos on 01.03.2022.
//

#ifndef WDI_MIM2021_QUEUE_H
#define WDI_MIM2021_QUEUE_H

#include "i_node.h"

typedef struct i_queue_o
{
    i_node_s* head;
    i_node_s* tail;
} i_queue_o;

extern int empty_q(i_queue_o queue);

extern void push_q(i_queue_o* queue, int value);

extern int pop_q(i_queue_o* queue);

#endif //WDI_MIM2021_QUEUE_H
