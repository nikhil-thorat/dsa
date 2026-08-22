#include <bits/stdc++.h>
#include <iostream>

void solve()
{
    /*
     * PROBLEM STATEMENT
     * Given an m x n matrix of integers
     * matrix. Return a list of all elements
     * within the matrix in spiral order.
     *
     * EXAMPLE
     * Input : matrix = {{1,2}, {3,4}}
     * Output : {1,2,3,4}
     *
     * Input : matrix = {{1,2,3}, {4,5,6}, {7,8,9}}
     * Output : {1,2,3,4,5,6,7,8,9}
     *
     * APPROACH
     * Use top, left, bottom, right guides to
     * dictate what we iterate over and print
     * it in order left -> right, top -> bottom,
     * right -> left and bottom -> top. After
     * each iteration update these to shrink
     * the iterating area.
     */

    int n;
    int m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> matrix(n, std::vector<int>(m));
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < m; c++)
        {
            std::cin >> matrix[r][c];
        }
    }

    std::vector<int> result;

    int top = 0;
    int left = 0;
    int bottom = matrix.size() - 1;
    int right = matrix[0].size() - 1;

    while (top <= bottom && left <= right)
    {
        for (int i = left; i <= right; i++)
        {
            result.push_back(matrix[top][i]);
        }
        top++;

        for (int i = top; i <= bottom; i++)
        {
            result.push_back(matrix[i][right]);
        }
        right--;

        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                result.push_back(matrix[bottom][i]);
            }
            bottom--;
        }

        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                result.push_back(matrix[i][left]);
            }
            left++;
        }
    }

    for (int num : result)
    {
        std::cout << num << " ";
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
