#include <stdio.h>

/*
 * Binary Search
 * Time Complexity : O(log N)
 * Space Complexity : O(1)
 *
 * Note the array must be sorted for Binary Search to work.
 */
int BinarySearch(int array[], size_t len, int key)
{
    int start = 0;
    int end = len;

    int mid = start + ((end - start) / 2);

    while (start <= end)
    {
        if (array[mid] == key)
        {
            return mid;
        }

        if (array[mid] > key)
        {
            end = mid - 1;
        }

        if (array[mid] < key)
        {
            start = mid + 1;
        }

        mid = start + ((end - start) / 2);
    }

    return -1;
}

int main()
{
    int array[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    size_t len = 9;
    int key = 90;

    int result = BinarySearch(array, len, key);
    if (result != -1)
    {
        printf("%d exists in array!\n", key);
    }
    else
    {
        printf("%d does not exists in array!\n", key);
    }

    key = 100;

    result = BinarySearch(array, len, key);
    if (result != -1)
    {
        printf("%d exists in array!\n", key);
    }
    else
    {
        printf("%d does not exists in array!\n", key);
    }

    return 0;
};
