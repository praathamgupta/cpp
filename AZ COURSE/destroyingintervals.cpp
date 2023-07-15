#include <bits/stdc++.h>
using namespace std;
using lli = long long;
bool comp(pair<lli, lli> &a, pair<lli, lli> &b)
{
    return a.second < b.second; // sorting by end parameters
}
lli max(vector<pair<lli, lli>> &v)
{
    lli n = v.size();
    lli count = 0;
    lli prev_end = INT_MIN;
    for (lli i = 0; i < n; i++)
    {
        if (v[i].first > prev_end)
        {
            prev_end = v[i].second;
            count++;
        }
    }
    return count;
}
void solve()
{
    lli n;
    cin >> n;
    vector<pair<lli, lli>> v(n);
    for (lli i = 0; i < n; i++)
    {
        lli start, end;
        cin >> start >> end;
        v.push_back({start, end});
    }
    sort(v.begin(), v.end(), comp);
    lli ans = max(v);
    cout << ans << "\n";
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}