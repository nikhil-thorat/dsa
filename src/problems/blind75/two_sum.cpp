#include <bits/stdc++.h>

void solve()
{
    /*
     * PROBLEM STATEMENT
     * Given an array of integers num and integer
     * target, return the indicies i and j such
     * that nums[i] + nums[j] == target and i != j
     * You may assume that every input has exactly
     * one pair of indicies i and j that satisfy
     * the condition.
     * Return the answer with smallest index first.
     *
     * EXAMPLE
     * Input : nums = {3, 4, 5, 6}, target = 7
     * Output : {0, 1}
     *
     * Input : nums = {4, 5, 6}, target = 10
     * Output : {0, 2}
     *
     * BRUTE FORCE APPROACH
     * Use nested loops to compare every number
     * with every other number that sums up to
     * the given target and return the indices.
     * Time complexity becomes O(N * N). Space
     * complexity becomes O(1).
     *
     * OPTIMIZED APPROACH
     * Use a map to store numbers that we have
     * encounter so far. If the complement(target - num)
     * of current number exits in a map, we get
     * the index of it and current number and
     * return it, else we add index as value of
     * key num. Time complexity becomes O(N).
     * Space complexity becomes O(N) because of
     * map.
     */

    int target;
    std::cin >> target;

    int length;
    std::cin >> length;

    std::vector<int> nums(length);
    for (int i = 0; i < length; i++)
    {
        std::cin >> nums[i];
    }

    std::unordered_map<int, int> map;

    for (int i = 0; i < nums.size(); i++)
    {
        int complement = target - nums[i];
        if (map.contains(complement))
        {
            std::cout << i << " " << map[complement] << std::endl;
            break;
        }

        map[nums[i]] = i;
    }
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
