//
// Created by mitos on 30.05.2022.
//

#ifndef WDI_MIM2021_I_GRAPH_H
#define WDI_MIM2021_I_GRAPH_H

#include "list.h"

typedef i_list_s* graph_d;

/**
 * Load directional graph from text file.
 * 
 * The file must be in following format:
 *      - single intiger indicating the size of the graph
 *      - each next line should contain two intigers x and y indicating, that there is edge from x to y
 * 
 * \param G - graph to load to, must be of size N
 * \param size - returns size of loaded graph
 * \param filepath - path to file from which to read graph
 */
void load_d(graph_d** G, int* size, const char* filepath);

/**
 * Prints directed graph in human readable form.
 * 
 * \param G - graph to print
 * \param size - number of vertices in graph
 */
void print_graph(graph_d* G, int size);

/**
 * Miscellaneous functions for graphs
 */

int is_articulation(graph_d* G, int size, int node);

#endif