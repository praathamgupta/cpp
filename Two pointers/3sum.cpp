#include <bits/stdc++.h>
using namespace std;

#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define int long long

void solve()
{
    int n, t;
    cin >> n >> t;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int tar_sum;
    sort(arr, arr + n);
    int min_diff = abs((arr[n - 3] + arr[n - 2] + arr[n - 1]) - t);
    for (int j = 0; j < n; j++)
    {
        int i = 0;
        int k = n - 1;

        while (i < j && j < k)
        {

            if (arr[i] + arr[j] + arr[k] == t)
            {
                min_diff = 0;
                break;
            }
            else if (arr[i] + arr[j] + arr[k] < t)
            {
                min_diff = min(min_diff, t - (arr[i] + arr[j] + arr[k]));
                i++;
            }
            else
            {
                min_diff = min(min_diff, (arr[i] + arr[j] + arr[k]) - t);
                k--;
            }
        }
    }

    cout << min_diff << "\n";
}

signed main()
{
    IOS int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}