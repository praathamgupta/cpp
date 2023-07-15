#include <bits/stdc++.h>
using namespace std;
int findTargetSumWays(vector<int> &nums, int target)
{
    // similar to count of subset of min diff
    int n = nums.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + nums[i];
    }
    int x = (sum + target) / 2;
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
    for (int i = 0; i < (n + 1); i++)
    {
        dp[i][0] = 1;
    }
    for (int j = 1; j < (x + 1); j++)
    {
        dp[0][j] = 0;
    }
    for (int i = 1; i < (n + 1); i++)
    {
        for (int j = 1; j < (x + 1); j++)
        {
            if (nums[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
            }
        }
    }
    return dp[n][x];
}
void solve(){
    int n;
    cin>>n;
    vector<int>a(n);
    for (int i = 0; i < n; i++)
    {
       cin>>a[i];
    }
    int target;
    cin>>target;
    cout<<findTargetSumWays(a,target);
}
int main()
{
    solve();
}