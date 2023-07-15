// longestrepeating subsequence
// 01234567
// aabebcdd   we have to print abd, lcs= aabebcdd => aabbdd => only once => abd eliminate e and c
// aabebcdd   pair such that i!=j so that single occ elements cancel offs
#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int lcsmod(string s1, string s2, int n, int m)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s1[j - 1] && i != j)
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    return dp[n][m];
}
void solve()
{
    string s1, s2;
    cin >> s1;
    int n = s1.size();
    s2 = s1;
    int m = s2.size();

    memset(dp, -1, sizeof(dp));
    cout << lcsmod(s1, s2, n, m);
}
int main()
{
    solve();
}