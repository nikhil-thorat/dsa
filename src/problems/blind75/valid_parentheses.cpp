#include <bits/stdc++.h>

void solve()
{
    std::string str;
    std::cin >> str;

    std::unordered_map<char, char> map;
    map['('] = ')';
    map['['] = ']';
    map['{'] = '}';

    std::stack<char> st;

    for (char c : str)
    {
        if ((c == '{' || c == '[' || c == '{'))
        {
            st.push(map[c]);
        }
        else
        {
            if (st.empty() || st.top() != c)
            {
                break;
            }

            st.pop();
        }
    }

    if (st.empty())
    {
        std::cout << "Valid Parentheses" << std::endl;
    }
    else
    {
        std::cout << "Invalid Parentheses" << std::endl;
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
