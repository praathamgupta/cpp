#include <bits/stdc++.h>
using namespace std;

vector<int> findOccurrences(vector<int> &A)
{
    sort(A.begin(), A.end());
    unordered_map<int, int> mp;
    for (int i = 0; i < A.size(); i++)
    {
        mp[A[i]]++;
    }
    vector<int> b;
    for (auto v : mp)
    {
        b.push_back(v.second);
    }
    reverse(b.begin(), b.end());
    return b;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> occurrences = findOccurrences(a);
    for (auto x : occurrences)
    {
        cout << x << " ";
    }
    cout << endl;
    for (auto x : a)
    {
        // cout << x << " ";
    }
    return 0;
}
