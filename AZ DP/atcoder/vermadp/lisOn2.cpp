#include <bits/stdc++.h>
using namespace std;
#define int long long int
int lis(int n)
{
    int a[n], dp[n], cnt[n];
    dp[0] = 1;
    cnt[0] = 1;
    int maxLen = 1;
    for (int i = 1; i < n; i++)
    {
        dp[i] = 1;
        cnt[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (a[i] > a[j] && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
                cnt[i] = cnt[j];
            }
            else if (a[i] > a[j] && dp[i] == dp[j] + 1)
            {
                cnt[i] += cnt[j];
            }
        }
        maxLen = max(maxLen, dp[i]);
    }
    int numofLis = 0;
    for (int i = 0; i < n; i++)
    {
        if (maxLen == dp[i])
        {
            numofLis += cnt[i];
        }
    }
    return numofLis;
    // return *max_element(dp, dp + n);
}
void solve()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << lis(n)<<'\n';
}
signed main()
{
    int t;
    cin >> t;
    while (t--){
        solve();}
}