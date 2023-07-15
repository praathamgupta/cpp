#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
const lli mod = 1000000007;

// Time & Space complexity:  O( log(min(a,b)) )
// abuilding can be expanded only when other building >= current building.
void solve()
{
    int n;
    cin >> n;
    vector<int> v1(n);
    vector<int> left;
    vector<int> right;
    vector<int> width;
    vector<int> area;
    stack<pair<int, int>> s;
    stack<pair<int, int>> s1;
    int pi = -1;
    int pi2 = n;
    for (int i = 0; i < n; i++)
    {
        cin >> v1[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (s.empty())
        {
            left.push_back(pi);
        }
        else if (!s.empty() && (s.top()).first < v1[i])
        {
            left.push_back((s.top()).second);
        }
        else if (!s.empty() && (s.top()).first >= v1[i])
        {
            while (!s.empty() && (s.top()).first >= v1[i])
            {
                s.pop();
            }
            if (s.empty())
            {
                left.push_back(-1);
            }
            else
            {
                left.push_back((s.top()).second);
            }
        }
        s.push({v1[i], i});
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (s1.empty())
        {
            right.push_back(pi2);
        }
        else if (!s1.empty() && (s1.top()).first < v1[i])
        {
            right.push_back((s1.top()).second);
        }
        else if (!s1.empty() && (s1.top()).first >= v1[i])
        {
            while (!s1.empty() && (s1.top()).first >= v1[i])
            {
                s1.pop();
            }
            if (s1.empty())
            {
                right.push_back(pi2);
            }
            else
            {
                right.push_back((s1.top()).second);
            }
        }
        s1.push({v1[i], i});
    }
    reverse(right.begin(), right.end());
    for (int i = 0; i < n; i++)
    {
        width.push_back(right[i] - left[i] - 1);
    }
    for (int i = 0; i < n; i++)
    {
        area.push_back(v1[i] * width[i]);
    }
    sort(area.begin(), area.end());
    cout << area[n - 1] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}