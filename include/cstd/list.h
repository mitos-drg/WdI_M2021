//
// Created by mitos on 01.03.2022.
//

#ifndef WDI_MIM2021_LIST_H
#define WDI_MIM2021_LIST_H

#include "i_node.h"
#include "function.h"

typedef i_node_s* i_list_s;

extern void push_back_ls(i_list_s list, int value);

extern void push_front_ls(i_list_s* list, int value);

extern int pop_front_ls(i_list_s* list);

extern void reverse_ls(i_list_s* list);

extern int is_ordered_ls(i_list_s list);

extern void foreach_ls_const(i_list_s list, i_method_c operation);

extern void foreach_ls(i_list_s list, i_method operation);

extern i_node_s* merging_ls(i_list_s lhs, i_list_s rhs);

extern int length_ls(i_list_s list);

#endif //WDI_MIM2021_LIST_H
