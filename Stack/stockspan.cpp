#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
const lli mod = 1000000007;

void solve()
{
    int n;
    cin >> n;
    vector<int> v1(n);
    vector<int> v;
    stack<pair<int, int>> s;
    for (int i = 0; i < n; i++)
    {
        cin >> v1[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (s.empty())
        {
            v.push_back(-1);
        }
        else if (!s.empty() && ((s.top()).first) > v1[i])
        {
            v.push_back(s.top().second);
        }
        else if (!s.empty() && ((s.top()).first) <= v1[i])
        {
            while (!s.empty() && ((s.top()).first) <= v1[i])
            {
                s.pop();
            }
            if (s.empty())
            {
                v.push_back(-1);
            }
            else
            {
                v.push_back(s.top().second);
            }
        }
        s.push({v1[i], i});
    }
    for (int i = 0; i < n; i++)
    {
        cout<< i-v[i]<<" ";
    }
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}