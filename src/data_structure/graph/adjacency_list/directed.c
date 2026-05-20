#include <stdio.h>
#include <stdlib.h>

/*
 * Vertex represents Graph's vertex.
 */
typedef struct Vertex
{
    int dest;
    struct Vertex *next;
} Vertex;

/*
 * Creates a new Vertex and returns
 * a pointer to it.
 */
Vertex *NewVertex(int dest)
{
    Vertex *vertex = malloc(sizeof(Vertex));

    vertex->dest = dest;
    vertex->next = NULL;

    return vertex;
}

/*
 * DirectedGraph Representation using Ajacency List.
 */
typedef struct
{
    size_t no_of_vertex;
    Vertex *list[];
} DirectedGraph;

/*
 * Creates a new DirectedGraph and returns
 * a pointer to it.
 */
DirectedGraph *NewDirectedGraph(size_t vertexes)
{
    DirectedGraph *directed_graph = malloc(sizeof(DirectedGraph));

    directed_graph->no_of_vertex = vertexes;
    directed_graph->list[vertexes] = malloc(sizeof(Vertex) * vertexes);

    for (int i = 0; i < vertexes; i++)
    {
        directed_graph->list[i] = NULL;
    }

    return directed_graph;
};

/*
 * Adds the edge between the source and destination
 */
void AddEdge(DirectedGraph *directed_graph, int src, int dest)
{
    Vertex *new_vertex = NewVertex(dest);
    new_vertex->next = directed_graph->list[src];
    directed_graph->list[src] = new_vertex;
}

/*
 * Removes the edge between the srouce and destination
 */
void RemoveEdge(DirectedGraph *directed_graph, int src, int dest)
{
    Vertex *current = directed_graph->list[src];

    if (current == NULL)
    {
        return;
    }

    if (current->dest == dest)
    {
        directed_graph->list[src] = current->next;
        free(current);
        return;
    }

    Vertex *prev = NULL;
    while (current != NULL)
    {
        if (current->dest == dest)
        {
            break;
        }
        prev = current;
        current = current->next;
    }

    if (current == NULL)
    {
        return;
    }

    prev->next = current->next;
    free(current);
}

/*
 * Checks is there is an edge between source and destination
 */
int HasEdge(DirectedGraph *directed_graph, int src, int dest)
{
    Vertex *current = directed_graph->list[src];

    if (current == NULL)
    {
        return 0;
    };

    while (current != NULL)
    {
        if (current->dest == dest)
        {
            return 1;
        }
        current = current->next;
    }

    return 0;
}

/*
 * Prints the directed_graph
 */
void Print(DirectedGraph *directed_graph)
{
    for (int i = 0; i < directed_graph->no_of_vertex; i++)
    {
        printf("%d : ", i);

        Vertex *current = directed_graph->list[i];
        while (current != NULL)
        {
            printf("%d->", current->dest);
            current = current->next;
        }
        printf("NULL\n");
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

    int has_edge = HasEdge(directed_graph, 2, 3);
    if (has_edge)
    {
        puts("There is an edge between 2 and 3");
    }
    else
    {
        puts("There is no edge between 2 and 3");
    }

    RemoveEdge(directed_graph, 2, 3);
    Print(directed_graph);

    has_edge = HasEdge(directed_graph, 2, 3);
    if (has_edge)
    {
        puts("There is an edge between 2 and 3");
    }
    else
    {
        puts("There is no edge between 2 and 3");
    }

    return 0;
};
