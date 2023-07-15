// Given a set of digits S, and an integer n, you have to find how many n-digit integers are there, which contain
// digits that belong to S and the difference between any two adjacent digits is not more than two.
// find the actual distance
//  suppose N = 9
//  1 2 4 5 6 7 8 9 //3 nai aana chahiya
//  x = 3 {1}
// ans = N-x
#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[12][12]; // digit prev_digit ka dp
int go(int n, vector<int> &s, int pos = 0, int prev = 0)
{
    int res = 0;
    if (dp[pos][prev] != -1)
    {
        return dp[pos][prev];
    }
    if (pos == n)
    {
        return 1;
    }
    for (int j = 0; j < s.size(); j++)
    {
        if (prev == 0 or ((abs(prev - s[j])) <= 2))
        {
            res+=go(n,s,pos+1,s[j]);
        }
    }
    return dp[pos][prev]=res;
}
void solve()
{
    int m, n;
    cin >> m >> n;
    vector<int> a(m);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    memset(dp, -1, sizeof(dp));
}
signed main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}