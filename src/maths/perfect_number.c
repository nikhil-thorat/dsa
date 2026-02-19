#include <stdio.h>

void solve()
{
    int N;
    printf("Enter a number : ");
    scanf("%d", &N);

    int divisor_sum = 0;
    for (int i = 1; i < N; i++)
    {
        if (N % i == 0)
        {
            divisor_sum += i;
        }
    }

    if (N == divisor_sum)
    {
        printf("Perfect Number\n");
    }
    else
    {
        printf("Not a Perfect Number\n");
    }
}

int main()
{
    solve();
    return 0;
}
