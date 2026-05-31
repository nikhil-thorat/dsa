#include <stdio.h>

/*
 * Given coin denominations sorted in descending order,
 * repeatedly select the largest possible coin until
 * the amount becomes zero.
 *
 * Returns the number of coins chosen by the greedy strategy.
 */
int MinCoins(int coins[], size_t size, int amount)
{
    int coin_count = 0;

    for (int i = 0; i < size; i++)
    {
        while (amount >= coins[i])
        {
            amount = amount - coins[i];
            coin_count++;
        }

        if (amount == 0)
        {
            break;
        }
    }

    return coin_count;
}

int main()
{
    int amount = 0;

    printf("Enter amount : ");
    scanf("%d", &amount);

    int coins[] = {25, 20, 10, 5};
    size_t size = 4;

    int min_coins = MinCoins(coins, size, amount);
    printf("Minimum coins needed : %d\n", min_coins);

    return 0;
}
