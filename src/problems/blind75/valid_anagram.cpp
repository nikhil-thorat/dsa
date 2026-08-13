#include <bits/stdc++.h>
#include <iostream>

void solve()
{
    /*
     * PROBLEM STATEMENT
     * Given two strings s and t, return true
     * if two strings are anagram of each other,
     * otherwise return false.
     * An anagram is a string that contains exact
     * same characters as another string, but the
     * order of characters can be different.
     *
     * EXAMPLE
     * Input : s = "racecar", t = "carrace"
     * Output : true
     *
     * Input : s = "jim", t = "jar"
     * Output : false
     *
     * BRUTE FORCE APPROACH
     * Sort both the strings and compare if they
     * are equal, if yes return true else return
     * false. Time complexity becomes O(N Log N)
     * for sorting the strings. Space complexity
     * is O(1).
     *
     * OPTIMIZED APPROACH
     * Use a maps for storing characther count in
     * each string. Compare if two maps are equal
     * if yes return true, else return false.
     * Time complexity becomes O(N + M) where
     * N is the size of s and M is the size of t.
     * Space complexity is O(N + M) for the two
     * maps.
     */

    std::string s;
    std::string t;

    std::cin >> s >> t;

    if (s.size() != t.size())
    {
        std::cout << "Invalid Anagram" << std::endl;
        return;
    }

    std::unordered_map<char, int> map_s;
    std::unordered_map<char, int> map_t;

    for (char c : s)
    {
        map_s[c]++;
    }

    for (char c : t)
    {
        map_t[c]++;
    }

    if (map_s == map_t)
    {
        std::cout << "Valid Anagram" << std::endl;
    }
    else
    {
        std::cout << "Invalid Anagram" << std::endl;
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
