#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
const lli mod = 1000000007;

void solve()
{
    int n, x;
    int count = 0;
    cin >> n >> x;
    vector<int> a(n);
    vector<int> p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i > 0)
        {
            p[i] += p[i - 1];
        }
    }
    int sum = 0;
    map<int, int> mp;
    mp[0]++;
    for (int i = 0; i < n; i++)
    {
        sum += mp[a[i] - x];
        mp[p[i]++];
    }
    cout << sum;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
}