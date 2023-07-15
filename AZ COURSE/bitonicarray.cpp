#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
const lli mod = 1000000007;
int a[10000];
int n;
int check(int mid)
{
    if (mid == n - 1)
    {
        return 1;
    }
    else if (a[mid] > a[mid + 1])
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void increasingBs(int low, int high, int k)
{
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (a[mid] == k)
        {
            cout << mid + 1 << " ";
            return;
        }
        else if (a[mid] < k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
}

void decreasingBs(int low, int high, int k)
{
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (a[mid] == k)
        {
            cout << mid + 1 << " ";
            return;
        }
        else if (a[mid] < k)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
}
void solve()
{
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int low = 0;
    int high = n - 1;
    int ans = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (check(a[mid]) == 0)
        {
            low = mid + 1;
        }
        else
        {
            ans = mid;
            high = mid - 1;
        }
    }
    while (q--)
    {
        int k;
        cin >> k;
        increasingBs(0, ans - 1, k);
        decreasingBs(ans, n - 1, k);
        cout << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}