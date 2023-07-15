#include <bits/stdc++.h>
using namespace std;

#define int long long

int subseq(vector<int> &a, int i, vector<int> &dp)
{
    int n = a.size();
    if (i >= n)
    {
        return 0;
    }
    if (dp[i] != -1)
    {
        return dp[i];
    }
    if (a[i + 1] - a[i] == 0 && a[i + 2] - a[i + 1] == 1 && a[i + 3] - a[i + 2] == 0)
    {
        dp[i] = 1 + subseq(a, i + 4, dp);
    }
    else
    {
        return dp[i] = subseq(a, i + 1, dp);
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> dp(n + 1, -1);
    int x = subseq(a, 0, dp);
    cout << x << "\n";
}

signed main()
{
    solve();
    return 0;
}
