#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
const lli mod = 1000000007;

lli maxhistogram(vector<lli> &v1)
{
    lli n = v1.size(); // Fix: Initialize 'n' with the size of the vector
    vector<lli> left(n);
    vector<lli> right(n);
    vector<lli> width(n);
    vector<lli> area(n);
    stack<pair<lli, lli>> s;
    stack<pair<lli, lli>> s1;
    lli pi = -1;
    lli pi2 = n;
    // Remove the input code for vector v1 from this function

    for (lli i = 0; i < n; i++)
    {
        if (s.empty())
        {
            left[i] = pi;
        }
        else if (!s.empty() && s.top().first < v1[i])
        {
            left[i] = s.top().second;
        }
        else if (!s.empty() && s.top().first >= v1[i])
        {
            while (!s.empty() && s.top().first >= v1[i])
            {
                s.pop();
            }
            if (s.empty())
            {
                left[i] = -1;
            }
            else
            {
                left[i] = s.top().second;
            }
        }
        s.push({v1[i], i});
    }

    for (lli i = n - 1; i >= 0; i--)
    {
        if (s1.empty())
        {
            right[i] = pi2;
        }
        else if (!s1.empty() && s1.top().first < v1[i])
        {
            right[i] = s1.top().second;
        }
        else if (!s1.empty() && s1.top().first >= v1[i])
        {
            while (!s1.empty() && s1.top().first >= v1[i])
            {
                s1.pop();
            }
            if (s1.empty())
            {
                right[i] = pi2;
            }
            else
            {
                right[i] = s1.top().second;
            }
        }
        s1.push({v1[i], i});
    }
    reverse(right.begin(), right.end());

    for (lli i = 0; i < n; i++)
    {
        width[i] = right[i] - left[i] - 1;
    }

    for (lli i = 0; i < n; i++)
    {
        area[i] = v1[i] * width[i];
    }

    sort(area.begin(), area.end());
    return area[n - 1];
}

void solve()
{
    lli n, m;
    cin >> n >> m;
    vector<vector<lli>> a(n, vector<lli>(m));

    for (lli i = 0; i < n; i++)
    {
        for (lli j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    vector<lli> v(a[0].begin(), a[0].end()); // Initialize v with values from a[0]

    lli mx = LLONG_MIN;

    for (lli i = 1; i < n; i++)
    {
        for (lli j = 0; j < m; j++)
        {
            if (a[i][j] == 0)
            {
                v[j] = 0;
            }
            else
            {
                v[j] = v[j] + a[i][j];
            }
            mx = max(mx, maxhistogram(v));
        }
    }

    cout << mx << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
