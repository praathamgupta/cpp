#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
lli dp[3001][3001];
vector<lli> a;
lli n;
lli deque1(lli l, lli r)
{
    if (l == r)
    {
        return a[l];      // only 1 element
    }
    if (dp[l][r] == -1)
    {
        lli x = a[l] - deque1(l + 1, r);
        lli y = a[r] - deque1(l, r - 1);
        lli ans = max(x, y);
        dp[l][r] = ans;
    }
    return dp[l][r];
}
void solve()
{
    memset(dp, -1, sizeof(dp));
    cin >> n;
    a.resize(n);
    for (lli i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << deque1(0, n - 1) << "\n";
}

int main()
{
    solve();
    return 0;
}