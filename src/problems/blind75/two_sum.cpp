#include <bits/stdc++.h>

void solve()
{
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
