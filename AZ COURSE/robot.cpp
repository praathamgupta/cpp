#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, r, c, x, y;
    cin >> n >> r >> c >> x >> y;
    string s;
    cin >> s;
    int countUp = 0, countDown = 0;
    int countLeft = 0, countRight = 0;
    for (int i = 0; i < s.size(); i++)
    {

        if (s[i] == 'N')
            countUp++;
        else if (s[i] == 'S')
            countDown++;
        else if (s[i] == 'W')
            countLeft++;
        else if (s[i] == 'E')
            countRight++;
    }
    cout << (x + countRight - countLeft)
         << ", " << (y + countUp - countDown) << endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}