#include <stdio.h>

/*
 * Insertion Sort
 *
 * Time Complexity : O(N^2)
 * Space Complexity : O(1)
 */
void InsertionSort(int array[], size_t len)
{
    for (int i = 1; i < len; i++)
    {
        int value = array[i];
        int idx = i;

        while (idx > 0 && value < array[idx - 1])
        {
            array[idx] = array[idx - 1];
            idx--;
        }

        array[idx] = value;
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

    InsertionSort(array, len);

    printf("Sorted : ");
    Print(array, len);

    return 0;
}
