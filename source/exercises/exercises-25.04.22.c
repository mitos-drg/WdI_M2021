#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <cstd/tree.h>
#include <cstd/list.h>
#include <cstd/debug.h>

/**
 * Zadanie 3
 */

typedef struct s_node
{
    char* str;
    int count;
    struct s_node* up, *right, *left;
} s_node, *s_tree;

/**
 * Helper comparator function for strings
 * \returns 0 if strings are equal, 1 if rhs is greater and -1 if lhs is greater
 */
int s_comp(char* lhs, char* rhs) // lhs >= rhs
{
    // get length of both strings
    int lenl = strlen(lhs);
    int lenr = strlen(rhs);

    // check whether the strings are substrings
    for (int i=0; i < lenl && i < lenr; ++i)
        if (lhs[i] < rhs[i])
            return 1;
        else if (lhs[i] > rhs[i])
            return -1;

    // Check which is substring
    if (lenl < lenr) return 1;
    else if (lenr < lenl) return -1;

    // The strings are equal
    return 0;
}

s_node* new_node(char* str)
{
    s_node* t = malloc(sizeof(s_node));
    t->str = malloc(strlen(str));
    strcpy(t->str, str);
    t->count = 1;
    t->left = t->right = t->up = NULL;

    return t;
}

void s_add_node_bst(s_tree* root, char* str)
{
    // If tree is empty set root to be new node end exit
    if (*root == NULL)
    {
        *root = new_node(str);
        return;
    }

    // Decide in witch subtree new node should be placed
    int comp = s_comp(str, (*root)->str);
    if (comp == -1)
    {
        if ((*root)->right == NULL)
        {
            (*root)->right = new_node(str);
            (*root)->right->up = *root;
        }else add_node_bst(&(*root)->right, str);
    }
    else if (comp == 1)
    {
        if ((*root)->left == NULL)
        {
            (*root)->left = new_node(str);
            (*root)->left->up = *root;
        }else add_node_bst(&(*root)->left, str);
    }
    else
        (*root)->count++;
}

void print(s_tree tree)
{
    if (tree == NULL) return;
    print(tree->left);
    printf("%s: %d\n", tree->str, tree->count);
    print(tree->right);
}

void s_delete_bst(s_tree* root)
{
    if (*root == NULL) return;
    delete(&(*root)->left);
    delete(&(*root)->right);
    free((*root)->str);
    free(*root);
    *root = NULL;
}

/**
 * Zadanie 2
 */
int max_subBST(i_tree_b tree, int *ok, int* min, int* max, int* height)
{
    // An empty tree is indeed the bst tree
    if (tree == NULL) return 1;

    int lmin = tree->key, lmax = tree->key, rmin = tree->key, rmax = tree->key;
    int lok = 1, rok = 1, lh = 0, rh = 0;
    int lbst = max_subBST(tree->left, &lok, &lmin, &lmax, &lh);
    int rbst = max_subBST(tree->right, &rok, &rmin, &rmax, &rh);

    *min = lmin < rmin ? lmin : rmin;
    *max = lmax > rmax ? lmax : rmax;

    *ok =  (lmax <= tree->key) && (tree->key <= rmin) && lbst && rbst;
    if (lh > rh)
    {
        *height = lh + 1;
        if (!(*ok))
        {
            if (lok) return lbst;
            return rbst;
        }
    }
    else
    {
        *height = rh + 1;
        if (!(*ok))
        {
            if (rok) return rbst;
            return lbst;
        }
    }

    return tree->key;
}

/**
 * Zadania na grafy
 */

typedef i_list_s* graph;

/**
 * Load graph from text file.
 * 
 * The file must be in following format:
 *      x y
 *      x z
 *      ...
 *  where each line consists of two integers describing one, directional edge (from x to y)
 * 
 * \param N - maximal number of vertices in loaded graph
 * \param G - graph to load to, must be of size N
 * \param size - returns size of loaded graph
 * \param filepath - path to file from which to read graph
 */
void load(int N, graph G[N], int* size, const char* filepath)
{
    FILE* input = fopen(filepath, "r");
    int x, y;
    *size = 0;
    while (fscanf(input, "%d %d ", &x, &y) != EOF)
    {
        push_front_ls(G[x], y);
        if (x > *size) *size = x;
        if (y > *size) *size = y;
    }
    fclose(input);
}

void printg(int k)
{
    printf("%d, ", k);
}
void print_graph(graph* G, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d: ", i);
        foreach_ls_const(G[i], printg);
        printf("\n");
    }
    
}

int main()
{
    /**
     * Zadania na drzewa
    FILE* input = fopen("test_words.txt", "r");
    char buf[128];
    s_tree tree = NULL;
    while (fscanf(input, " %s", buf) != -1)
    {
        // printf("%s\n", buf);
        s_add_node_bst(&tree, buf);
    }
    print(tree);
    fclose(input);
    s_delete_bst(&tree);
    */
}