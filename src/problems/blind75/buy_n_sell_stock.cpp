#include <bits/stdc++.h>
#include <iostream>

void solve()
{
    /*
     * PROBLEM STATEMENT
     * You are given an integer array prices, where
     * prices[i] is the price of stock on ith day.
     * You may choose a single day to buy one stock,
     * and choose different day in future to sell it.
     * Return the maximum profit you can achieve. You
     * may choose to not make any transactions, in which
     * case profit would be 0.
     *
     * EXAMPLE
     * Input : prices = {10, 1, 5, 6, 7, 1}
     * Output : 6
     *
     * BRUTE FORCES APPROACH
     * Compute profit of every transaction that can be made
     * based on the conditions given and get the maximum
     * profit from that. Time complexity becomes O(N^2).
     * Space complexity becomes O(1).
     *
     * OPTIMIZED APPROACH
     * Use sliding window approach, keep track of minimum
     * price and iterate over array to find the maximum
     * profit that can be made. Time complexity becomes
     * O(N). Space complexity becomes O(1).
     */

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
