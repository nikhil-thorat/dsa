#include <stdio.h>
#include <stdlib.h>

void solve()
{
    int n;
    printf("Enter the number of elements : ");
    scanf("%d", &n);

    int *arr = malloc(n);

    for (int i = 0; i < n; i++) {
        printf("Enter element at %d ", i);
        scanf("%d", &arr[i]);
    }

    int res = arr[0];
    for (int i = 1; i < n; i++) {
        res ^= arr[i];
    }

    printf("%d", res);
}

int main()
{
    solve();
    return 0;
}

