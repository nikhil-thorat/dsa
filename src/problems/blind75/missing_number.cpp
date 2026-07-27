#include <bits/stdc++.h>
#include <iostream>

void solve()
{
    int length;
    std::cin >> length;

    std::vector<int> nums(length);
    for (int i = 0; i < nums.size(); i++)
    {
        std::cin >> nums[i];
    }

    int sum = (length * (length + 1)) / 2;
    int nums_sum = 0;

    for (int num : nums)
    {
        nums_sum += num;
    }

    std::cout << sum - nums_sum;
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
