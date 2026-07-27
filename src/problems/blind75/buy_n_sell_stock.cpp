#include <bits/stdc++.h>
#include <iostream>

void solve()
{
    int length;
    std::cin >> length;

    std::vector<int> prices(length);
    for (int i = 0; i < length; i++)
    {
        std::cin >> prices[i];
    }

    int max = 0;
    int buy = 0;

    for (int i = 1; i < prices.size(); i++)
    {
        if (prices[i] - prices[buy] > max)
        {
            max = prices[i] - prices[buy];
        }

        if (prices[i] < prices[buy])
        {
            buy = i;
        }
    }

    std::cout << max << std::endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t = 0;
    std::cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
