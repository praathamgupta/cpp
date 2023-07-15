// Given an array where every element occurs three times, except one element which occurs only once. Find the element that occurs once.
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[a[i]]++;
    }
    for (auto v : mp)
    {
        if (v.second == 1)
        {
            cout << v.first << "\n";
        }
    }

    return 0;
}