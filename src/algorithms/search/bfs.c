#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
 * Represents Queue type.
 */
typedef struct
{
    size_t capacity;
    int front;
    int rear;
    int *elements;
} Queue;

/*
 * Creates a new Queue of a given capacity
 * and returns a pointer to it.
 */
Queue *NewQueue(size_t capacity)
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = -1;
    queue->rear = -1;
    queue->elements = (int *)malloc(queue->capacity * sizeof(int));
    return queue;
};

/*
 * Returns 1 if Queue is full
 * else 0.
 */
int IsFull(Queue *queue)
{
    return queue->rear == queue->capacity - 1;
};

/*
 * Returns 1 if Queue is empty
 * else 0.
 */
int IsEmpty(Queue *queue)
{
    return queue->front == -1;
};

/*
 * Enqueues the given value in
 * the Queue.
 * Time complexity is O(1).
 */
void Enqueue(Queue *queue, int value)
{
    if (IsFull(queue))
    {
        puts("Queue is Full.");
        return;
    }

    if (IsEmpty(queue))
    {
        queue->front++;
    }

    queue->rear++;
    queue->elements[queue->rear] = value;
};

/*
 * Dequeues the element from
 * the Queue.
 * Returns the dequeued element else
 * -1 if Queue is empty.
 * Time complexity is O(1).
 */
int Dequeue(Queue *queue)
{
    if (IsEmpty(queue))
    {
        puts("Queue is Empty");
        return -1;
    }

    int element = queue->elements[queue->front];
    if (queue->front == queue->rear)
    {
        queue->front = -1;
        queue->rear = -1;
        return element;
    }

    queue->front++;
    return element;
};

/*
 * Returns the Front element of
 * the Queue else -1 if empty.
 * Time complexity is O(1).
 */
int Peek(Queue *queue)
{
    if (IsEmpty(queue))
    {
        puts("Queue is Empty");
        return -1;
    }
    return queue->elements[queue->front];
};

/*
 * Searches the  given value in
 * the Queue.
 * Returns 1 if found else 0.
 * Time complexity is O(N).
 */
int Search(Queue *queue, int value)
{
    for (int i = queue->front; i < queue->rear; i++)
    {
        if (queue->elements[i] == value)
        {
            return 1;
        }
    }
    return 0;
};

/*
 * Prints the elements of
 * the Queue.
 */
void PrintElements(Queue *queue)
{

    if (IsEmpty(queue))
    {
        puts("Queue is Empty");
        return;
    }

    for (int i = queue->front; i <= queue->rear; i++)
    {
        printf("%d ", queue->elements[i]);
    }
    printf("\n");
}

/*
 * Frees the memory of the given
 * Queue.
 */
void Destroy(Queue *queue)
{
    if (queue == NULL)
    {
        return;
    }
    free(queue->elements);
    free(queue);
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
 * Breadth First Search (BFS)
 *
 * Time Complexity : O(V + E), where V is vertices and E is edges.
 * Space Complexity : O(V), vertexes stored in queue and visited array.
 */
void BFS(UndirectedGraph *undirected_graph, int start_vertex)
{
    size_t size = undirected_graph->size;

    int visited[size] = {};
    Queue *queue = NewQueue(size * size);

    Enqueue(queue, start_vertex);
    visited[start_vertex] = 1;

    while (!IsEmpty(queue))
    {
        int vertex = Dequeue(queue);
        printf("Visited Vertex : %d\n", vertex);

        for (int idx = 0; idx < size; idx++)
        {
            if (HasEdge(undirected_graph, vertex, idx) && visited[idx] == 0)
            {
                Enqueue(queue, idx);
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

    BFS(undirected_graph, 0);

    return 0;
}
