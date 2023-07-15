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
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        cin >> v1[i];
    }
    for (int i = (n - 1); i >= 0; i--)
    {
        if (s.empty())
        {
            v.push_back(-1);
        }
        else if (!s.empty() && s.top() > v1[i])
        {
            v.push_back(s.top());
        }
        else if (!s.empty() && s.top() <= v1[i])
        {
            while (s.size() > 0 && s.top() <= v1[i])
            {
                s.pop();
            }
            if (s.size() == 0)
            {
                v.push_back(-1);
            }
            else
            {
                v.push_back(s.top());
            }
        }
        s.push(v1[i]);
    }
    reverse(v.begin(), v.end());
    for (auto x1 : v)
    {
        cout << x1 << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}