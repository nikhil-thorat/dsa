#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>

void solve()
{
    /*
     * PROBLEM STATEMENT
     * Given an array of integers nums, return the
     * length of longest consecutive sequence of elements
     * that can be formed.
     * A consecutive sequence is a sequence of elements
     * in which each element is exactly 1 greater than
     * the previous element. The element do not have to
     * have be consecutive in the original array.
     *
     * EXAMPLE
     * Input : nums = {2,20,4,10,3,4,5}
     * Output : 4
     *
     * Input : nums = {0,3,2,5,4,6,1,1}
     * Output : 7
     *
     * BRUTE FORCE APPROACH
     * Sort the given array, and calculate the
     * longest consecutive sequence that is formed.
     * Time complexity becomes O(N Log N). Space
     * complexity is O(1).
     *
     * OPTIMAL APPROACH
     * Use a map with initiliazed values of nums
     * with 1, indicating they exists in map.
     * Then iterate over map, and check if
     * key +/- 1 exits in map. If map[key - 1]
     * exits then map[key] = map[key - 1] + 1.
     * If map[key + 1] exits then map[key + 1]
     * = map[key] + 1;
     * Finally find the maximum value from the
     * map.
     */

    std::vector<int> nums = {2, 20, 4, 10, 3, 4, 5};
    std::map<int, int> map;

    for (int n : nums)
    {
        map[n] = 1;
    }

    for (const auto &[key, value] : map)
    {
        if (map.contains(key - 1))
        {
            map[key] = map[key - 1] + 1;
        }
        if (map.contains(key + 1))
        {
            map[key + 1] = value + 1;
        }
    }

    int longest = 0;
    for (const auto &[key, value] : map)
    {
        longest = std::max(longest, value);
    }
    std::cout << longest << std::endl;
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
