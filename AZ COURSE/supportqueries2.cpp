#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
const lli mod = 1000000007;

// Time & Space complexity:  O( log(min(a,b)) )

void solve()
{
    int q, k, x, y;
    int sum = 0;
    int sum1 = 0;
    char c;
    cin >> q >> k;
    multiset<int> st1;
    multiset<int> st2;
    while (q--)
    {
        int n;
        cin >> n;
        if (n == 1)
        {
            int x;
            cin >> x;
            if (st1.size() < k)
            {
                st1.insert(x);
                sum += x;
            }
            else
            {
                if (x > *st1.begin())
                {
                    sum = sum + x - *st1.begin();
                    st2.insert(*st1.begin());
                    st1.erase(st1.begin());
                    st1.insert(x);
                }
                else
                {
                    st2.insert(x);
                }
            }
        }
        else if (n == 2)
        {
            int x;
            cin >> x;
            if (st2.find(x) != st2.end())
            {
                st2.erase(st2.find(x));
            }
            else if (st1.find(x) != st1.end())
            {
                sum = sum - x;
                st1.erase(st1.find(x));

                if (st2.size())
                {
                    sum += *st2.rbegin();
                    st1.insert(*st2.rbegin());
                    auto it = st2.end();
                    it--;
                    st2.erase(it);
                }
            }
        }
        else
        {
            char c;
            cin >> c;
            cout << sum << endl;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    solve();
}