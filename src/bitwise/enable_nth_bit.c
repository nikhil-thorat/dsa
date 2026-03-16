#include <stdio.h>

void solve()
{
    int N, n;

    printf("Enter num : ");
    scanf("%d", &N);

    printf("Enter n : ");
    scanf("%d", &n);

    n--;
    int mask = (1 << n);
    N = N | mask;

    printf("N : %d\n", N);
}

int main()
{
    solve();
    return 0;
}
