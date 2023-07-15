#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
const lli mod = 1000000007;
void printsmaller(vector<int> a, int n)
{
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && s.top() >= a[i])
        {
            s.pop();
        }
        if (s.empty())
        {
            cout << "0 ";
        }
        else
        {
            cout << s.top() << " ";
        }
        s.push(a[i]);
    }
    cout << "\n";
}
void solve()
{
    lli n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    printsmaller(a, n);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    // int t;
    // cin >> t;
    // while (t--)
    //     solve();
}