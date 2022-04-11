//
// Created by mitos on 14.03.2022.
//

#include <stdlib.h>
#include <i_node.h>
#include <function.h>
#include <tree.h>

/**
 * BINARY SEARCH TREES
 */

void add_node_bst(i_tree_b* root, i_node_t* node)
{
    // If tree is empty set root to be new node end exit
    if (*root == NULL)
    {
        *root = node;
        return;
    }

    // Decide in witch subtree new node should be placed
    if ((*root)->key < node->key)
    {
        if ((*root)->right == NULL)
        {
            node->up = *root;
            (*root)->right = node;
        }else add_node_bst(&(*root)->right, node);
    }
    else
    {
        if ((*root)->left == NULL)
        {
            node->up = *root;
            (*root)->left = node;
        }else add_node_bst(&(*root)->left, node);
    }
}

void add_bst(i_tree_b* root, int value)
{
    // Create new node
    i_node_t* node = malloc(sizeof(i_node_t));
    node->key = value;
    node->up = node->right = node->left = NULL;

    // Add newly created node to the tree
    add_node_bst(root, node);
}

void remove_bst(i_tree_b* root, i_node_t* node)
{
    // Create helper pointers
    i_node_t *x, *y;

    // Decide which node we would actually delete
    if (node->left == NULL || node->right == NULL)
        y = node;
    else
        y = next_bst(node);
    
    // y has exactly 1 child, set it to be x
    if (y->left == NULL) x = y->right;
    else x = y->left;

    // If x exists clear its connection to y
    if (x != NULL) x->up = y->up;

    // If we are deleting root x is new root, otherwise set x as apropiete
    // child of y's parent
    if (y->up == NULL) *root = x;
    else
    {
        if (y == y->up->left)
            y->up->left = x;
        else
            y->up->right = x;
    }

    // If we are deleting other node than originally passed rewrite their values
    if (y != node)
        node->key = y->key;
    
    // Free memory of deleted element
    free(y);
}

i_node_t* next_bst(i_node_t* node)
{
    // If current node has right child return minimal node from it's subtree
    if (node->right != NULL)
        return min_bst(node->right);
    
    // Find next node
    i_node_t* iter = node->up;
    while (iter != NULL)
    {
        // Is it last node being left child?
        if (iter->left != node)
        {
            node = iter;
            iter = iter->up;
        }
        else return iter;
    }

    // There is no next node, return NULL
    return NULL;
}

i_node_t* min_bst(i_node_t* root)
{
    // Get the iterator for tree
    i_node_t* iter = root;

    // If tree isn't empty
    if (iter != NULL)
    {
        // We go to the left as long as there is something to go to
        while (iter->left != NULL)
        {
            iter = iter->left;
        }
    }

    // Return found minimal element
    return iter;
}

i_node_t* find_bst(i_tree_b root, int key)
{
    // Get the iterator for tree
    i_node_t* iter = root;

    // Search for desired key
    while (iter != NULL && iter->key != key)
    {
        // If current key is smaller continue searching in rigth subtree
        if (iter->key < key)
            iter = iter->right;
        // Otherwise search left subtree
        else
            iter = iter->left;
    }
    
    // Return found element
    return iter;
}

void foreach_bst_const(i_tree_b tree, i_method_c operation)
{
    // If we entered empty tree just return
    if (tree == NULL) return;

    // Execute the operation recursively on left subtree
    foreach_bst_const(tree->left, operation);

    // Execute operation on current node
    operation(tree->key);

    // Execute the operation recursively on right subtree
    foreach_bst_const(tree->right, operation);
}

void foreach_bst(i_tree_b tree, i_method operation)
{
    // If we entered empty tree just return
    if (tree == NULL) return;

    // Execute the operation recursively on left subtree
    foreach_bst(tree->left, operation);

    // Execute operation on current node
    operation(tree->key);

    // Execute the operation recursively on right subtree
    foreach_bst(tree->right, operation);
}

void clear_bst(i_tree_b* root)
{
    // If we are in empty tree do nothing
    if (*root == NULL) return;

    // Recursively delete both subtrees
    clear_bst(&(*root)->left);
    clear_bst(&(*root)->right);

    // Free memory of root and set it to NULL for safety
    free(*root);
    *root = NULL;
}

int height_bst(i_tree_b root)
{
    // If the tree is empty return -1
    if (root == NULL) return -1;

    // Compute height of both subtrees
    int lh = height_bst(root->left);
    int rh = height_bst(root->right);

    // Return greater of this two
    if (lh > rh)
        return lh + 1;
    else
        return rh + 1;
}


/**
 * RED-BLACK TREES
 */

void rotate_left(i_tree_rb* tree, i_node_c* x)
{ // TODO: Finish
    // Get second node taking part in rotation
    i_node_c* y = x->right;

    // Left subtree of right child  
    x->right = y->left;
    x->right->up = x;
    y->up = x->up;
}

void add_rb(i_tree_rb* tree, int value)
{

}

void remove_rb(i_tree_rb* tree, i_node_c* node)
{

}

i_node_c* find_rb(i_tree_rb root, int value)
{

}