#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
const lli mod = 1000000007;
lli n, k;
map<lli, lli> mp;
vector<lli> cur_perm;
vector<vector<lli>> all_sol;

void rec(lli level)
{
    if (level == n)
    {
        all_sol.push_back(cur_perm);
        return;
    }
    for (auto &v : mp)
    {
        if (v.second != 0)
        {
            v.second--;
            cur_perm.push_back(v.first);
            rec(level + 1);
            cur_perm.pop_back();
            v.second++;
        }
    }
}
int check(){
    for (int i = 0; i <n; i++)
    {
      for (int j = i; i < n; j++)
      {
          
      }
      
    }
    
}
void solve()
{
    cin >> n >> k;
    for (lli i = 1; i <= n; i++)
    {
        mp[i] = 1;
    }
    rec(0);
    for (const auto &v : all_sol)
    {
        for (auto val : v)
        {
            //cout << val << " ";
        }
        //cout << "\n";
    }
}

int main()
{
    // lli t;cin>>t;while(t--)
    solve();
    return 0;
}
