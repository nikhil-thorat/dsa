#include <stdio.h>
#include <stdlib.h>

/*
 * Represents a Node for
 * the Queue.
 */
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

/*
 * Creates a new Node with given data, and sets
 * the next pointer to NULL and returns a pointer
 * to it.
 */
Node *NewNode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;

    return node;
}

/*
 * Represents s Queue, implemeted
 * using Linked List
 */
typedef struct
{
    Node *front;
    Node *rear;
} Queue;

Queue *NewQueue()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;

    return queue;
};

/*
 * Returns 1 if Queue is empty
 * else 0.
 */
int IsEmpty(Queue *queue)
{
    return queue->front == NULL;
};

/*
 * Enqueues the given value in
 * the Queue.
 * Time complexity is O(1).
 */
void Enqueue(Queue *queue, int value)
{
    Node *new_node = NewNode(value);

    if (IsEmpty(queue))
    {
        queue->front = new_node;
        queue->rear = new_node;
        return;
    }

    queue->rear->next = new_node;
    queue->rear = new_node;
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

    Node *temp = queue->front;
    queue->front = queue->front->next;

    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }

    int result = temp->data;
    free(temp);

    return result;
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

    return queue->front->data;
};

/*
 * Searches the  given value in
 * the Queue.
 * Returns 1 if found else 0.
 * Time complexity is O(N).
 */
int Search(Queue *queue, int value)
{
    Node *current = queue->front;
    while (current)
    {
        if (current->data == value)
        {
            return 1;
        }
        current = current->next;
    }

    return 0;
}

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

    Node *current = queue->front;
    while (current)
    {
        printf("%d ", current->data);
        current = current->next;
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

    while (queue->front)
    {
        Node *temp = queue->front;
        queue->front = queue->front->next;
        free(temp);
    }

    free(queue);
}

int main()
{
    Queue *queue = NewQueue();

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
