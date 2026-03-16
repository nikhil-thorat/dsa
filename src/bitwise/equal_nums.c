#include <stdio.h>

void solve()
{
    int num1, num2;

    printf("Enter num1 : ");
    scanf("%d", &num1);

    printf("Enter num2 : ");
    scanf("%d", &num2);

    if ((num1 ^ num2) == 0)
    {
        printf("Equal\n");
    }
    else
    {
        printf("Not Equal\n");
    }
}

int main()
{
    solve();
    return 0;
}
