#include <stdio.h>

/*
 * Linear Search
 * Time Complexity : O(n)
 * Space Complexity : O(1)
 */
int LinearSearch(int array[], size_t len, int key)
{
    for (int i = 0; i < len; i++)
    {
        if (array[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int array[] = {10, 30, 60, 20, 50, 70, 40, 90, 80};
    size_t len = 9;
    int key = 90;

    int result = LinearSearch(array, len, key);
    if (result != -1)
    {
        printf("%d exists in array!\n", key);
    }
    else
    {
        printf("%d does not exists in array!\n", key);
    }

    key = 100;

    result = LinearSearch(array, len, key);
    if (result != -1)
    {
        printf("%d exists in array!\n", key);
    }
    else
    {
        printf("%d does not exists in array!\n", key);
    }

    return 0;
}
