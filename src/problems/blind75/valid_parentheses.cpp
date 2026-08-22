#include <bits/stdc++.h>

void solve()
{
    /*
     * PROBLEM STATEMENT
     * You are given a string s consisting
     * of the following characters '(', '[',
     * '{', ')', ']' and '}'.
     * The input string s is valid if and only
     * if.
     * - Every open bracket is closed by the same
     *   type of closed bracket.
     * - Open brackets are closed in the correct
     *   order.
     * - Every close bracket has a corresponding
     *   open bracket of the same types.
     *
     * EXAMPLE
     * Input : s = "[]"
     * Output : true
     *
     * Input : s = "[(])"
     * Output : false
     *
     * APPROACH
     * Use a stack to keep track of opening
     * brackets. Whenever we see a closing
     * bracket compare it with top of stack
     * and pop it if they are of same type
     * and continue, else string s is invalid.
     * Time complexity becomes O(N). Space
     * Complexity becomes O(N).
     */

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
