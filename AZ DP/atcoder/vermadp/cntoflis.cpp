#include <bits/stdc++.h>
using namespace std;

int lis(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 1);
    int maxCount = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
                maxCount = max(maxCount, dp[i]);
            }
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (dp[i] == maxCount)
        {
            count++;
        }
    }

    return count;
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
    cout << lis(a) << "\n";
}

int main()
{
    solve();
    return 0;
}
