#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
const lli mod = 1000000007;
int n;
vector<int> queens;
bool check(int row, int col)
{
    for (int prow = 0; prow < row; prow++)
    {
        int pcol = queens[prow];
        if (pcol == col || abs(row - prow) == abs(col - pcol) || abs(row - prow) + abs(col - pcol) == 3)
        {
            return 0;
        }
    }
    return 1;
}
int cnt=0;
void rec(int level)
{
    if (level == n)
    {
        cnt++;
    }
    for (int col = 0; col < n; col++)
    {
        if (check(level, col))
        {
            queens.push_back(col);
            rec(level + 1);
            queens.pop_back();
        }
    }
}
void solve()
{
    cin >> n;
    rec(0);
    cout << cnt << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int t;cin>>t;while(t--)
    solve();
}