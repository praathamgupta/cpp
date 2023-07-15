#include <bits/stdc++.h>
using namespace std;
#define int long long

void generate(int x)
{
    for (int i = 1; i < 1001; i++)
    {
        int num = i; // Make a copy of i
        int sum = 0;
        while (num != 0)
        {
            sum = sum + num % 10;
            num = num / 10;
        }
        if (sum == x)
        {
            cout << i << " ";
        }
    }
    cout<<"\n";
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // generate(2);
    for (int i = 0; i < n; i++)
    {
        generate(a[i]);
    }
}

signed main()
{
    solve();
    return 0;
}
