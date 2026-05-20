#include <stdio.h>

/*
 * Heapifies the given Array.
 */
void Heapify(int array[], int idx, int size)
{
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    int min = idx;

    if (left < size && array[left] < array[min])
    {
        min = left;
    }

    if (right < size && array[right] < array[min])
    {
        min = right;
    }

    if (min != idx)
    {
        int temp = array[min];
        array[min] = array[idx];
        array[idx] = temp;
        Heapify(array, min, size);
    }
}

/*
 * Builds a MinHeap from given Array.
 */
void BuildHeap(int array[], int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        Heapify(array, i, size);
    }
}

/*
 * Delete's the Minimum element from the Heap.
 */
void DeleteMin(int array[], int *size)
{
    int temp = array[0];
    array[0] = array[*size - 1];
    array[*size - 1] = temp;
    (*size)--;

    printf("Min = %d\n", temp);
    Heapify(array, 0, *size);
}

/*
 * Prints elements of the Array.
 */
void Print(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main()
{

    int array[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int size = 9;

    printf("Before : ");
    Print(array, size);

    BuildHeap(array, size);

    printf("After : ");
    Print(array, size);

    DeleteMin(array, &size);
    Print(array, size);

    DeleteMin(array, &size);
    Print(array, size);

    return 0;
}
