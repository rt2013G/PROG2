#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
/*
 * Implementation of a Graph using an adjacency list, for simplicity every vertex is identified by its index.
 */
typedef struct Node {
    int vertex;
    struct Node *next;
} Node;

typedef struct Graph {
    int num_of_nodes;
    Node **adj_list;
} Graph;

Node *create_node(int vertex)
{
    Node *new_node = calloc(1, sizeof(Node));
    new_node->vertex = vertex;
    new_node->next = NULL;
    return new_node;
}

Graph *create_graph(int num_of_nodes)
{
    Graph *new_graph = calloc(1, sizeof(Graph));
    new_graph->num_of_nodes = num_of_nodes;
    new_graph->adj_list = calloc(new_graph->num_of_nodes, sizeof(Node *));
    for(int i = 0; i < new_graph->num_of_nodes; i++) {
        new_graph->adj_list[i] = NULL;
    }
    return new_graph;
}

bool add_edge(Graph *g, int index_from, int index_to)
{
    Node *node = create_node(index_to);
    node->next = g->adj_list[index_from];
    g->adj_list[index_from] = node;
    return true;
}

bool visit_graph(Graph *g) {
    for(int i = 0; i < g->num_of_nodes; i++) {
        Node *tmp = g->adj_list[i];
        while(tmp != NULL) {
            printf("Node %d -> Node %d\n", i, tmp->vertex);
            tmp = tmp->next;
        }
    }
    return true;
}

int main()
{
    Graph *g = create_graph(3);
    add_edge(g, 1, 1);
    add_edge(g, 1, 2);
    add_edge(g, 0, 2);
    visit_graph(g);
    return 0;
}
