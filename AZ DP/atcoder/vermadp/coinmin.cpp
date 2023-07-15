#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int maxcoin(vector<int> a, int n, int sum, vector<int> &subarray)
{
    if (sum == 0)
    {
        return 1;
    }
    if (n == 0)
    {
        return 0;
    }
    if (dp[n][sum] != -1)
    {
        return dp[n][sum];
    }
    if (a[n - 1] > sum)
    {
        return dp[n][sum] = maxcoin(a, n - 1, sum, subarray);
    }
    else
    {
        if (maxcoin(a, n - 1, sum, subarray))
        {
            return dp[n][sum] = 1;
        }
        else if (maxcoin(a, n - 1, sum - a[n - 1], subarray))
        {
            subarray.push_back(a[n - 1]);
            return dp[n][sum] = 1;
        }
        else
        {
            return dp[n][sum] = 0;
        }
    }
    
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int sum;
    cin >> sum;
    memset(dp, -1, sizeof(dp));
    vector<int> subarray;
    if (maxcoin(a, n, sum, subarray))
    {
        cout << "Count: " << subarray.size() << "\n";
       
    }
    else
    {
        cout << "No subarray found.";
    }
}

int main()
{
    solve();
    return 0;
}
