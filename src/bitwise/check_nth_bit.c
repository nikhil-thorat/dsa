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

    if ((N & mask) != 0)
    {
        printf("Set\n");
    }
    else
    {
        printf("Not set\n");
    }
}

int main()
{
    solve();
    return 0;
}
