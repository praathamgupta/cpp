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

void printSubset(lli n, const vector<lli> &a, const vector<vector<bool>> &dp, lli sum)
{
    if (!dp[n][sum])
    {
        cout << "No subset found with the given sum." << endl;
        return;
    }

    vector<lli> subset;
    lli i = n;
    lli j = sum;
    while (i > 0 && j > 0)
    {
        if (dp[i - 1][j])
        {
            i--;
        }
        else
        {
            subset.push_back(a[i - 1]);
            j -= a[i - 1];
        }
    }

    cout << "Subset with the given sum: ";
    for (i = subset.size() - 1; i >= 0; i--)
    {
        cout << subset[i] << " ";
    }
    cout << endl;
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
    cout << "Subset with sum " << sum << " exists? " << (hasSubset ? "Yes" : "No") << endl;
    printSubset(n, a, dp, sum);
}

int main()
{
    solve();
    return 0;
}
