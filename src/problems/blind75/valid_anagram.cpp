#include <bits/stdc++.h>
#include <iostream>

void solve()
{
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
