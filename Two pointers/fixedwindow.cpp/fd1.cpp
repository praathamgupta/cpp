
#include <bits/stdc++.h>

using namespace std;

#define int long long
int fact(int i)
{
    if (i == 1 || i == 0)
        return 1;
    else
        return i * fact(i - 1);
}

void solve()
{
    string s;
    map<char, int> mp1;
    map<int, int, greater<int>> mp2;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
        mp1[s[i]]++;
    for (auto &v : mp1)
    {
        mp2[v.second]++;
    }
    int k;
    cin >> k;
    int ans = 1;
    int sum = 0;
    int n = s.length();
    for (auto v : mp2)
    {
        if ((k - v.second) >= 0)
        {
            k -= v.second;
            ans *= pow(v.first, v.second);
            sum += (v.first * v.second);
        }
        else
        {
            ans *= fact(n - sum) / (fact(k) * (fact(n - sum - k)));
            break;
        }
    }
    cout << ans;
}
signed main()
{

    int t;
    // cin >> t;
    t = 1;
    for (int it = 1; it <= t; it++)
    {
        solve();
    }
    return 0;
}