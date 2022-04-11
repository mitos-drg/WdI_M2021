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
        v = rand()%1000;
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

int main()
{
    srand(time(0));
    i_tree_b sTree = randomize_bst(20);
    printf("Height of random tree with 20 nodes is: %d\n", height_bst(sTree));
    //foreach_bst_const(sTree, pr);
    pretty_print(sTree, 0);

    clear_bst(&sTree);

    return 0;
}