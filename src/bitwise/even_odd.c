#include <stdio.h>

void solve()
{
    int N;

    printf("Enter num : ");
    scanf("%d", &N);

    if ((N & 1) == 0)
    {
        printf("Even\n");
    }
    else
    {
        printf("Odd\n");
    }
}

int main()
{
    solve();
    return 0;
}
