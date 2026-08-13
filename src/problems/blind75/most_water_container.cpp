#include <bits/stdc++.h>
#include <iostream>
#include <pthread.h>

void solve()
{
    /*
     * PROBLEM STATEMENT
     * You are given an integer array heights
     * where heights[i] represents the height
     * of the ith bar.
     * You may choose any two bars to form a
     * container. Return the maximum amount of
     * water a container can store.
     *
     * EXAMPLE
     * Input : height = [1,7,2,5,4,7,3,6]
     * Output : 36
     *
     * Input : height = [2, 2, 2]
     * Output : 4
     *
     * BRUTE FORCE APPROACH
     * Calculate all the possible containers
     * and their areas and return the container
     * with maximum water. Time complexity
     * becomes O(N * N). Space complexity
     * is O(1).
     *
     * OPTIMIZED APPROACH
     * Use left and right pointers to form
     * a container, calculate area and compare
     * it with max area. Update the max area
     * if current area is greater than max area.
     * Move the smallest pointer to form next
     * container. Time complexity becomes O(N).
     * Space complexity becomes O(1).
     */

    int length;
    std::cin >> length;

    std::vector<int> heights(length);
    for (int i = 0; i < length; i++)
    {
        std::cin >> heights[i];
    }

    int left = 0;
    int right = heights.size() - 1;

    int max_area = 0;

    while (left < right)
    {
        int height = std::min(heights[left], heights[right]);
        int width = right - left;

        int area = width * height;
        max_area = std::max(max_area, area);

        if (heights[left] < heights[right])
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    std::cout << max_area << std::endl;
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
