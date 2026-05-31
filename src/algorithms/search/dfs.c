#include <stdio.h>
#include <stdlib.h>

/*
 * Represents Stack type.
 */
typedef struct
{
    size_t size;
    size_t capacity;
    int *elements;
} Stack;

/*
 * Creates a new Stack of a given capacity
 * and returns a pointer to it.
 */
Stack *NewStack(size_t capacity)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->size = 0;
    stack->elements = (int *)malloc(stack->capacity * sizeof(int));
    return stack;
}

/*
 * Pushes the given value onto
 * the Stack.
 * Time complexity is O(1).
 */
void Push(Stack *stack, int value)
{
    if (stack->size == stack->capacity)
    {
        puts("Stack is Full");
        return;
    }

    stack->elements[stack->size] = value;
    stack->size++;
};

/*
 * Pops the top element from the
 * Stack.
 * Time complexity is O(1).
 */
void Pop(Stack *stack)
{
    if (stack->size == 0)
    {
        puts("Stack is Empty");
        return;
    }

    stack->size--;
}

/*
 * Returns the top element of
 * the Stack.
 * Time complexity is O(1).
 */
int Top(Stack *stack)
{
    return stack->elements[stack->size - 1];
}

/*
 * Searches the given value in
 * the Stack.
 * Returns 1 if found else 0.
 * Time complexity is O(N).
 */
int Search(Stack *stack, int value)
{
    for (int i = 0; i < stack->size; i++)
    {
        if (stack->elements[i] == value)
        {
            return 1;
        }
    }
    return 0;
};

/*
 * Returns 1 if Queue is empty
 * else 0.
 */
int IsEmpty(Stack *stack)
{
    return stack->size == 0;
};

/*
 * Prints the elements of
 * the Stack.
 */
void PrintElements(Stack *stack)
{
    for (int i = 0; i < stack->size; i++)
    {
        printf("%d ", stack->elements[i]);
    }
    printf("\n");
}

/*
 *  Frees the memory of the given
 *  Stack.
 */
void Destroy(Stack *stack)
{
    if (stack == NULL)
    {
        return;
    }
    free(stack->elements);
    free(stack);
}

/*
 * UndirectedGraph Representation using Adjacency Matrix
 */
typedef struct
{
    int **matrix;
    size_t size;
} UndirectedGraph;

/*
 * Creates a UndirectedGraph and returns
 * a pointer to it.
 */
UndirectedGraph *NewUndirectedGraph(size_t size)
{
    UndirectedGraph *undirected_graph = (UndirectedGraph *)malloc(sizeof(UndirectedGraph));
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
void AddEdge(UndirectedGraph *undirected_graph, int src, int dest)
{
    undirected_graph->matrix[src][dest] = 1;
    undirected_graph->matrix[dest][src] = 1;
};

/*
 * Removes the edge between the srouce and destination
 */
void RemoveEdge(UndirectedGraph *undirected_graph, int src, int dest)
{
    undirected_graph->matrix[src][dest] = 0;
    undirected_graph->matrix[dest][src] = 0;
}

/*
 * Checks is there is an edge between source and destination
 */
int HasEdge(UndirectedGraph *undirected_graph, int src, int dest)
{
    return undirected_graph->matrix[src][dest] == 1;
}

/*
 * Prints the directed_graph
 */
void Print(UndirectedGraph *undirected_graph)
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

/*
 * Depth First Search (DFS)
 *
 * Time Complexity : O(V + E), where V is vertices and E is edges.
 * Space Complexity : O(V), vertexes stored in queue and visited array.
 */
void DFS(UndirectedGraph *undirected_graph, int start_vertex)
{
    size_t size = undirected_graph->size;

    int visited[size] = {};
    Stack *stack = NewStack(size * size);

    Push(stack, start_vertex);
    visited[start_vertex] = 1;

    while (!IsEmpty(stack))
    {
        int vertex = Top(stack);
        Pop(stack);

        printf("Visited Vertex : %d\n", vertex);

        for (int idx = 0; idx < size; idx++)
        {
            if (HasEdge(undirected_graph, vertex, idx) && visited[idx] == 0)
            {
                Push(stack, idx);
                visited[idx] = 1;
            }
        }
    }
}

int main()
{
    UndirectedGraph *undirected_graph = NewUndirectedGraph(5);

    /*
     * 0------1 -
     * | \    |  \
     * |   \  |   4
     * |     \|  /
     * 2------3 -
     *
     */
    AddEdge(undirected_graph, 0, 1);
    AddEdge(undirected_graph, 0, 2);
    AddEdge(undirected_graph, 0, 3);
    AddEdge(undirected_graph, 1, 3);
    AddEdge(undirected_graph, 1, 4);
    AddEdge(undirected_graph, 2, 3);
    AddEdge(undirected_graph, 3, 4);
    Print(undirected_graph);

    DFS(undirected_graph, 0);

    return 0;
}
