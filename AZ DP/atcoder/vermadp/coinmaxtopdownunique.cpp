#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
const lli mod = 1000000007;

bool subset(lli n, vector<lli> &a, vector<vector<bool>> &dp, lli sum)
{
    for (lli i = 0; i < n + 1; i++)
    {
        dp[i][0] = true;
    }
    for (lli i = 1; i < sum + 1; i++)
    {
        dp[0][i] = false;
    }
    for (lli i = 1; i < n + 1; i++)
    {
        for (lli j = 1; j < sum + 1; j++)
        {
            if (a[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else if (a[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - a[i - 1]];
            }
        }
    }
    return dp[n][sum];
}

void printSubsets(lli n, vector<lli> &a, vector<vector<bool>> &dp, lli sum, vector<lli> &current, lli i)
{
    if (sum == 0)
    {
        for (lli j = 0; j < current.size(); j++)
        {
            cout << current[j] << " ";
        }
        cout << endl;
        return;
    }
    if (sum < 0 || i <= 0)
    {
        return;
    }
    if (dp[i - 1][sum])
    {
        vector<lli> newSubset = current;
        printSubsets(n, a, dp, sum, newSubset, i - 1);
    }
    if (sum >= a[i - 1] && dp[i - 1][sum - a[i - 1]])
    {
        current.push_back(a[i - 1]);
        printSubsets(n, a, dp, sum - a[i - 1], current, i - 1);
        current.pop_back();
    }
}

void solve()
{
    lli n, sum;
    cin >> n >> sum;
    vector<lli> a(n);
    for (lli i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1));
    bool hasSubset = subset(n, a, dp, sum);
    if (hasSubset)
    {
        vector<lli> current;
        printSubsets(n, a, dp, sum, current, n);
    }
    else
    {
        cout << "No subset found with the given sum." << endl;
    }
}

int main()
{
    solve();
    return 0;
}
