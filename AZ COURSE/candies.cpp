#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, m;
        int count = 0;
        cin >> n >> m;
        vector<int> a;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            a.push_back(x);
        }
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++)
        {
            m = m - a[i];
            if (m >= 0)
            {
                count++;
            }
            else
            {
                break;
            }
        }
        cout << count;
        cout << "\n";
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}