#include <bits/stdc++.h>
using namespace std;
#define int long long

bool ispalindrome(const string &s)
{
    string s1 = s;
    reverse(s1.begin(), s1.end());
    return s == s1;
}

void solve()
{
    string s;
    cin >> s;
    while (true)
    {
        if (!ispalindrome(s))
        {
            s = to_string(stoll(s) + 1);
        }
        else
        {
            cout << s << "\n";
            break;
        }
    }
}

signed main()
{
    solve();
    return 0;
}
