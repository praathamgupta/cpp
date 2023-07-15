//    2 1 1 5 6 2 3 1
// lis 1 1 1 2 3 2 3 1
// lds 2 1 1 3 3 2 2 1

// lis + lds -1
//     2 1 1 4 5 3 4 1
#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;
int dp[10010][2];

vector<int> prefixlis(vector<int> &arr)
{
    vector<int> temp;
    vector<int> ans;

    for (auto x : arr)
    {
        if (temp.empty() || x > temp.back())
        {
            temp.push_back(x);
        }
        else
        {
            auto it = lower_bound(temp.begin(), temp.end(), x);
            *it = x;
        }

        ans.push_back(temp.size());
    }
    return ans;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    auto LIS = prefixlis(arr);
    reverse(arr.begin(), arr.end());
    auto LDS = prefixlis(arr);
    reverse(LDS.begin(), LDS.end());
    reverse(arr.begin(), arr.end());

    int ans = -1;
    for (int i = 0; i < n; i++)
    {
        if ((LDS[i] + LIS[i] - 1) > ans && LDS[i] >= 2 && LIS[i] >= 2)
        {
            ans = LDS[i] + LIS[i] - 1; // By adding LDS[i] and LIS[i] and subtracting 1, we get the length of the bitonic subsequence
            // that includes the element at index i.
            //  The if condition checks whether this length is greater than the current maximum ans
        }
    }

    if (ans >= 3)
    {
        cout << (n - ans) << '\n';
    }
    else
    {
        cout << -1 << '\n';
    }
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}