#include <bits/stdc++.h>
using namespace std;
int lcs(string &s1, string &s2, int i, int j, vector<vector<int>> &dp)
{
    if (i == 0 || j == 0)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    if (s1[i - 1] == s2[j - 1])
    {
        return dp[i][j] = 1 + lcs(s1, s2, i - 1, j - 1, dp);
    }
    else
    {
        return dp[i][j] = max(lcs(s1, s2, i, j - 1, dp), lcs(s1, s2, i - 1, j, dp));
    }
    return dp[i][j];
}
void printset(string &s1, string &s2, int i, int j, vector<vector<int>> &dp)
{
    if (i == 0 || j == 0)
    {
        return;
    }
    if (s1[i - 1] == s2[j - 1])
    {
        printset(s1, s2, i - 1, j - 1, dp);
        cout << s1[i - 1];
    }
    else
    {
        if (lcs(s1, s2, i - 1, j, dp) > lcs(s1, s2, i, j-1, dp))
        {
            printset(s1, s2, i - 1, j, dp);
        }
        else
        {
            printset(s1, s2, i, j - 1, dp);
        }
    }
}
void solve()
{
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
   // cout << lcs(s1, s2, n, m, dp) << "\n";
    printset(s1, s2, n, m, dp);
}
int main()
{
    solve();
}