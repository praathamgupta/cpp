#include <bits/stdc++.h>
using namespace std;
using lli =long long int;
void solve()
{
    lli n;
    cin >> n;
    vector<lli> a(n);
    for (lli i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<lli> index;
    lli x = a[0];
    // initialize count to Zero
    lli cnt = 0, y = 0;
    // iterate for all elements
    for (lli i = 0; i < n; i++)
    {
        if (a[i] == (x + y))
        {
            cnt++;
            y++;
            index.push_back(i);
        }
    }
    cout<<cnt<<"\n";
    for (auto x : index)
    {
        cout << (x + 1) << " ";
    }
}

int main()
{
    solve();
    return 0;
}
