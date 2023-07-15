#include <bits/stdc++.h>
using namespace std;
#define int long long

int solve(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &dp)
{
    int n = mat.size();
    int m = mat[0].size();

    if (i >= n || j >= m)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int right = solve(i, j + 1, mat, dp);
    int down = solve(i + 1, j, mat, dp);
    int diag = solve(i + 1, j + 1, mat, dp);

    int ans = 0;
    if (mat[i][j] == 1)
    {
        ans = 1 + min(right, min(down, diag));
    }

    dp[i][j] = ans;
    return dp[i][j];
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, -1));
        vector<vector<int>> dp(n, vector<int>(m, -1));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }

        int maxSquareArea = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int side = solve(i, j, mat, dp);
                maxSquareArea = max(maxSquareArea, side * side);
            }
        }

        cout << maxSquareArea << "\n";
    }
    return 0;
}
