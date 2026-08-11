#include <bits/stdc++.h>

void solve()
{
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
