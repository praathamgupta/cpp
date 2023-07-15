#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        float count = 0;
        float d, i, x, n;
        cin >> n;
        vector<float> a;
        vector<float> b;
        vector<float> c;

        vector<float> e;

        for (i = 0; i < n; i++)
        {

            cin >> x;
            a.push_back(x);
        }
        for (i = 0; i < n; i++)
        {

            cin >> x;
            b.push_back(x);
        }
        for (i = 0; i < n; i++)
        {
            if (a[i] == 0 && b[i] == 0)
            {
                count++;
            }
            else if (a[i] != 0)
            {
                d = (-b[i]) / (a[i]);
                e.push_back(d);
            }
        }

        unordered_map<float,float> mp;
        for (i = 0; i < n-1; i++)
        {
            mp[e[i]]++;
        }
        for (auto x1 : mp)
        {
            e.push_back(x1.second);
          cout << x1.first << " " << x1.second << endl;
        }

        cout << count + *max_element(e.begin(), e.end());
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