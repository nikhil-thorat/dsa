#include <stdio.h>

/*
 * Selection Sort
 *
 * Time Complexity : O(N^2)
 * Space Complexity : O(1)
 */
void SelectionSort(int array[], size_t len)
{
    for (int i = 0; i < len - 1; i++)
    {

        for (int j = i + 1; j < len; j++)
        {
            if (array[j] < array[i])
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
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

    SelectionSort(array, len);

    printf("Sorted : ");
    Print(array, len);

    return 0;
}
