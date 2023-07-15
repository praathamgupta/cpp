#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n, sum, k;
    cin >> n >> k >> sum;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int start = 0, end = 0;
    int cnt = 0;
    int maxSum = INT_MIN;
    int currSum = 0;

    while (end < n)
    {
        if (a[end] % 2 != 0)
        {
            cnt++;
        }

        while (cnt > k || currSum > sum)
        {
            if (a[start] % 2 != 0)
            {
                cnt--;
            }
            currSum -= a[start];
            start++;
        }

        if (cnt <= k && currSum <= sum)
        {
            maxSum = max(maxSum, currSum);
        }

        currSum += a[end];
        end++;
    }

    if (maxSum == INT_MIN)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        cout << maxSum << endl;
    }
}

signed main()
{
    solve();
    return 0;
}
