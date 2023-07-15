#include <bits/stdc++.h>
using namespace std;
int m, n;
float check(vector<int> c)
{
    // 1 2 3 4 5
    // 1 2 3 4
    if ((m + n) % 2 != 0)
    {
        int z = (m + n) / 2;
        return (c[z]);
    }
    else
    {
        float p = (c[(m + n - 1) / 2] + c[(m + n - 1) / 2 + 1])/2.0;
        return p;
    }
}
void solve()
{

    cin >> m >> n;
    vector<int> a(m);
    vector<int> c(m + n);
    vector<int> b(n);
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
        c[i] = a[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        c[i + n] = b[i];
    }
    sort(c.begin(), c.end());
    cout << check(c);
}
int main()
{
    solve();
    return 0;
}