#include <stdio.h>
#include <stdlib.h>
#include <cstd/graph.h>
#include <cstd/stack.h>

void load_d(graph_d** G, int* size, const char* filepath)
{
    FILE* input = fopen(filepath, "r");
    int x, y;
    *size = 0;
    fscanf(input, "%d ", size);
    *G = malloc(*size * sizeof(graph_d));
    while (fscanf(input, "%d %d ", &x, &y) != EOF)
    {
        push_front_ls((*G)[x], y);
    }
    fclose(input);
}

void printg(int k)
{
    printf("%d, ", k);
}
void print_graph(graph_d* G, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d: ", i);
        foreach_ls_const(G[i], printg);
        printf("\n");
    }
    
}

int is_articulation(graph_d* G, int size, int start)
{
    // Created array storing whether we visited vertex or not and second one telling how many
    // subtrees each vertex has
    int visited[size];
    int descendants[size];
    int prev[size];
    for (int i = 0; i < size; ++i)
    {
        visited[i] = 0;
        descendants[i] = 0;
        prev[i] = -1;
    }
    
    // visit first vertex and push it to the stack
    visited[start] = 1;
    i_stack_t stack = NULL;
    push_s(&stack, start);

    // DFS
    while (!empty_s(stack))
    {
        int c = front_s(&stack); // TODO: implement
        if (visited[c] == 1)
        {
            pop_s(&stack);
            continue;
        }
        i_node_s* iter = G[c];
        while (iter != NULL)
        {
            if (visited[iter->data] == 0)
            {
                push_s(&stack, iter->data);
                visited[iter->data] = 1;
                prev[iter->data] = c;
            }
            iter = iter->next;
        }
    }
    
}

/**
 * Undirectional graphs
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