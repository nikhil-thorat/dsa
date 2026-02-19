#include <stdio.h>

int fibonacci(int n)
{
    if (n == 0)
    {
        return 0;
    }

    if (n == 1 || n == 2)
    {
        return 1;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}

void solve()
{
    int N;
    printf("Enter a number : ");
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        printf("%d ", fibonacci(i));
    }

    printf("\n");
}

int main()
{
    solve();
    return 0;
}
