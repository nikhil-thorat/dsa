#include <stdio.h>
#include <stdlib.h>

/*
 * WeightedUndirectedGraph Representation using Adjacency Matrix
 */
typedef struct
{
    int **matrix;
    size_t size;
} WeightedUndirectedGraph;

/*
 * Creates a WeightedUndirectedGraph and returns
 * a pointer to it.
 */
WeightedUndirectedGraph *NewWeightedUndirectedGraph(size_t size)
{
    WeightedUndirectedGraph *weighted_undirected_graph =
        (WeightedUndirectedGraph *)malloc(sizeof(WeightedUndirectedGraph));
    weighted_undirected_graph->size = size;

    weighted_undirected_graph->matrix = malloc(weighted_undirected_graph->size * sizeof(int *));
    for (int i = 0; i < weighted_undirected_graph->size; i++)
    {
        weighted_undirected_graph->matrix[i] = malloc(sizeof(int) * weighted_undirected_graph->size);
    };

    for (int i = 0; i < weighted_undirected_graph->size; i++)
    {
        for (int j = 0; j < weighted_undirected_graph->size; j++)
        {
            weighted_undirected_graph->matrix[i][j] = 0;
        }
    }

    return weighted_undirected_graph;
};

/*
 * Adds the edge between the source and destination
 */
void AddEdge(WeightedUndirectedGraph *weighted_undirected_graph, int src, int dest, int weight)
{
    weighted_undirected_graph->matrix[src][dest] = weight;
    weighted_undirected_graph->matrix[dest][src] = weight;
};

/*
 * Removes the edge between the srouce and destination
 */
void RemoveEdge(WeightedUndirectedGraph *weighted_undirected_graph, int src, int dest)
{
    weighted_undirected_graph->matrix[src][dest] = 0;
    weighted_undirected_graph->matrix[dest][src] = 0;
}

/*
 * Checks is there is an edge between source and destination
 */
int HasEdge(WeightedUndirectedGraph *weighted_undirected_graph, int src, int dest)
{
    return weighted_undirected_graph->matrix[src][dest] != 0;
}

/*
 * Prints the directed_graph
 */
void Print(WeightedUndirectedGraph *weighted_undirected_graph)
{
    for (int i = 0; i < weighted_undirected_graph->size; i++)
    {
        printf("%d : ", i);
        for (int j = 0; j < weighted_undirected_graph->size; j++)
        {
            printf("%d ", weighted_undirected_graph->matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    WeightedUndirectedGraph *weighted_undirected_graph = NewWeightedUndirectedGraph(5);
    Print(weighted_undirected_graph);

    AddEdge(weighted_undirected_graph, 0, 1, 10);
    AddEdge(weighted_undirected_graph, 0, 2, 20);
    AddEdge(weighted_undirected_graph, 0, 3, 15);
    AddEdge(weighted_undirected_graph, 1, 3, 25);
    AddEdge(weighted_undirected_graph, 1, 4, 5);
    AddEdge(weighted_undirected_graph, 2, 3, 80);
    AddEdge(weighted_undirected_graph, 3, 4, 35);
    Print(weighted_undirected_graph);

    int has_edge = HasEdge(weighted_undirected_graph, 1, 3);
    if (has_edge)
    {
        puts("There is an edge between 1 and 3");
    }
    else
    {
        puts("There is no edge between 1 and 3");
    }

    RemoveEdge(weighted_undirected_graph, 1, 3);
    RemoveEdge(weighted_undirected_graph, 1, 4);
    Print(weighted_undirected_graph);

    has_edge = HasEdge(weighted_undirected_graph, 1, 4);
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
