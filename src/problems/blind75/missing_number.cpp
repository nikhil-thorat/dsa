#include <bits/stdc++.h>
#include <iostream>

void solve()
{
    /*
     * PROBLEM STATEMENT
     * Given an array nums containing n
     * integers in the range [0, n] without
     * any duplicates, return the single
     * number in the range that is missing
     * from the nums.
     *
     * EXAMPLE
     * Input : nums = {1, 2, 3}
     * Output : 0
     *
     * Input : nums = {0, 2}
     * Output : 1
     *
     * APPROACH
     * Using sum of natural numbers formula
     * calculate the sum from 0-n, then
     * calculate the sum of nums array.
     * And return the difference.
     */

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
