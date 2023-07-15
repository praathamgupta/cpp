#include <bits/stdc++.h>
using namespace std;
int dp[3001][3001];
int lcs(string &a, string &b, int i, int j)
{
    if (i == 0 || j == 0)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    if (a[i - 1] == b[j - 1])
    {
        dp[i][j] = 1 + lcs(a, b, i - 1, j - 1);
    }
    else
    {
        dp[i][j] = max(lcs(a, b, i - 1, j), lcs(a, b, i, j - 1));
    }
    return dp[i][j];
}

void printset(string &a, string &b, int i, int j)
{
    if (i == 0 || j == 0)
        return;

    if (a[i - 1] == b[j - 1])
    {
        printset(a, b, i - 1, j - 1);
        cout << a[i - 1];
    }
    else
    {
        if (lcs(a, b, i - 1, j) > lcs(a, b, i, j - 1))
        {
            printset(a, b, i - 1, j);
        }
        else
        {
            printset(a, b, i, j - 1);
        }
    }
}

void solve()
{
    string s1, s2, s;
    cin >> s1 >> s2;
    int i = s1.size();
    int j = s2.size();
    memset(dp, -1, sizeof(dp));
    cout << lcs(s1, s2, i, j) << "\n";
    printset(s1, s2, i, j);
}
int main()
{
    solve();
    return 0;
}