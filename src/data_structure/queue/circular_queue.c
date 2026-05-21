#include <stdio.h>
#include <stdlib.h>

/*
 * Represents CircularQueue type.
 */
typedef struct
{
    size_t capacity;
    int front;
    int rear;
    int *elements;
} CircularQueue;

/*
 * Creates a new CircularQueue of a given capacity
 * and returns a pointer to it.
 */
CircularQueue *NewCircularQueue(size_t capacity)
{
    CircularQueue *circular_queue = (CircularQueue *)malloc(sizeof(CircularQueue));
    circular_queue->capacity = capacity;
    circular_queue->front = -1;
    circular_queue->rear = -1;
    circular_queue->elements = (int *)malloc(circular_queue->capacity * sizeof(int));
    return circular_queue;
};

/*
 * Returns 1 if Queue is full
 * else 0.
 */
int IsFull(CircularQueue *circular_queue)
{
    if (circular_queue->front == 0 && circular_queue->rear == circular_queue->capacity - 1)
    {
        return 1;
    }

    if (circular_queue->rear == circular_queue->front - 1)
    {
        return 1;
    }

    return 0;
};

/*
 * Returns 1 if Queue is empty
 * else 0.
 */
int IsEmpty(CircularQueue *circular_queue)
{
    return circular_queue->front == -1;
};

/*
 * Enqueu the given value in
 * the Queue.
 * Time complexity is O(1).
 */
void Enqueue(CircularQueue *circular_queue, int value)
{
    if (IsFull(circular_queue))
    {
        puts("Circular Queue is Full.");
        return;
    }

    if (IsEmpty(circular_queue))
    {
        circular_queue->front = 0;
    }

    circular_queue->rear = (circular_queue->rear + 1) % circular_queue->capacity;
    circular_queue->elements[circular_queue->rear] = value;
};

/*
 * Dequeue the element from
 * the Queue.
 * Returns the decircular_queued element else
 * -1 if Queue is empty.
 * Time complexity is O(1).
 */
int Dequeue(CircularQueue *circular_queue)
{
    if (IsEmpty(circular_queue))
    {
        puts("Circular Queue is Empty");
        return -1;
    }

    int element = circular_queue->elements[circular_queue->front];
    if (circular_queue->front == circular_queue->rear)
    {
        circular_queue->front = -1;
        circular_queue->rear = -1;
        return element;
    }

    circular_queue->front = (circular_queue->front + 1) % circular_queue->capacity;
    return element;
};

/*
 * Returns the Front element of
 * the CircularQueue else -1 if empty.
 * Time complexity is O(1).
 */
int Peek(CircularQueue *circular_queue)
{
    if (IsEmpty(circular_queue))
    {
        puts("Circular Queue is Empty");
        return -1;
    }
    return circular_queue->elements[circular_queue->front];
};

/*
 * Searches the  given value in
 * the Queue.
 * Returns 1 if found else 0.
 * Time complexity is O(N).
 */
int Search(CircularQueue *circular_queue, int value)
{
    for (int i = circular_queue->front; i < circular_queue->rear; i++)
    {
        if (circular_queue->elements[i] == value)
        {
            return 1;
        }
    }
    return 0;
};

/*
 * Prints the elements of
 * the CircularQueue.
 */
void PrintElements(CircularQueue *circular_queue)
{

    if (IsEmpty(circular_queue))
    {
        puts("Circular Queue is Empty");
        return;
    }

    int i = circular_queue->front;
    while (i != circular_queue->rear)
    {
        printf("%d ", circular_queue->elements[i]);
        i = (i + 1) % circular_queue->capacity;
    }
    printf("%d\n", circular_queue->elements[i]);
}

/*
 * Frees the memory of the given
 * CircularQueue.
 */
void Destroy(CircularQueue *circular_queue)
{
    if (circular_queue == NULL)
    {
        return;
    }
    free(circular_queue->elements);
    free(circular_queue);
}

int main()
{
    CircularQueue *circular_queue = NewCircularQueue(5);

    Enqueue(circular_queue, 1);
    Enqueue(circular_queue, 2);
    Enqueue(circular_queue, 3);
    Enqueue(circular_queue, 4);
    PrintElements(circular_queue);

    Dequeue(circular_queue);
    PrintElements(circular_queue);

    Enqueue(circular_queue, 0);
    PrintElements(circular_queue);

    Dequeue(circular_queue);
    PrintElements(circular_queue);

    Enqueue(circular_queue, 10);
    PrintElements(circular_queue);

    Destroy(circular_queue);

    return 0;
};
