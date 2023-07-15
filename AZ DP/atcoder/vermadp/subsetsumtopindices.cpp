#include <bits/stdc++.h>
using namespace std;

bool subsetsum(vector<int> &a, int n, int sum, vector<vector<int>> &dp)
{
    dp[0][0] = 1;
    for (int i = 1; i < (n + 1); i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 1; i < (sum + 1); i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 1; i < (n + 1); i++)
    {
        for (int j = 1; j < (sum + 1); j++)
        {
            if (a[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = (dp[i - 1][j] || dp[i - 1][j - a[i - 1]]);
            }
        }
    }
    return dp[n][sum];
}

void printsubset(int n, vector<int> a, int sum, vector<vector<int>> dp)
{
    vector<int> indices;
    if (subsetsum(a, n, sum, dp))
    {
        int i = n;
        int j = sum;
        vector<int> subset;
        while (i > 0 && j > 0)
        {
            if (dp[i - 1][j])
            {
                i--;
            }
            else
            {
                subset.push_back(a[i - 1]);
                indices.push_back(i-1);
                j -= a[i - 1];
            }
        }
        for (int i = subset.size() - 1; i >= 0; i--)
        {
            cout << subset[i] << " ";
        }
        cout << endl;
         for (int i = indices.size() - 1; i >= 0; i--)
        {
            cout << indices[i] << " ";
        }
        
    }
    else
    {
        cout << "No subset with the given sum exists." << endl;
    }
}

void solve()
{
    int n, sum;
    cin >> n >> sum;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1));
    printsubset(n, a, sum, dp);
}

int main()
{
    solve();
    return 0;
}
