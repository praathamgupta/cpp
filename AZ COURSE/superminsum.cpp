#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
const lli mod = 1000000007;

void solve()
{
    lli n, k, h = 0;
    cin >> n;
    vector<lli> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    lli left[n], right[n];

    stack<pair<lli, lli>> s1, s2;

    for (lli i = 0; i < n; ++i)
    {
        lli cnt = 1;
        while (!s1.empty() && (s1.top().first) > A[i])
        {
            cnt += s1.top().second;
            s1.pop();
        }

        s1.push({A[i], cnt});
        left[i] = cnt;
    }

    for (lli i = n - 1; i >= 0; --i)
    {
        lli cnt = 1;
        while (!s2.empty() && (s2.top().first) >= A[i])
        {
            cnt += s2.top().second;
            s2.pop();
        }

        s2.push({A[i], cnt});
        right[i] = cnt;
    }

    lli result = 0;

    // calculating required resultult
    for (lli i = 0; i < n; ++i)
    {
        result = (result + A[i] * left[i] * right[i]);
    }
    cout << result << "\n";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli t;
    cin >> t;
    while (t--)
        solve();
}