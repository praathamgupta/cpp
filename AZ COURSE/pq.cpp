// https://www.learning.algozenith.com/problems/Deque-AZ101-332
#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
const lli mod = 1000000007;

void solve()
{
    lli q, x;
    cin >> q;
    priority_queue<lli> pq;
    while (q--)
    {
        string s;
        cin >> s;
        if (s == "add")
        {
            cin >> x;
            pq.push(x);
        }
        else if (s == "remove")
        {
            if (!pq.empty())
            {
                pq.pop();
            }
        }
        else if (s == "print")
        {
            if (!pq.empty())
            {
                cout << pq.top();
                cout << "\n";
            }
            else{
                cout<<"0\n";
            }
        }
    }
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