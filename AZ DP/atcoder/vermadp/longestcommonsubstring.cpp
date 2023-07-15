#include <iostream>
#include <cstring>

using namespace std;

const int MAX_N = 1001;
int dp[MAX_N][MAX_N];

void printLongestCommonSubstring(string s1, string s2, int n, int m, int maxLen)
{
    int endIndex = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1] && dp[i][j] == maxLen)
            {
                endIndex = i - 1;
                break;
            }
        }
    }

    string longestCommonSubstr = s1.substr(endIndex - maxLen + 1, maxLen);
    cout << longestCommonSubstr;
}

int longestCommonSubstring(string s1, string s2, int n, int m)
{
    int maxLen = 0;

    // Initialize the first row and column of dp[][] to 0
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                maxLen = max(maxLen, dp[i][j]);
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }

    return maxLen;
}

void solve()
{
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size();
    int m = s2.size();

    int maxLen = longestCommonSubstring(s1, s2, n, m);
    printLongestCommonSubstring(s1, s2, n, m, maxLen);
}

int main()
{
    solve();
    return 0;
}
