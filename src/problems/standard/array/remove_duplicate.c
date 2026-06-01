#include <stdio.h>
#include <time.h>

/*
 * Problem Statement
 * Given an sorted array, remove the duplicate elements from
 * the array and return the new length of the array.
 *
 * Input
 * array : {1,1,1,3,3,5,5}
 * length : 7
 *
 * Output
 * 3 -- length after removing duplicates.
 * i.e {1,3,5}
 */
int RemoveDuplicates(int array[], size_t length)
{
    if (length == 1)
    {
        return length;
    }

    int i = 0;
    int mark = 0;

    while (i < length)
    {
        int j = i;
        while (array[j] == array[i] && j < length)
        {
            j++;
        }

        mark++;
        array[mark] = array[j];

        i = j;
    }

    return mark;
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

    Print(array, length);

    int result = RemoveDuplicates(array, length);
    printf("Length after removing duplicates : %d\n", result);

    Print(array, length);

    return 0;
}
