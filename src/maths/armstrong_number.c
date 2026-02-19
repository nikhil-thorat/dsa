#include <math.h>
#include <stdio.h>

void solve()
{
    int N;
    printf("Enter a number : ");
    scanf("%d", &N);

    int original = N;
    int armstrong = 0;

    int temp = N;
    int digits = 0;

    while (temp != 0)
    {
        digits++;
        temp = temp / 10;
    }

    while (N != 0)
    {
        armstrong += pow(N % 10, digits);
        N = N / 10;
    }

    if (armstrong == original)
    {
        printf("Armstrong Number\n");
    }
    else
    {
        printf("Not an Armstrong Number\n");
    }
}

int main()
{
    solve();
    return 0;
}
