#include <stdio.h>

/*
 * Problem Statement
 * Given an array of integers and a rotation count rotate_count,
 * rotate the array to the right by rotate_count positions.
 *
 * Input
 *   array : {1, 2, 3, 4, 5}
 *   length : 5
 *   rotate_count : 2
 *
 * Output
 * {4, 5, 1, 2, 3}
 *
 * Explanation
 * After rotating the array 2 positions to the right,
 * the last two elements move to the front while the
 * remaining elements shift to the right.
 */

/*
 * Brute Force Solution
 *
 * Time Complexity : O (length * rotate_count) i.e O(n * k)
 * Space Complexity : O(1)
 *
 * void RotateArray(int array[], size_t length, int rotate_count)
 * {
 *     for (int i = 0; i < rotate_count; i++)
 *     {
 *         for (int j = length - 1; j > 0; j--)
 *         {
 *             int temp = array[j];
 *             array[j] = array[j - 1];
 *             array[j - 1] = temp;
 *         }
 *     }
 * }
 */

/*
 * Reverses the array from starting index to the
 * ending index.
 */
void Reverse(int array[], int start, int end)
{
    int i = start;
    int j = end - 1;
    while (i <= j)
    {
        int temp = array[j];
        array[j] = array[i];
        array[i] = temp;

        i++;
        j--;
    }
}

/*
 * Optimal Solution using Reversal technique.
 *
 * Time Complexity : O(length) + O(rotate_count) + O(length - rotate_count) i.e O(n)
 * Space Complexity : O(1)
 */
void RotateArray(int array[], size_t length, int rotate_count)
{
    Reverse(array, 0, length);
    Reverse(array, 0, rotate_count);
    Reverse(array, rotate_count, length);
}

/*
 * Prints the elements of the array.
 */
void Print(int array[], size_t length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main()
{
    size_t length = 0;
    printf("Enter length : ");
    scanf("%zd", &length);

    int array[length];
    for (int i = 0; i < length; i++)
    {
        printf("Enter element at %d : ", i);
        scanf("%d", &array[i]);
    }

    int rotate_count = 0;
    printf("Enter Rotate count : ");
    scanf("%d", &rotate_count);

    printf("Before Rotations : ");
    Print(array, length);

    RotateArray(array, length, rotate_count);

    printf("After Rotations : ");
    Print(array, length);

    return 0;
}
