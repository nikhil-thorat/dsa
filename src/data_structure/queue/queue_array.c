#include <stdio.h>
#include <stdlib.h>

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

int main()
{
    Queue *queue = NewQueue(5);

    Enqueue(queue, 1);
    Enqueue(queue, 2);
    Enqueue(queue, 3);
    Enqueue(queue, 4);
    PrintElements(queue);

    Dequeue(queue);
    PrintElements(queue);

    Dequeue(queue);
    Dequeue(queue);
    Dequeue(queue);
    Dequeue(queue);
    PrintElements(queue);

    Enqueue(queue, 11);
    Enqueue(queue, 12);
    Enqueue(queue, 13);
    Enqueue(queue, 14);
    Enqueue(queue, 15);
    PrintElements(queue);

    Enqueue(queue, 16);

    Destroy(queue);

    return 0;
};
