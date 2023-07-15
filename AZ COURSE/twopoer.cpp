#include <bits/stdc++.h>
using namespace std;
void solve()
{
    long long ans = 0;
    int n;
    cin >> n;
    // vector<int>v(n);
    int v[n];
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++)
    {
        // for all sum in [2,2^2,2^3,2^4,...,2^31]
        long long x = 1; // store different power of 2
        for (int k = 1; k <= 31; k++)
        {
            x = x * 2;
            int search = x - v[i];
            ans = ans + (mp[search]);
        }
        mp[v[i]]++;
    }
    cout << ans << '\n';
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _t;
    cin >> _t;
    while (_t--)
    {
        solve();
    }
}