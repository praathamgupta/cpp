#include <bits/stdc++.h>
using namespace std;
#define int long long

string s = "";
int n, k;
int cl = 0, op = 0;

void generate(int open, int close)
{
    if (s.size() == 2 * n)
    {
        int count = 0;
        int mxcount = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                count++;
            }
            else if (s[i] == ')')
            {
                count--;
            }
            mxcount = max(count, mxcount);
        }
        if (mxcount == k)
        {
            cout << s << "\n";
        }
    }
    if (open < n)
    {
        s.push_back('(');
        generate(open + 1, close);
        s.pop_back();
    }
    if (close < open)
    {
        s.push_back(')');
        generate(open, close + 1);
        s.pop_back();
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> n >> k;
    n /= 2;
    generate(op, cl);
    return 0;
}