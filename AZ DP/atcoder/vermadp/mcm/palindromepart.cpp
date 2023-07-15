#include <bits/stdc++.h>
using namespace std;

int static dp[1001][1001];

bool ispalindrome(string s)
{
    string s1 = s;
    reverse(s1.begin(), s1.end());
    if (s == s1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool ispalindrome2(string s, int i, int j)
{
    if (i == j)
    {
        return true;
    }
    if (i > j)
    {
        return false;
    }
    while (i < j)
    {
        if (s[i] != s[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int solve1(string s, int i, int j)
{
    if (i >= j)
    {
        return 0;
    }
    /*if (ispalindrome2(s, i, j))
    {
        return 0;
    }*/
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int ans = INT_MAX; // Initialize ans to a large value

    for (int k = i; k < j; k++)
    {
        int left, right;

        if (dp[i][k] != -1)
        {
            left = dp[i][k];
        }
        else
        {
            left = solve1(s, i, k);
            dp[i][k] = left;
        }

        if (dp[k + 1][j] != -1)
        {
            right = dp[k + 1][j];
        }
        else
        {
            right = solve1(s, k + 1, j);
            dp[k + 1][j] = right;
        }

        int temp = 1 + left + right;
        ans = min(ans, temp);
    }

    return dp[i][j] = ans;
}

void solve()
{
    string s;
    cin >> s;
    memset(dp, -1, sizeof(dp));
    if (ispalindrome(s))
    {
        cout << "0\n";
    }
    else
    {
        cout << solve1(s, 1, s.size());
    }
}

int main()
{
    solve();
    return 0;
}
