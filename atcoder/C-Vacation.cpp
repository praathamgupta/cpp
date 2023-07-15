#include <bits/stdc++.h>
using namespace std;

long long dp[100010][4];
long long a[100010], b[100010], c[100010];
int n;

long long solve(int level, int last)
{
    if (level == n + 1)
    {
        return 0;
    }
    if (dp[level][last] == -1)
    {
        long long ans = 0;
        if (last != 1)
        {
            ans = max(ans, a[level] + solve(level + 1, 1));
        }
        if (last != 2)
        {
            ans = max(ans, b[level] + solve(level + 1, 2));
        }
        if (last != 3)
        {
            ans = max(ans, c[level] + solve(level + 1, 3));
        }
        dp[level][last] = ans;
    }
    return dp[level][last];
}

int main()
{
    cin >> n;
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i] >> c[i];
    }
    cout << solve(1, 0);
    return 0;
}