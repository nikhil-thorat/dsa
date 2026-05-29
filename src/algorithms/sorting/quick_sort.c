#include <stdio.h>

/*
 * Swap function
 */
void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*
 * Partition function for Quick Sort
 * Returns the pivot index of the given array.
 */
int Partition(int array[], int start, int end)
{
    int pivot_index = start;
    int pivot = array[end];

    for (int i = start; i < end; i++)
    {
        if (array[i] < pivot)
        {
            Swap(&array[i], &array[pivot_index]);
            pivot_index++;
        }
    }

    Swap(&array[end], &array[pivot_index]);
    return pivot_index;
}

/*
 * Quick Sort
 * (Uses Divide and Conquer technique)
 *
 * Time Complexity : O(N^2)
 * Space Complexity : O(N) --recursive call stack
 */
void QuickSort(int array[], int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int pivot_index = Partition(array, 0, end);
    QuickSort(array, start, pivot_index - 1);
    QuickSort(array, pivot_index + 1, end);
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

    QuickSort(array, 0, len - 1);

    printf("Sorted : ");
    Print(array, len);

    return 0;
}
