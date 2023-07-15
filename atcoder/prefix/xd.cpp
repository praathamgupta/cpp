#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;
    cin >> n;

    vector<int> a;

    for (int i = 1; i < 1691; i++)
    {
        if (i % 2 == 0 || i % 3 == 0 || i % 5 == 0)
        {
            a.push_back(i);
        }
    }
    for(auto x: a){
        cout<<x<<" ";
    }
}
signed main()
{
    solve();
}