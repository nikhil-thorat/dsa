#include <stdio.h>

/*
 * Helper function
 */
int FibHelper(int num, int dp[])
{
    if (dp[num] == -1)
    {
        if (num <= 1)
        {
            dp[num] = num;
        }
        else
        {
            dp[num] = FibHelper(num - 1, dp) + FibHelper(num - 2, dp);
        }
    }
    return dp[num];
}

/*
 * Calculates the nth Fibonacci term using
 * TopDown Approach and Memoization
 */
int Fibonacci(int num)
{
    int dp[num];
    for (int i = 0; i <= num; i++)
    {
        dp[i] = -1;
    };

    return FibHelper(num, dp);
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
