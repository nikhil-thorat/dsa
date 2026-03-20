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
 * Prints the elements of the given Vector.
 */
void PrintElements(Vector *vector)
{
    printf("Elements : ");
    for (int i = 0; i < vector->size; i++)
    {
        printf("%d ", vector->vector[i]);
    }
    printf("\n");
}

/*
 * Searches the given value in the Vector.
 * Returns the index of the value if found,
 * else -1.
 * Worst case time complexity is O(N)
 * and best case time complexity is O(1).
 */
int Search(Vector *vector, int value)
{
    for (int i = 0; i < vector->size; i++)
    {
        if (vector->vector[i] == value)
        {
            return i;
        }
    }
    return -1;
};

int main()
{
    Vector *vector = NewVector(5);

    Push(vector, 1);
    Push(vector, 2);
    Push(vector, 3);
    Push(vector, 4);
    Push(vector, 5);

    int capacity = GetCapacity(vector);
    int size = GetSize(vector);

    printf("Capacity of Vector : %d\n", capacity);
    printf("Size of Vector : %d\n", size);
    PrintElements(vector);

    int value = 4;
    int index = Search(vector, value);
    if (index != -1)
    {
        printf("Value %d found at index %d\n", value, index);
    }
    else
    {
        printf("Value %d not found in the Vector\n", value);
    }

    puts("Adding more elements to the Vector");
    Push(vector, 6);
    Push(vector, 7);

    capacity = GetCapacity(vector);
    printf("Capacity of Vector : %d\n", capacity);
    PrintElements(vector);

    puts("Removing elements from the Vector for resizing");
    Pop(vector);
    Pop(vector);
    Pop(vector);
    Pop(vector);
    Pop(vector);
    Pop(vector);

    capacity = GetCapacity(vector);
    printf("Capacity of Vector : %d\n", capacity);
    PrintElements(vector);

    free(vector->vector);
    free(vector);

    return 0;
}
