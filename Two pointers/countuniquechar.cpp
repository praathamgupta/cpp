// Count Unique Char in Substrings
// For the 1st test case: ac
// Substring and score = ("a",1), ("c",1) ("ac",2).
// Total score = 4

// For the 2nd test case:aac
// Substring and score = ("a",1), ("aa",0), ("aac",1), ("a",1), ("ac",2), ("c",1).
// Total score = 6

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ;
    ll testcases;
    cin >> testcases;
    while (testcases--)
    {
        ll n;
        cin >> n;
        string s;
        cin >> s;
        vector<ll> occurence[26];
        for (ll i = 0; i < 26; i++)
            occurence[i].push_back(-1);
        for (ll i = 0; i < n; i++)
            occurence[s[i] - 'a'].push_back(i);
        for (ll i = 0; i < 26; i++)
            occurence[i].push_back(n);
        ll ans = 0;
        for (ll i = 0; i < 26; i++)
        {
            for (ll j = 1; j < (int)occurence[i].size() - 1; j++)
            {
                ans += (occurence[i][j] - occurence[i][j - 1]) * (occurence[i][j + 1] - occurence[i][j]);
            }
        }
        cout << ans << "\n";
    }
}