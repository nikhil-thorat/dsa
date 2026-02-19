#include <stdio.h>

void solve()
{
    int N;
    printf("Enter a number : ");
    scanf("%d", &N);

    for (int i = 2; i < N; i++)
    {
        if (N % i == 0)
        {
            printf("Not a Prime Number\n");
            return;
        }
    }

    printf("Prime Number\n");
}

int main()
{
    solve();
    return 0;
}
