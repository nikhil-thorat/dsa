#include <bits/stdc++.h>

void solve()
{
    /*
     * PROBLEM STATEMENT
     * Design an algorithm to encode and deode a list
     * of strings to string. The encoded string is then
     * sent over the network and is decoded back to the
     * original list of strings.
     *
     * EXAMPLE
     * Input : strs = {"Hello", "World"}
     * Output : {"Hello", "World"}
     *
     * APPROACH
     * For encoding, we store the length of each word
     * with a delimiter like '#'. Using this we will
     * get "5#Hello5#World" as output of our encoding
     * function.
     * For decoding, we first get the length of each
     * word from our encoded string, and append the
     * substring of encoded string to the strs vector.
     * Time complexity is O(N) since we iterate over
     * string once. Space complexity is O(N) for storing
     * results.
     */

    std::vector<std::string> strs = {"My", "name", "is", "Nikhil"};

    std::string result;
    for (std::string str : strs)
    {
        result += std::to_string(str.size()) + "#" + str;
    }

    std::cout << result << std::endl;

    strs = {};
    int i = 0;

    while (i < result.size())
    {
        int len = 0;
        while (result[i] != '#')
        {
            len = len * 10 + (result[i] - '0');
            i++;
        }

        i++;
        strs.push_back(result.substr(i, len));
        i += len;
    }

    for (std::string str : strs)
    {
        std::cout << str << " ";
    }
    std::cout << std::endl;
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
