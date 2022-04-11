#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <cstd/tree.h>
#include <cstd/function.h>

i_tree_b randomize_bst(int size)
{
    // Create tree root
    i_tree_b root = NULL;
    int v;

    // Add random nodes to the tree
    for (int i = 0; i < size; i++)
    {
        v = rand()%100;
        add_bst(&root, v);
        printf("Added %d\n", v);
    }
    
    // Return tree
    return root;
}

void pr(int a)
{
    printf("%d\n", a);
}

void pretty_print(i_tree_b t, int n)
{
    if (t == NULL) return;

    pretty_print(t->right,n+3);

    for (int i = 0; i < n; i++)
    {
        printf(" ");
    }

    printf("%d\n",t->key);

    pretty_print(t->left,n+3);
}

int isIsomorphic(i_tree_b lhs, i_tree_b rhs)
{
    // Two empty trees are isomorphic
    if (lhs == NULL && rhs == NULL) return 1;
    // Two empty tree never is isomorphic with non-empty tree
    if (lhs == NULL || rhs == NULL) return 0;

    // Check if both subtrees are isomorphic and return it
    return isIsomorphic(lhs->left, rhs->left) && isIsomorphic(lhs->right, rhs->right);
}

int isBST(i_tree_b tree, int* min, int* max)
{
    // An empty tree is indeed the bst tree
    if (tree == NULL) return 1;

    int lmin = tree->key, lmax = tree->key, rmin = tree->key, rmax = tree->key;
    int lbst = isBST(tree->left, &lmin, &lmax);
    int rbst = isBST(tree->right, &rmin, &rmax);

    *min = lmin < rmin ? lmin : rmin;
    *max = lmax > rmax ? lmax : rmax;

    return (lmax <= tree->key) && (tree->key <= rmin) && lbst && rbst;
}

int main()
{
    srand(time(0));
    i_tree_b sTree = randomize_bst(20);
    printf("Height of random tree with 20 nodes is: %d\n", height_bst(sTree));
    //foreach_bst_const(sTree, pr);
    pretty_print(sTree, 0);
    int min = 0, max = 0;
    if (isBST(sTree, &min, &max)) printf("This is BST\n");
    else printf("This is not BST\n");

    clear_bst(&sTree);

    return 0;
}