// https://www.learning.algozenith.com/problems/Deque-AZ101-332
#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
const lli mod = 1000000007;

void solve()
{
    lli q, x;
    cin >> q;
    deque<lli> dq;
    deque<lli>::iterator itr;
    while (q--)
    {
        string s;
        cin >> s;
        if (s == "insertback")
        {
            cin >> x;
            dq.push_back(x);
        }
        else if (s == "insertfront")
        {
            cin >> x;
            dq.push_front(x);
        }
        else if (s == "erasefront")
        {
            if (!dq.empty())
            {
                dq.pop_front();
            }
        }
        else if (s == "eraseback")
        {
            if (!dq.empty())
            {
                dq.pop_back();
            }
        }
        else if (s == "printfront")
        {
            if (!dq.empty())
            {
                cout << dq[0];
                cout << "\n";
            }
            else
            {
                cout << "0\n";
            }
        }
        else if (s == "printback")
        {
            if (!dq.empty())
            {
                cout << dq[(dq.size() - 1)];
                cout << "\n";
            }
            else
            {
                cout << "0\n";
            }
        }
        else if (s == "print")
        {
            cin >> x;

           
            if (dq.size()>x)
            {
                cout << dq[x];
                cout << "\n";
            }
            else
            {
                cout << "0\n";
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