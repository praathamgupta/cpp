#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
const lli mod = 1000000007;

void solve()
{
    lli n, k, x;
    cin >> n >> k;
    lli sum = 0;
    priority_queue<lli> pq;
    priority_queue<lli> pq2;
    vector<int> b;
    for (int i = 0; i < n; i++)
    {
        lli x;
        cin >> x;
        pq.push(x);
    }
    for (int i = 0; i < k; i++)
    {
        x = pq.top();
        (sum = sum + x);
        pq.pop();
        pq.push(floor(x / 2));
    }
    for (int i = 0; i < n; i++)
    {
        pq2.push(sum);
    }
    cout << pq2.top();
    cout << "\n";
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
}