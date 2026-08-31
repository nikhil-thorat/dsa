#include <bits/stdc++.h>
#include <iostream>

void solve()
{
    /*
     * PROBLEM STATEMENT
     * Given an integer array nums, return all triplets
     * [nums[i], nums[j], nums[k]] where nums[i] + nums[j]
     * + nums[k] == 0, and the indices i, j and k are all
     * distinct.
     * The output should not contain any duplicate triplets.
     * You may return the output and the triplet in any
     * order.
     *
     * EXAMPLE
     * Input : nums = {-1,0,1,2,-1,4}
     * Output : {{-1,-1,2},{-1,0,1}}
     * Distinct triplets are {-1,0,1} and {-1,-1,2}
     *
     * BRUTE FORCE APPROACH
     * Using 3 nested loops for calculating all the triplets
     * that sum up to 0. Time complexity becomes O(N ^ 3).
     * Space complexity is O(1).
     *
     * OPTIMIZED APPROACH
     * First sort the array, which requires O(N Log N) Time
     * complexity. Then iterate over nums array, for every
     * element check complement elements in array using
     * 2 pointers that sums up to 0. Adjust the pointers
     * based on the summation. Once we find triplet add it
     * to result array and update any one of 2 pointers
     * so that we can avoid duplicates in the triplets.
     * Time complexity becomes O(N ^ 2). Space complexity
     * becomes O(1).
     */

    int length;
    std::cin >> length;

    std::vector<int> nums(length);
    for (int i = 0; i < length; i++)
    {
        std::cin >> nums[i];
    }

    std::sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> result;

    for (int i = 0; i < nums.size(); i++)
    {
        if (i > 0 && nums[i - 1] == nums[i])
        {
            continue;
        }

        int j = i + 1;
        int k = nums.size() - 1;

        while (j < k)
        {
            int three_sum = nums[i] + nums[j] + nums[k];

            if (three_sum > 0)
            {
                k--;
            }
            else if (three_sum < 0)
            {
                j++;
            }
            else
            {
                result.push_back({nums[i], nums[j], nums[k]});
                j += 1;
                while (nums[j] == nums[j - 1] && j < k)
                {
                    j++;
                }
            }
        }
    }

    for (std::vector vec : result)
    {
        for (int i = 0; i < vec.size(); i++)
        {
            std::cout << vec[i] << " ";
        }
        std::cout << std::endl;
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
