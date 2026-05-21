#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

/*
 * Creates a Node and returns
 * a pointer to it.
 */
Node *NewNode(int data)
{
    Node *node = malloc(sizeof(Node));
    node->data = data;

    node->next = NULL;
    node->prev = NULL;

    return node;
}

/*
 * Implementation of Deque or Double Ended Queue
 * using Doubly linked list.
 */
typedef struct
{
    Node *front;
    Node *rear;
} Deque;

/*
 * Creates a Deque and returns
 * a pointer to it.
 */
Deque *NewDeque()
{
    Deque *deque = malloc(sizeof(Deque));
    deque->front = NULL;
    deque->rear = NULL;

    return deque;
}

/*
 * Insert's the data at the front
 * of the Deque.
 */
void InsertFront(Deque *deque, int data)
{
    Node *new_node = NewNode(data);

    if (deque->front == NULL)
    {
        deque->front = new_node;
        deque->rear = new_node;
        return;
    }

    new_node->next = deque->front;
    deque->front->prev = new_node;
    deque->front = new_node;
}

/*
 * Insert's the data at the end
 * of the Deque.
 */
void InsertRear(Deque *deque, int data)
{
    Node *new_node = NewNode(data);

    if (deque->front == NULL)
    {
        deque->front = new_node;
        deque->rear = new_node;
        return;
    }

    deque->rear->next = new_node;
    new_node->prev = deque->rear;
    deque->rear = new_node;
}

/*
 * Delete's the element at the front
 * of the Deque.
 */
void DeleteFront(Deque *deque)
{
    if (deque->front == NULL)
    {
        return;
    }

    Node *temp = deque->front;
    deque->front = temp->next;

    if (deque->front == NULL)
    {
        deque->rear = NULL;
    }
    else
    {
        deque->front->prev = NULL;
    }

    free(temp);
}

/*
 * Delete's the element from the end
 * of the Deque.
 */
void DeleteRear(Deque *deque)
{
    if (deque->rear == NULL)
    {
        return;
    }

    Node *temp = deque->rear;
    deque->rear = temp->prev;

    if (deque->rear == NULL)
    {
        deque->front = NULL;
    }
    else
    {

        deque->rear->next = NULL;
    }

    free(temp);
}

/*
 * Check's if the Deque is empty.
 */
int IsEmpty(Deque *deque)
{
    if (deque->front == NULL)
    {
        return 1;
    }
    return 0;
}

/*
 * Return's the front element of Deque.
 */
int GetFront(Deque *deque)
{
    if (IsEmpty(deque))
    {
        return -1;
    }

    return deque->front->data;
}

/*
 * Return's the rear element of Deque.
 */
int GetRear(Deque *deque)
{
    if (IsEmpty(deque))
    {
        return -1;
    }

    return deque->rear->data;
}

/*
 * Frees the memory allocated to Deque.
 */
void Destroy(Deque *deque)
{
    while (deque->front)
    {
        Node *temp = deque->front;
        deque->front = temp->next;
        free(temp);
    }
    free(deque);
}

/*
 * Prints the elements of the Deque.
 */
void Print(Deque *deque)
{
    Node *current = deque->front;
    while (current)
    {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main()
{
    Deque *deque = NewDeque();

    InsertFront(deque, 1);
    InsertFront(deque, 2);
    Print(deque);

    int front = GetFront(deque);
    if (front != -1)
    {
        printf("Front of Deque : %d\n", front);
    }

    InsertRear(deque, 3);
    InsertRear(deque, 4);
    Print(deque);

    int rear = GetRear(deque);
    if (rear != -1)
    {
        printf("Rear of Deque : %d\n", rear);
    }

    DeleteFront(deque);
    Print(deque);

    DeleteRear(deque);
    Print(deque);

    DeleteRear(deque);
    DeleteRear(deque);
    Print(deque);

    Destroy(deque);

    return 0;
}
