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

int solve1(string s, int i, int j, vector<string> &partitions)
{
    if (i >= j)
    {
        return 0;
    }
    if (ispalindrome2(s, i, j))
    {
        return 0;
    }
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
            left = solve1(s, i, k, partitions);
            dp[i][k] = left;
        }

        if (dp[k + 1][j] != -1)
        {
            right = dp[k + 1][j];
        }
        else
        {
            right = solve1(s, k + 1, j, partitions);
            dp[k + 1][j] = right;
        }

        int temp = 1 + left + right;
        ans = min(ans, temp);
    }

    // Store the result in dp[i][j] before returning
    dp[i][j] = ans;

    return ans;
}

void constructPartitions(string s, int i, int j, vector<string> &partitions)
{
    if (i >= j)
    {
        return;
    }
    if (ispalindrome2(s, i, j))
    {
        partitions.push_back(s.substr(i, j - i + 1));
        return;
    }

    int minPartitions = dp[i][j];

    for (int k = i; k < j; k++)
    {
        int left = dp[i][k];
        int right = dp[k + 1][j];

        if (minPartitions == 1 + left + right)
        {
            constructPartitions(s, i, k, partitions);
            constructPartitions(s, k + 1, j, partitions);
            return;
        }
    }
}

void solve()
{
    string s;
    cin >> s;
    memset(dp, -1, sizeof(dp)); // Initialize dp array with -1

    vector<string> partitions;
    int minPartitions = solve1(s, 0, s.size() - 1, partitions);

    cout << "Minimum number of partitions: " << minPartitions << endl;
    cout << "Partitioning string: ";
    constructPartitions(s, 0, s.size() - 1, partitions);
    for (const string &partition : partitions)
    {
        cout << partition << " ";
    }
}

int main()
{
    solve();
    return 0;
}
