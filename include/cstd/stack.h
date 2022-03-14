//
// Created by mitos on 01.03.2022.
//

#ifndef WDI_MIM2021_STACK_H
#define WDI_MIM2021_STACK_H

#include "i_node.h"

typedef i_node_s* i_stack_t;

extern int empty_s(i_stack_t stack);

extern void push_s(i_stack_t* stack, int value);

extern int pop_s(i_stack_t* stack);

#endif //WDI_MIM2021_STACK_H
