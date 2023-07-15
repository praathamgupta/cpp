#include <bits/stdc++.h>
using namespace std;

int lcs(string &s1, string &s2, int n, int m, vector<vector<int>> &dp)
{
    if (n == 0 || m == 0)
    {
        return 0;
    }
    if (dp[n][m] != -1)
    {
        return dp[n][m];
    }
    if (s1[n - 1] == s2[m - 1])
    {
        dp[n][m] = 1 + lcs(s1, s2, n - 1, m - 1, dp);
    }
    else
    {
        dp[n][m] = 0;
    }
    return dp[n][m];
}

string printset(string &a, string &b, int i, int j, vector<vector<int>> &dp)
{
    if (i == 0 || j == 0)
    {
        return "";
    }
    if (a[i - 1] == b[j - 1])
    {
        return printset(a, b, i - 1, j - 1, dp) + a[i - 1];
    }
    else
    {
        if (lcs(a, b, i - 1, j, dp) > lcs(a, b, i, j - 1, dp))
        {
            return printset(a, b, i - 1, j, dp);
        }
        else
        {
            return printset(a, b, i, j - 1, dp);
        }
    }
}


void solve()
{
    string s1, s2;
    cin >> s1;
    s2 = s1;
    reverse(s2.begin(), s2.end());
    int i = s1.size();
    int j = s2.size();
    vector<vector<int>> dp(i + 1, vector<int>(j + 1, -1));
    cout << printset(s1, s2, i, j, dp);
}

int main()
{
    solve();
    return 0;
}
