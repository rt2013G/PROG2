#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
/*
 * Implementation of a Graph using an adjacency matrix.
 */
typedef struct Graph {
    int num_of_nodes;
    bool **adj_matrix;
} Graph;

Graph *create_graph(int num_of_nodes)
{
    Graph *new_graph = calloc(1, sizeof(Graph));
    new_graph->num_of_nodes = num_of_nodes;
    new_graph->adj_matrix = calloc(new_graph->num_of_nodes, sizeof(bool *));
    for(int i = 0; i < new_graph->num_of_nodes; i++) {
        new_graph->adj_matrix[i] = calloc(new_graph->num_of_nodes, sizeof(bool));
    }
    return new_graph;
}

bool print_graph(Graph *g)
{
    for(int i = 0; i < g->num_of_nodes; i++) {
        for(int j = 0; j < g->num_of_nodes; j++) {
            if(g->adj_matrix[i][j]) {
                printf("Node %d -> Node %d\n", i, j);
            }
        }
    }
    return true;
}

int main()
{
    Graph *graph = create_graph(5);
    graph->adj_matrix[2][2] = true;
    graph->adj_matrix[2][3] = true;
    graph->adj_matrix[3][2] = true;
    print_graph(graph);
    return 0;
}
