#include <stdio.h>
#include <stdlib.h>

/*
 * Custom Vector type.
 */
typedef struct
{
    int size;
    int capacity;
    int *vector;
} Vector;

/*
 * Creates a new Vector of a given capacity
 * and returns a pointer to it.
 */
Vector *NewVector(int cap)
{
    Vector *vector = malloc(sizeof(Vector));
    vector->capacity = cap;
    vector->size = 0;
    vector->vector = malloc(vector->capacity * sizeof(int));
    return vector;
};

/*
 * Resizes the given Vector with the given capacity.
 */
void Resize(Vector *vector, int cap)
{
    int *new_array = malloc(cap);
    for (int i = 0; i < vector->size; i++)
    {
        new_array[i] = vector->vector[i];
    }

    free(vector->vector);
    vector->vector = new_array;
    vector->capacity = cap;
}

/*
 * Adds the given element at the end of the Vector.
 */
void Push(Vector *vector, int value)
{
    if (vector->size == vector->capacity)
    {
        Resize(vector, vector->capacity * 2);
    }

    vector->vector[vector->size] = value;
    vector->size++;
}

/*
 * Removes the last element from the given Vector.
 */
void Pop(Vector *vector)
{
    if (vector->size == (vector->capacity / 4))
    {
        Resize(vector, vector->capacity / 2);
    }

    vector->size--;
}

/*
 * Returns the size of the Vector.
 */
int GetSize(Vector *vector)
{
    return vector->size;
}

/*
 * Returns the capacity of the Vector.
 */
int GetCapacity(Vector *vector)
{
    return vector->capacity;
}

/*
 * Checks if the Vector is empty.
 * Returns 1 if empty else 0.
 */
int IsEmpty(Vector *vector)
{
    return vector->size == 0;
}

/*
 * Heapifies the given Array.
 */
void Heapify(Vector *vector, int idx, int size)
{
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    int max = idx;

    if (left <= size && vector->vector[left] > vector->vector[max])
    {
        max = left;
    }

    if (right <= size && vector->vector[right] > vector->vector[max])
    {
        max = right;
    }

    if (max != idx)
    {
        int temp = vector->vector[max];
        vector->vector[max] = vector->vector[idx];
        vector->vector[idx] = temp;
        Heapify(vector, max, size);
    }
}

/*
 * Builds a MaxHeap from given Array.
 */
void BuildHeap(Vector *vector, int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        Heapify(vector, i, size);
    }
}

/*
 * Implementation of Priority Queue using Vector
 */
typedef struct
{
    Vector *vector;
} PriorityQueue;

/*
 * Creates a PriotiyQueue and
 * returns a pointer to it.
 */
PriorityQueue *NewPriorityQueue()
{
    PriorityQueue *priority_queue = malloc(sizeof(PriorityQueue));
    priority_queue->vector = NewVector(1);

    return priority_queue;
};

/*
 * Insert the given element in the PriorityQueue
 * while managing the priority based on the value
 */
void Insert(PriorityQueue *priority_queue, int value)
{
    if (priority_queue->vector->size == 0)
    {
        Push(priority_queue->vector, value);
        return;
    }

    Push(priority_queue->vector, value);
    BuildHeap(priority_queue->vector, priority_queue->vector->size);
};

/*
 * Get highest priority element from the PriorityQueue
 */
int HighestPriority(PriorityQueue *priority_queue)
{
    if (priority_queue->vector->size == 0)
    {
        return -1;
    }

    return priority_queue->vector->vector[0];
}

/*
 * Deletes the highest priority element from the
 * PriorityQueue
 */
void Dequeue(PriorityQueue *priority_queue)
{
    int temp = priority_queue->vector->vector[0];
    priority_queue->vector->vector[0] = priority_queue->vector->vector[priority_queue->vector->size - 1];
    priority_queue->vector->vector[priority_queue->vector->size - 1] = temp;
    priority_queue->vector->size--;

    printf("Max = %d\n", priority_queue->vector->vector[priority_queue->vector->size]);
    Heapify(priority_queue->vector, 0, priority_queue->vector->size);
}

/*
 * Prints the elements of the PriorityQueue
 */
void Print(PriorityQueue *priority_queue)
{
    for (int i = 0; i < priority_queue->vector->size; i++)
    {
        printf("%d ", priority_queue->vector->vector[i]);
    }
    printf("\n");
}

int main()
{
    PriorityQueue *priority_queue = NewPriorityQueue();

    Insert(priority_queue, 10);
    Insert(priority_queue, 20);
    Insert(priority_queue, 30);
    Insert(priority_queue, 40);
    Print(priority_queue);

    int hightest_priority = HighestPriority(priority_queue);
    printf("Highest Priority Element is : %d\n", hightest_priority);

    Insert(priority_queue, 50);
    Print(priority_queue);

    hightest_priority = HighestPriority(priority_queue);
    printf("Highest Priority Element is : %d\n", hightest_priority);

    Dequeue(priority_queue);
    Print(priority_queue);

    hightest_priority = HighestPriority(priority_queue);
    printf("Highest Priority Element is : %d\n", hightest_priority);

    return 0;
};
