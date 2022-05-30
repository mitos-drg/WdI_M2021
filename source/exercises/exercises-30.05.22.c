#include <stdio.h>
#include <stdlib.h>

/**
 * Data structures for undirected graph
 */
typedef struct g_node_u {
    int data;
    struct g_node_u* next, *backway;
} g_node_u, *g_list_u;

void g_push_ud(g_list_u* list, int value)
{
    // Create new list node and initialize its fields
    g_node_u* item = malloc(sizeof(g_node_u));
    item->data = value;
    item->next = *list;

    // Move list pointer to new beginning of the list
    *list = item;
}

typedef g_list_u graph_d;
/**
 * Load graph from text file.
 * 
 * The file must be in following format:
 *  - where each line consists of two integers describing one, directional edge (from x to y)
 * 
 * \param N - number of vertices in graph
 * \param G - graph to load to, must be of size N
 * \param filepath - path to file from which to read graph
 */
void load(int N, graph_d G[N], const char* filepath)
{
    FILE* input = fopen(filepath, "r");
    int x, y;
    while (fscanf(input, "%d %d ", &x, &y) != EOF)
    {
        g_push_ud(G[x], y);
        g_push_ud(G[y], x);
        G[x]->backway = G[y];
        G[y]->backway = G[x];
    }
    fclose(input);
}

int main()
{
    return 0;
}