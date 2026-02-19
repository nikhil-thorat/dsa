#include <stdio.h>

void solve()
{
    int N;
    printf("Enter a number : ");
    scanf("%d", &N);

    int original = N;
    int reverse = 0;
    while (N > 0)
    {
        reverse += N % 10;
        if (N >= 10)
        {
            reverse *= 10;
        }
        N = N / 10;
    }

    if (original == reverse)
    {
        printf("Palindrome\n");
    }
    else
    {
        printf("Not Palindrome\n");
    }
}

int main()
{
    solve();
    return 0;
}
