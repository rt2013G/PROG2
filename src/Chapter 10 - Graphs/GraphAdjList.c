#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
/*
 * Implementation of a Graph using an adjacency list, for simplicity every vertex is identified by its index.
 * visit_depth_first() visits the graph by depth-first search, recursively.
 * visit_breadth_first() visits the graph by breadth-first search, the queue implementation is the same as in
 * "Chapter 8/QueueArray.c"
 */
typedef struct Node {
    int vertex;
    struct Node *next;
} Node;

typedef struct Graph {
    int num_of_nodes;
    bool *visited;
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
    new_graph->visited = calloc(new_graph->num_of_nodes, sizeof(bool));
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

bool visit_depth_first(Graph *g, int vertex)
{
    Node *tmp = g->adj_list[vertex];
    g->visited[vertex] = true;
    printf("Node %d.\n", vertex);
    while(tmp != NULL) {
        int vertex_connected = tmp->vertex;
        if(g->visited[vertex_connected] == false) {
            visit_depth_first(g, vertex_connected);
        }
        tmp = tmp->next;
    }
    return true;
}

// Queue-related code begins here
typedef struct Queue {
    int size;
    int *items;
    int head;
    int tail;
    int num_of_elems;
} Queue;

Queue *create_queue(int len)
{
    Queue *new_queue = calloc(1, sizeof(Queue));
    new_queue->size = len;
    new_queue->items = calloc(new_queue->size, sizeof(int));
    new_queue->head = -1;
    new_queue->tail = -1;
    new_queue->num_of_elems = 0;
    return new_queue;
}

bool enqueue(Queue *q, int val)
{
    if(q->num_of_elems >= q->size) {
        printf("The queue is full.\n");
        return false;
    }
    q->tail = q->head + q->num_of_elems;
    q->tail = q->tail % q->size;
    q->items[q->tail] = val;
    (q->num_of_elems)++;
    return true;
}

bool dequeue(Queue *q, int *val)
{
    if(q->num_of_elems == 0) {
        printf("The queue is empty.\n");
        return false;
    }
    *val = q->items[q->head];
    (q->head)++;
    q->head = q->head % q->size;
    (q->num_of_elems)--;
    return true;
}
// Queue-related code ends here

bool visit_breadth_first(Graph *g, int vertex)
{
    Queue *q = create_queue(g->num_of_nodes);
    g->visited[vertex] = true;
    enqueue(q, vertex);
    int value = vertex;
    while(dequeue(q, &value)) {
        int curr_vertex = value;
        printf("Node %d\n", curr_vertex);
        Node *tmp = g->adj_list[curr_vertex];
        while(tmp != NULL) {
            int vertex_connected = tmp->vertex;
            if(g->visited[vertex_connected] == false) {
                g->visited[vertex_connected] = true;
                enqueue(q, vertex_connected);
            }
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
    add_edge(g, 0, 1);
    visit_breadth_first(g, 0);
    return 0;
}
