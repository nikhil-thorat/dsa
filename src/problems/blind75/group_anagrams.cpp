#include <bits/stdc++.h>

void solve()
{
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
