#include <bits/stdc++.h>
#include <iostream>

void solve()
{
    int length;
    std::cin >> length;

    std::vector<int> nums(length);
    for (int i = 0; i < length; i++)
    {
        std::cin >> nums[i];
    }

    std::unordered_set<int> seen;

    for (int num : nums)
    {
        if (seen.contains(num))
        {
            std::cout << "true" << std::endl;
            return;
        }

        seen.insert(num);
    }

    std::cout << "false" << std::endl;
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
