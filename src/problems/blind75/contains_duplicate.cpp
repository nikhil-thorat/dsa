#include <bits/stdc++.h>
#include <iostream>

void solve()
{
    /*
     * PROBLEM STATEMENT
     * Given an integer array nums, return true
     * if any value appears more than once in the
     * array, otherwise return false.
     *
     * EXAMPLES
     * Input : nums = [1, 2, 3, 3]
     * Output : true
     *
     * Input : nums = [1, 2, 3, 4]
     * Output : false
     *
     * BRUTE FORCE APPROACH
     * Use nested loops for comparing every
     * number with every other number, if
     * we find duplicates then return true
     * else return false. Time complexity
     * becomes O(N * N), Space complexity
     * is O(1).
     *
     * OPTIMIZED APPROACH
     * Use a set to keep a track of seen
     * elements and iterate over nums and
     * check if it exists in the set, if yes
     * return true else add that element to
     * set and continue until all elements
     * are inserted or duplicate is found.
     * If no duplicates are found return
     * false. Time complexity becomes
     * O(N), Space complexity is O(N) for
     * additional set.
     */

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
