#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <cstd/list.h>
#include <cstd/tree.h>

void randomize_ls(i_list_s* list)
{
    srand(time(0));
    int n;
    n = rand() % 30;
    for (int i=0; i<n; ++i)
        push_front_ls(list, rand() % 60);
}

i_node_t* find_list_in_tree(i_tree_b root, int* good, int* length)
{
    // Check if root is NULL
    if (root == NULL)
    {
        *good = 1;
        *length = -1;
        return root;
    }

    int lg, rg, ll, rl;
    i_node_t* lp, *rp;
    lp = find_list_in_tree(root, &lg, &ll);
    rp = find_list_in_tree(root, &rg, &rl);

    if (root->left && root->right)
    {
        *good = 0;
        if (ll > rl)
        {
            *length = ll;
            return lp;
        }
        else
        {
            *length = rl;
            return rp;
        }
    }

    if (root->left == NULL)
    {
        *good = rg;
        if (*good)
        {
            *length = rl+1;
            return root;
        }
        else
        {
            *length = rl;
            return rp;
        }
    }else
    {
        *good = lg;
        if (*good)
        {
            *length = ll+1;
            return root;
        }
        else
        {
            *length = ll;
            return lp;
        }
    }
}

int main()
{

    return 0;
}