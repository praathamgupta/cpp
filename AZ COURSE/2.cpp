// given a entry find whether it is alphabet or a digit
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    char ch;
    cin >> ch;

    // 0-9  -48-57
    // A-Z  -65-90
    // a-z  -97-123
    if (ch >= '0' && ch <= '9')
    {
        cout << "IS DIGIT\n";
    }
    else
    {
        if (ch >= 'a' && ch <= 'z')
        {
            cout << "ALPHA IS SMALL\n";
        }
        else
        {
            cout << "ALPHA IS LARGE\n";
        }
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}