#include <bits/stdc++.h>
using namespace std;
int n;
bool cubic(int x)
{
    for (int i = 2; i < n; i++)
    {
        if ((x % (i * i * i)) == 0)
        {
            return 1;
        }
    }
    return 0;
}
void solve()
{

    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int p;
        for (int j = i + 1; j < n; j++)
        {
            p = (a[i] * a[j]);
            cout << p << " ";
            if (cubic(p))
            {
                ans++;
            }
        }
    }
    cout << ans << "\n";
}
int main()
{
    solve();
}