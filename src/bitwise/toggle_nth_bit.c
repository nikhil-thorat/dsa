#include <stdio.h>

void solve()
{
    int N, n;

    printf("Enter num : ");
    scanf("%d", &N);

    printf("Enter n : ");
    scanf("%d", &n);

    N = N ^ 1 << (n - 1);
    printf("%d", N);

}

int main()
{
    solve();
    return 0;
}
