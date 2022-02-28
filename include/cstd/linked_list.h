//
// Created by mitos on 28.02.2022.
//

#ifndef WDI_MIM2021_LINKED_LIST_H
#define WDI_MIM2021_LINKED_LIST_H

// Declare node types
struct i_node_s;
struct i_node_b;

// Declare list types
typedef struct i_list_s
{
    struct i_node_s* head;
} i_list_s;
struct i_list_b;

typedef struct i_node_s i_node_t;

typedef struct i_list_s i_list_t;

extern void init_list(i_list_t* list);
extern int empty(i_list_t* list);
extern void add(i_list_t* list, int value);
extern void append(i_list_t* list, int value);
extern int remove(i_list_t* list);

#endif //WDI_MIM2021_LINKED_LIST_H
