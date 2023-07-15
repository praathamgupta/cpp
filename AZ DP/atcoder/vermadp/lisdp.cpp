#include <bits/stdc++.h>
using namespace std;
int n;
int lis(vector<int> &a)
{
    set<int> s;

    for (int i = 0; i < n; i++)
    {
        s.insert(a[i]);
        auto it = s.upper_bound(a[i]);
        if (it != s.end())
        {
            s.erase(it);
        }
    }
    return s.size();
}
int lds(vector<int> &a)
{
    multiset<int> ms;

    for (int i = 0; i < n; i++)
    {
        ms.insert(a[i]);
        auto it = ms.upper_bound(a[i]);
        if (it != ms.end())
        {
            ms.erase(it);
        }
    }
    return ms.size();
}
void solve()
{

    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout<<lis(a)<<" "<<lds(a);
}
int main()
{
    solve();
    return 0;
}