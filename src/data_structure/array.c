#include <stdio.h>
#include <stdlib.h>

/*
 * Custom Array type.
 */
typedef struct
{
    int size;
    int capacity;
    int *array;
} Array;

/*
 * Creates a new Array of a given capacity
 * and returns a pointer to it.
 */
Array *NewArray(int cap)
{
    Array *array = malloc(sizeof(Array));
    array->capacity = cap;
    array->size = 0;
    array->array = malloc(array->capacity);
    return array;
};

/*
 * Inserts a given element at a given
 * index in the Array.
 * Worst case time complexity is O(N)
 * and the best case time complexity is
 * O(1).
 */
void InsertAt(Array *array, unsigned int index, int value)
{
    if (index > array->size)
    {
        puts("Index out of bound");
        return;
    }

    for (int i = array->size; i > index; i--)
    {
        array->array[i] = array->array[i - 1];
    }

    array->array[index] = value;
    array->size++;
}

/*
 * Deltes an element at a given index
 * from the Array.
 * Worst case time complexity is O(N)
 * and the best case time complexity is
 * O(1).
 */
void DeleteFrom(Array *array, unsigned int index)
{
    if (index > array->size)
    {
        puts("Index out of bound");
        return;
    }

    if (array->size == 0)
    {
        puts("Array is Empty, no Element to delete");
        return;
    }

    if (array->size - 1 == index)
    {
        array->size--;
        return;
    }

    for (int i = index; i < array->size; i++)
    {
        array->array[i] = array->array[i + 1];
    }

    array->size--;
}

/*
 * Returns the size of the Array.
 */
int GetSize(Array *array)
{
    return array->size;
}

/*
 * Returns the capacity of the Array.
 */
int GetCapacity(Array *array)
{
    return array->capacity;
}

/*
 * Checks if the Array is empty.
 * Returns 1 if empty else 0.
 */
int IsEmpty(Array *array)
{
    return array->size == 0;
}

/*
 * Prints the elements of the given Array.
 */
void PrintElements(Array *array)
{
    printf("Elements : ");
    for (int i = 0; i < array->size; i++)
    {
        printf("%d ", array->array[i]);
    }
    printf("\n");
}

/*
 * Searches the given value in the Array.
 * Returns the index of the value if found,
 * else -1.
 * Worst case time complexity is O(N)
 * and best case time complexity is O(1).
 */
int Search(Array *array, int value)
{
    for (int i = 0; i < array->size; i++)
    {
        if (array->array[i] == value)
        {
            return i;
        }
    }
    return -1;
};

int main()
{
    Array *array = NewArray(5);

    InsertAt(array, 0, 1);
    InsertAt(array, 1, 2);
    InsertAt(array, 2, 3);
    InsertAt(array, 3, 4);
    InsertAt(array, 4, 5);

    int capacity = GetCapacity(array);
    int size = GetSize(array);

    printf("Capacity of Array : %d\n", capacity);
    printf("Size of Array : %d\n", size);
    PrintElements(array);

    DeleteFrom(array, 3);
    printf("Deleting element at index 3\n");
    PrintElements(array);

    int value = 4;
    int index = Search(array, value);
    if (index != -1)
    {
        printf("Value %d found at index %d\n", value, index);
    }
    else
    {
        printf("Value %d not found in the Array\n", value);
    }

    return 0;
}
