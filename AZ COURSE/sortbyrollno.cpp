#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
const lli mod = 1000000007;
void solve()
{
    int n;
    cin >> n;
    vector<pair<int, string>> member;
    for (int i = 0; i < n; i++)
    {
        string s;
        int r;
        cin >> s >> r;
        member.push_back(make_pair(r, s));
    }
    sort(member.begin(), member.end());
    for (auto s1 : member)
    {
        cout << s1.second << " " << s1.first;
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