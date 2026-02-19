#include <stdio.h>

void solve()
{
    int N;
    printf("Enter a number : ");
    scanf("%d", &N);

    int sum = 0;

    while (N != 0)
    {
        sum += N % 10;
        N = N / 10;
    }

    printf("Sum of digits : %d\n", sum);
}

int main()
{
    solve();
    return 0;
}
