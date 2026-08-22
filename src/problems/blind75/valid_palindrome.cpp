#include <bits/stdc++.h>

void solve()
{
    /*
     * PROBLEM STATEMENT
     * Given a string s, return true if it
     * is a palindrome, otherwise return false.
     * A palindrome is string that reads the same
     * forward and backward. It is also case-insensitive
     * and ignores all non-alphanumeric characters.
     * NOTE - Alphanumeric includes (A-Z,a-z,0-9)
     *
     * EXAMPLE
     * Input : s = "Was it a car or a cat I saw?"
     * Output : true
     *
     * APPROACH
     * Use two pointers start and end, where
     * start starts from 0 and end starts from
     * length - 1. Compare char at start and end
     * and increment/decrement if they are equal
     * if not return false.
     */

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
