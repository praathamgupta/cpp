#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
const lli mod = 1000000007;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> v2;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[v[i]]++;
    }
    for (auto x : mp)
    {
        v2.push_back(x.second);
    }
    sort(v2.begin(), v2.end());
    int p = v2[v2.size() - 1];
    int result = n - max((2 * p - n), 0);
    cout << result << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int t;cin>>t;while(t--)
    solve();
}