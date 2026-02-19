#include <stdio.h>

void solve()
{
    int N;
    printf("Enter a number : ");
    scanf("%d", &N);

    int sum = (N * (N + 1)) / 2;

    printf("Sum of natural numbers to %d is : %d\n", N, sum);
}

int main()
{
    solve();
    return 0;
}
