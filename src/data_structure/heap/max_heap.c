#include <stdio.h>

/*
 * Heapifies the given Array.
 */
void Heapify(int array[], int idx, int size)
{
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    int max = idx;

    if (left <= size && array[left] > array[max])
    {
        max = left;
    }

    if (right <= size && array[right] > array[max])
    {
        max = right;
    }

    if (max != idx)
    {
        int temp = array[max];
        array[max] = array[idx];
        array[idx] = temp;
        Heapify(array, max, size);
    }
}

/*
 * Builds a MaxHeap from given Array.
 */
void BuildHeap(int array[], int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        Heapify(array, i, size);
    }
}

/*
 * Delete's the Maximum element from the Heap.
 */
void DeleteMax(int array[], int *size)
{
    int temp = array[0];
    array[0] = array[*size - 1];
    array[*size - 1] = temp;
    (*size)--;

    printf("Max = %d\n", array[*size]);
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

    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = 9;

    printf("Before : ");
    Print(array, size);

    BuildHeap(array, size);

    printf("After : ");
    Print(array, size);

    DeleteMax(array, &size);
    Print(array, size);

    DeleteMax(array, &size);
    Print(array, size);

    return 0;
}
