#include <stdio.h>
#include <stdlib.h>

/*
 * DirectedGraph Representation using Adjacency Matrix
 */
typedef struct
{
    int **matrix;
    size_t size;
} DirectedGraph;

/*
 * Creates a DirectedGraph and returns
 * a pointer to it.
 */
DirectedGraph *NewDirectedGraph(size_t size)
{
    DirectedGraph *directed_graph = (DirectedGraph *)malloc(sizeof(DirectedGraph));
    directed_graph->size = size;

    directed_graph->matrix = malloc(directed_graph->size * sizeof(int *));
    for (int i = 0; i < directed_graph->size; i++)
    {
        directed_graph->matrix[i] = malloc(sizeof(int) * directed_graph->size);
    };

    for (int i = 0; i < directed_graph->size; i++)
    {
        for (int j = 0; j < directed_graph->size; j++)
        {
            directed_graph->matrix[i][j] = 0;
        }
    }

    return directed_graph;
};

/*
 * Adds the edge between the source and destination
 */
void AddEdge(DirectedGraph *directed_graph, int src, int dest)
{
    directed_graph->matrix[src][dest] = 1;
};

/*
 * Removes the edge between the srouce and destination
 */
void RemoveEdge(DirectedGraph *directed_graph, int src, int dest)
{
    directed_graph->matrix[src][dest] = 0;
}

/*
 * Checks is there is an edge between source and destination
 */
int HasEdge(DirectedGraph *directed_graph, int src, int dest)
{
    return directed_graph->matrix[src][dest] == 1;
}

/*
 * Prints the directed_graph
 */
void Print(DirectedGraph *directed_graph)
{
    for (int i = 0; i < directed_graph->size; i++)
    {
        printf("%d : ", i);
        for (int j = 0; j < directed_graph->size; j++)
        {
            printf("%d ", directed_graph->matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    DirectedGraph *directed_graph = NewDirectedGraph(5);
    Print(directed_graph);

    AddEdge(directed_graph, 0, 1);
    AddEdge(directed_graph, 0, 2);
    AddEdge(directed_graph, 0, 3);
    AddEdge(directed_graph, 1, 3);
    AddEdge(directed_graph, 1, 4);
    AddEdge(directed_graph, 2, 3);
    AddEdge(directed_graph, 3, 4);
    Print(directed_graph);

    int has_edge = HasEdge(directed_graph, 1, 3);
    if (has_edge)
    {
        puts("There is an edge between 1 and 3");
    }
    else
    {
        puts("There is no edge between 1 and 3");
    }

    RemoveEdge(directed_graph, 1, 3);
    RemoveEdge(directed_graph, 1, 4);
    Print(directed_graph);

    has_edge = HasEdge(directed_graph, 1, 4);
    if (has_edge)
    {
        puts("There is an edge between 1 and 4");
    }
    else
    {
        puts("There is no edge between 1 and 4");
    }

    return 0;
}
