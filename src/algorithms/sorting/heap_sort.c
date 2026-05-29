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
 * Heap Sort
 *
 * Time Complexity : O(N^2)
 * Space Complexity : O(1)
 */
void HeapSort(int array[], size_t len)
{
    BuildHeap(array, len);

    int i = len - 1;
    while (i > 0)
    {
        int temp = array[i];
        array[i] = array[0];
        array[0] = temp;
        i--;
        Heapify(array, 0, i);
    }
};

/*
 * Prints the elements of the Array.
 */
void Print(int array[], size_t len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main()
{
    int array[] = {10, 30, 60, 20, 50, 70, 40, 90, 80};
    size_t len = 9;

    printf("Unsorted : ");
    Print(array, len);

    HeapSort(array, len);

    printf("Sorted : ");
    Print(array, len);

    return 0;
}
