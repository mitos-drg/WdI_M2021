//
// Created by mitos on 14.03.2022.
//

#ifndef WDI_MIM2021_TREE_H
#define WDI_MIM2021_TREE_H

#include "i_node.h"
#include "function.h"

// Binary Search Tree
typedef i_node_t* i_tree_b;

extern void add_bst(i_tree_b* tree, int value);
extern void remove_bst(i_tree_b* root, i_node_t* node);
extern i_node_t* next_bst(i_node_t* node);
extern i_node_t* min_bst(i_node_t* root);
extern i_node_t* find_bst(i_tree_b tree, int key);
extern void foreach_bst_const(i_tree_b tree, i_method_c operation);
extern void foreach_bst(i_tree_b tree, i_method operation);
extern void clear_bst(i_tree_b* root);
extern int height_bst(i_tree_b root);

// Red-Black Tree
typedef struct i_tree_rb {
    i_node_c* root;
    i_node_c* sentinel;
}i_tree_rb;

extern void add_rb(i_tree_rb* tree, int value);
extern void remove_rb(i_tree_rb* tree, i_node_c* node);
extern i_node_c* find_rb(i_tree_rb root, int value);

#endif //WDI_MIM2021_TREE_H