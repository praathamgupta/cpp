#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    long long int count = 0;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    for (int i = 1; i < n; i++)
    {
        if (v[i] < v[i - 1])
        {
            int change = v[i - 1] - v[i];
            count += change;
            v[i] += change;
        }
    }
    cout << count;
    cout << "\n";
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}