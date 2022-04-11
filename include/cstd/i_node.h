//
// Created by mitos on 01.03.2022.
//

#ifndef WDI_MIM2021_I_NODE_H
#define WDI_MIM2021_I_NODE_H

typedef struct i_node_s
{
    int data;
    struct i_node_s* next;
} i_node_s;

typedef struct i_node_t
{
    int key;
    struct i_node_t* up, *right, *left;
} i_node_t;

#endif //WDI_MIM2021_I_NODE_H
