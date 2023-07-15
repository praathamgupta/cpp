#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
const lli mod = 1000000007;

// Time & Space complexity:  O( log(min(a,b)) )

void solve()
{
    lli q, y;
    lli x;
    char c;
    cin >> q;
    list<int> li;
    while (q--)
    {
        int sum = 0;
        cin >> x;
        if (x == 1)
        {
            cin >> y;
            li.push_back(y);
        }
        else if (x == 2)
        {
            cin >> y;
            auto it1 = find(li.begin(), li.end(), y);
            if (it1 != li.end())
            {
                li.erase(it1);
            }
        }
        else if (x == 3)
        {
            cin >> c;
            if (!li.empty())
            {
                cout << *li.rbegin() << "\n";
            }
            else
            {
                cout << "-1"
                     << "\n";
            }
        }
        else if (x == 4)
        {
            cin >> c;
            if (!li.empty())
            {
                cout << *li.begin() << "\n";
            }
            else
            {
                cout << "-1"
                     << "\n";
            }
        }
        else if (x == 5)
        {
            cin >> c;
            if (!li.empty())
            {
                for (auto it = li.rbegin(); it != li.rend(); it++)
                {
                    sum = sum + *it;
                }
                cout << sum << "\n";
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
    solve();
}