#include <bits/stdc++.h>

void solve()
{
    /*
     * PROBLEM STATEMENT
     * You are given an unsigned integer n.
     * Return the number of 1 bits in its
     * binary representation. You may assume
     * n is a non-negative integer which fits
     * 32 bits.
     *
     * EXAMPLE
     * Input : n = 00000000000000000000000000010111
     * Output : 4
     *
     * APPROACH
     * For every bit in 32 bit integer,
     * where only ith bit is active, mask
     * it with n to  see if the ith bit
     * is active.
     */

    uint32_t N = 00000000000000000000000000010111;

    int bit_count = 0;

    for (int i = 0; i < 32; i++)
    {
        int mask = (1 << i);
        if (mask & N)
        {
            bit_count++;
        };
    }

    std::cout << bit_count << std::endl;
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
