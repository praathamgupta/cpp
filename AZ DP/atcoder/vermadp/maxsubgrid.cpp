#include <bits/stdc++.h>
using namespace std;
#define int long long

int bestSum(vector<int> v)
{
    int curr = 0, max = v[0];
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        curr += v[i];
        if (max < curr)
            max = curr;
        if (curr < 0)
            curr = 0;
    }
    return max;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    int grid[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    int ans = -1e18;
    if (m < n)
    {
        for (int c1 = 0; c1 < m; c1++)
        {
            vector<int> rowSum(n, 0);
            for (int c2 = c1; c2 < m; c2++)
            {
                for (int r = 0; r < n; r++)
                {
                    rowSum[r] += grid[r][c2];
                }
                ans = max(ans, bestSum(rowSum));
            }
        }
    }
    else
    {
        for (int r1 = 0; r1 < n; r1++)
        {
            vector<int> colSum(m, 0);
            for (int r2 = r1; r2 < n; r2++)
            {
                for (int c = 0; c < m; c++)
                {
                    colSum[c] += grid[r2][c];
                }
                ans = max(ans, bestSum(colSum));
            }
        }
    }
    cout << ans << endl;
}

signed main()
{

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}