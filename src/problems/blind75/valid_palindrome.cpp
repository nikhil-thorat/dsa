#include <bits/stdc++.h>

void solve()
{
    std::string str = "No lemon, no melon";

    int start = 0;
    int end = str.size() - 1;

    bool valid = true;

    while (start <= end)
    {
        if (!std::isalnum(static_cast<unsigned char>(str[start])))
        {
            start++;
            continue;
            ;
        }

        if (!std::isalnum(static_cast<unsigned char>(str[end])))
        {
            end--;
            continue;
        }

        if (std::tolower(str[start]) != std::tolower(str[end]))
        {
            valid = false;
            break;
        }

        start++;
        end--;
    }

    if (valid)
    {
        std::cout << "Valid Palindrome" << std::endl;
    }
    else
    {
        std::cout << "Invalid Palindrom" << std::endl;
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
