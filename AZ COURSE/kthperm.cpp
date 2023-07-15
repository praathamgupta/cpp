#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>> all_sol;
vector<int> cur_perm;
int n, k;
map<int, int> mp;

void rec(int level)
{
    if (level == n)
    {
        all_sol.push_back(cur_perm);
        return;
    }
    for (auto v : mp)
    {
        if (v.second != 0)
        {
            mp[v.first]--;
            cur_perm.push_back(v.first);
            rec(level + 1);
            cur_perm.pop_back();
            mp[v.first]++;
        }
    }
}

void solve()
{
    cin >> n >> k;
    vector<int> a;
    for (int i = 1; i <= n; i++)
    {
        a.push_back(i);
    }
    for (int i = 0; i < n; i++)
    {
        mp[a[i]]++;
    }
    rec(0);
    for (int i = 0; i < all_sol[k - 1].size(); i++)
    {
        cout << all_sol[k - 1][i] << " ";
    }
}

signed main()
{
    solve();
    return 0;
}
