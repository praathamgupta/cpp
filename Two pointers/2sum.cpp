#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int i = 0, j = n - 1; // Set j to n-1 instead of 0
    int cnt = 0;
    while (i < j)
    {
        if (a[i] + a[j] == k)
        {
            cnt++;
            break; // Since we found a pair, we can break the loop
        }
        else if (a[i] + a[j] < k)
        {
            i++;
        }
        else if (a[i] + a[j] > k)
        {
            j--;
        }
    }
    if (cnt > 0)
    {
        cout << "Y\n";
    }
    else
    {
        cout << "N\n";
    }
}

signed main()
{
    int t;cin>>t;while(t--)
    solve();
   
}
