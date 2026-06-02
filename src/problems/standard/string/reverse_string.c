#include <stdio.h>
#include <string.h>

/*
 * Problem Statement
 * Given a string containing alphabetic characters and
 * special characters, reverse only the alphabetic
 * characters while keeping all special characters in
 * their original positions.
 *
 * Example:
 * Input:
 *   "a*bcd,e$"
 *
 * Output:
 *   "e*dcb,a$"
 *
 * Explanation:
 * Only the letters are reversed. The positions of
 * '*', ',' and '$' remain unchanged.
 */
void ReverseString(char *string)
{
    size_t len = strlen(string) - 1;

    int start = 0;
    int end = len;

    while (start <= end)
    {
        if ((string[start] < 65 || string[start] > 90) && (string[start] < 97 || string[start] > 122))
        {
            start++;
            continue;
        }
        else if ((string[end] < 65 || string[end] > 90) && (string[end] < 97 || string[end] > 122))
        {
            end--;
            continue;
        }
        else
        {
            char temp = string[start];
            string[start] = string[end];
            string[end] = temp;

            start++;
            end--;
        }
    }
}

int main()
{
    char string[64];
    printf("Enter a string : ");
    fgets(string, sizeof(string), stdin);

    printf("Before Reversing : %s", string);
    ReverseString(string);
    printf("After Reversing : %s", string);

    return 0;
}
