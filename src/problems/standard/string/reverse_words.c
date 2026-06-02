#include <stdio.h>
#include <string.h>

/*
 * Reverses the given string from the start point
 * to the end point.
 */
void Reverse(char *string, int start, int end)
{
    int i = start;
    int j = end - 1;
    while (i < j)
    {
        char temp = string[i];
        string[i] = string[j];
        string[j] = temp;

        i++;
        j--;
    }
}

/*
 * Problem Statement
 * Given a string containing one or more words,
 * reverse each word individually while preserving
 * the original word order and spaces.
 *
 * Example:
 * Input:
 *   "Hello World"
 *
 * Output:
 *   "olleH dlroW"
 *
 * Explanation:
 * Each word is reversed in place, but the order
 * of the words remains unchanged.
 */
void ReverseWord(char *string)
{
    size_t length = strlen(string) - 1;

    int idx = 0;
    while (idx < length)
    {
        int start = idx;
        int end = idx;

        while (string[end] != ' ' && end < length)
        {
            end++;
        }

        Reverse(string, start, end);
        idx += end + 1;
    }
}

int main()
{
    char string[64];
    printf("Enter a string : ");
    fgets(string, sizeof(string), stdin);

    printf("Before Reversing words : %s", string);
    ReverseWord(string);
    printf("After Reversing words : %s", string);

    return 0;
}
