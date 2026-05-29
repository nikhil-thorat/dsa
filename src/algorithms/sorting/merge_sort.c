#include <stdio.h>
#include <stdlib.h>

/*
 * Merge Sorted Array
 */
void MergeSortedArray(int array[], int start, int mid, int end)
{
    int temp[end - start + 1];

    int i = start;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= end)
    {
        if (array[i] < array[j])
        {
            temp[k] = array[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = array[j];
            j++;
            k++;
        }
    }

    while (i <= mid)
    {
        temp[k] = array[i];
        i++;
        k++;
    }

    while (j <= end)
    {
        temp[k] = array[j];
        j++;
        k++;
    }

    k = 0;
    for (int i = start; i <= end; i++)
    {
        array[i] = temp[k];
        k++;
    }
}

/*
 * Merge Sort
 *
 * Time Complexity : O(N log N)
 * Space Complexity : O(N)
 */
void MergeSort(int array[], int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        MergeSort(array, start, mid);
        MergeSort(array, mid + 1, end);
        MergeSortedArray(array, start, mid, end);
    }
}

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

    MergeSort(array, 0, len - 1);

    printf("Sorted : ");
    Print(array, len);

    return 0;
}
