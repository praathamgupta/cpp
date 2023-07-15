
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, i;
    cin >> n;
    vector<int> a;
    vector<int> b;
    vector<int> c;
    for (i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    for (i = 0; i < n - 1; i++)
    {
        b.push_back(a[i] - a[i + 1]);
    }
    for (auto x : b)
    {
        cout << x;
        cout << "\n";
    }
    unordered_map<int, int> mp;
    for (i = 0; i < n - 1; i++)
    {
        mp[b[i]]++;
    }

    for (auto x1 : mp)
    {
        c.push_back(x1.second);
    }
    cout << 1 + *max_element(c.begin(), c.end());
    cout << "\n";

    return 0;
}