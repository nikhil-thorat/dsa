#include <stdio.h>

/*
 * Binary Search using Divide and Conquer Technique.
 * Time Complexity : O(log N)
 * Space Complexity : O(log N) --recursive call stack
 *
 * Note the array must be sorted for Binary Search to work.
 */
int BinarySearch(int array[], int start, int end, int key)
{

    if (start >= end)
    {
        return -1;
    }

    int mid = start + (end - start) / 2;
    if (array[mid] == key)
    {
        return mid;
    }
    if (array[mid] > key)
    {
        return BinarySearch(array, start, mid - 1, key);
    }
    else
    {
        return BinarySearch(array, mid + 1, end, key);
    }
}

int main()
{
    int array[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    size_t len = 9;
    int key = 90;

    int result = BinarySearch(array, 0, len - 1, key);
    if (result != -1)
    {
        printf("%d exists in array!\n", key);
    }
    else
    {
        printf("%d does not exists in array!\n", key);
    }

    key = 100;

    result = BinarySearch(array, 0, len - 1, key);
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
