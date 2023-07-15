#include <bits/stdc++.h>
using namespace std;
int dp[100][100][100];
int lcs(string s1, string s2, string s3, int n, int m, int k)
{
    if (n == 0 || m == 0 || k == 0)
    {
        return 0;
    }
    if (dp[n][m][k] != -1)
    {
        return dp[n][m][k];
    }
    if (s1[n - 1] == s2[m - 1] && s2[m - 1] == s3[k - 1])
    {
        return dp[n][m][k] = 1 + lcs(s1, s2, s3, n - 1, m - 1, k - 1);
    }
    else 
    {
        return dp[n][m][k] = max(max(lcs(s1, s2, s3, n - 1, m, k), lcs(s1, s2, s3, n, m - 1, k)), lcs(s1, s2, s3, n, m, k - 1));
    }
}
void solve()
{
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    int n = s1.size();
    int m = s2.size();
    int k = s3.size();
   memset(dp,-1,sizeof(dp));
    cout << lcs(s1, s2, s3, n, m, k)<<"\n";
}
int main()
{
    int t;cin>>t;
    while(t--)
    solve();
}