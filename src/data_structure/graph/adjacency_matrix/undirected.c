#include <stdio.h>
#include <stdlib.h>

/*
 * UndirectedGraph Representation using Adjacency Matrix
 */
typedef struct
{
    int **matrix;
    size_t size;
} WeightedUndirectedGraph;

/*
 * Creates a UndirectedGraph and returns
 * a pointer to it.
 */
WeightedUndirectedGraph *NewDirectedGraph(size_t size)
{
    WeightedUndirectedGraph *undirected_graph = (WeightedUndirectedGraph *)malloc(sizeof(WeightedUndirectedGraph));
    undirected_graph->size = size;

    undirected_graph->matrix = malloc(undirected_graph->size * sizeof(int *));
    for (int i = 0; i < undirected_graph->size; i++)
    {
        undirected_graph->matrix[i] = malloc(sizeof(int) * undirected_graph->size);
    };

    for (int i = 0; i < undirected_graph->size; i++)
    {
        for (int j = 0; j < undirected_graph->size; j++)
        {
            undirected_graph->matrix[i][j] = 0;
        }
    }

    return undirected_graph;
};

/*
 * Adds the edge between the source and destination
 */
void AddEdge(WeightedUndirectedGraph *undirected_graph, int src, int dest)
{
    undirected_graph->matrix[src][dest] = 1;
    undirected_graph->matrix[dest][src] = 1;
};

/*
 * Removes the edge between the srouce and destination
 */
void RemoveEdge(WeightedUndirectedGraph *undirected_graph, int src, int dest)
{
    undirected_graph->matrix[src][dest] = 0;
    undirected_graph->matrix[dest][src] = 0;
}

/*
 * Checks is there is an edge between source and destination
 */
int HasEdge(WeightedUndirectedGraph *undirected_graph, int src, int dest)
{
    return undirected_graph->matrix[src][dest] == 1;
}

/*
 * Prints the directed_graph
 */
void Print(WeightedUndirectedGraph *undirected_graph)
{
    for (int i = 0; i < undirected_graph->size; i++)
    {
        printf("%d : ", i);
        for (int j = 0; j < undirected_graph->size; j++)
        {
            printf("%d ", undirected_graph->matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    WeightedUndirectedGraph *undirected_graph = NewDirectedGraph(5);
    Print(undirected_graph);

    AddEdge(undirected_graph, 0, 1);
    AddEdge(undirected_graph, 0, 2);
    AddEdge(undirected_graph, 0, 3);
    AddEdge(undirected_graph, 1, 3);
    AddEdge(undirected_graph, 1, 4);
    AddEdge(undirected_graph, 2, 3);
    AddEdge(undirected_graph, 3, 4);
    Print(undirected_graph);

    int has_edge = HasEdge(undirected_graph, 1, 3);
    if (has_edge)
    {
        puts("There is an edge between 1 and 3");
    }
    else
    {
        puts("There is no edge between 1 and 3");
    }

    RemoveEdge(undirected_graph, 1, 3);
    RemoveEdge(undirected_graph, 1, 4);
    Print(undirected_graph);

    has_edge = HasEdge(undirected_graph, 1, 4);
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
