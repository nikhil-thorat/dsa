#include <bits/stdc++.h>

void solve()
{
    /*
     * PROBLEM STATEMENT
     * Given an array of strings strs, group all
     * anagrams together into sublists. You may
     * return the output in any order.
     *
     * EXAMPLE
     * Input : strs = {"act", "pots", "tops", "cat", "stop", "hat"}
     * Output : {{"hat"}, {"act", "cat"}, {"stop", "pots", "tops"}}
     *
     * BRUTE FORCE APPROACH
     * Sort each string, and group them by equality of the
     * sorted version. Time complexity becomes O(N^2) since
     * we compare each string with another while also sorting
     * them. Space complexity becomes O(N).
     *
     * OPTIMIZED APPROACH
     * Use a map to group string based on the char count.
     * The key is an array of len 26 where we store the count
     * of chars and the value becomes the string itself. Time
     * complexity becomes O(N). Space complexity becomes O(N).
     */

    std::vector<std::string> strs = {"act", "pots", "tops", "cat", "stop", "hat"};

    std::map<std::array<int, 26>, std::vector<std::string>> map;

    for (std::string str : strs)
    {
        std::array<int, 26> count = {0};
        for (char c : str)
        {
            count[c - 'a'] += 1;
        }
        map[count].push_back(str);
    }

    std::vector<std::vector<std::string>> result;
    for (const auto &[key, value] : map)
    {
        result.push_back(value);
    }

    for (std::vector vec : result)
    {
        for (std::string str : vec)
        {
            std::cout << str << " ";
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
