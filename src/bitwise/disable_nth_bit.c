#include <stdio.h>

void solve()
{
    int N, n;

    printf("Enter num : ");
    scanf("%d", &N);

    printf("Enter n : ");
    scanf("%d", &n);

    int mask = ~(1 << (n-1));
    N = N & n;

    printf("%d", N);
}

int main()
{
    solve();
    return 0;
}
