#include <stdio.h>

/*
 * Calculates the nth Fibonacci term using
 * BottomUp Approach
 */
int Fibonacci(int num)
{
    int fib[num];
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= num; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    return fib[num];
};

int main()
{

    int num = 0;
    printf("Enter a number : ");
    scanf("%d", &num);

    int fib = Fibonacci(num);

    printf("Fibonacci at %dth is : %d\n", num, fib);

    return 0;
};
