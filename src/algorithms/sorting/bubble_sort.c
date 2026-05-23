#include <stdio.h>

/*
 * Bubble Sort
 *
 * Time Complexity : O(N^2)
 * Space Complexity : O(1)
 */
void BubbleSort(int array[], size_t len)
{
    for (int i = 0; i < len - 1; i++)
    {
        int swapped = 0;
        for (int j = 0; j < len - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;

                swapped = 1;
            }
        }

        if (!swapped)
        {
            break;
        }
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

    BubbleSort(array, len);

    printf("Sorted : ");
    Print(array, len);

    return 0;
}
