#include <bits/stdc++.h>
using namespace std;

int shortestUnSub(string S, string T)
{
    int m = S.size();
    int n = T.size();

    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 0; i <= n; i++)
    {
        dp[0][i] = 1e5;
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            char ch = S[i - 1];
            int k;
            for (k = j - 1; k >= 0; k--)
            {
                if (T[k] == ch)
                {
                    break;
                }
            }
            if (k == -1)
            {
                dp[i][j] = 1;
            }
            else
            {
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][k] + 1);
            }
        }
    }

    int ans = dp[m][n];
    if (ans >= 1e5)
    {
        ans = -1;
    }
    return ans;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        string s1, s2;
        cin >> s1 >> s2;
        cout << shortestUnSub(s1, s2) << "\n";
    }
}