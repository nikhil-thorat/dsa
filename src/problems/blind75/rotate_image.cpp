#include <bits/stdc++.h>
#include <iostream>

void solve()
{
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
    for (int r = 0; r < matrix.size(); r++)
    {
        for (int c = 0; c < matrix.size(); c++)
        {
            std::cin >> matrix[r][c];
        }
    }

    std::reverse(matrix.begin(), matrix.end());

    for (int r = 0; r < matrix.size(); r++)
    {
        for (int c = r + 1; c < matrix.size(); c++)
        {
            std::swap(matrix[r][c], matrix[c][r]);
        }
    }

    for (int r = 0; r < matrix.size(); r++)
    {
        for (int c = 0; c < matrix.size(); c++)
        {
            std::cout << matrix[r][c] << " ";
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
