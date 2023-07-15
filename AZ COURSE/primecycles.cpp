#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
const lli mod = 1000000007;
int n;
map<int, int> mp;
vector<int> cur_perm;
vector<vector<int>> all_sol;
vector<int> is_prime;

bool isPrime(int n)
{
    is_prime.assign(2 * n + 1, true);

    for (int i = 2; i <= 2 * n; i++)
    {
        if (is_prime[i])
        {
            for (lli j = 2 * i; j <= 2 * n; j += i)
            {
                is_prime[j] = false;
            }
        }
    }
    return false;
}

void rec(int level)
{
    if (level == n)
    {
        all_sol.push_back(cur_perm);
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
    cin >> n;
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
    for (auto perm : all_sol)
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (isPrime(perm[i] + perm[i + 1]))
            {
                cout << perm[i] << " ";
            }
        }
        cout << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int t;cin>>t;while(t--)
    solve();
}
