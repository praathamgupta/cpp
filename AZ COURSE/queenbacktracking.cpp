#include <bits/stdc++.h>
using namespace std;
#define int long long
char a[8][8];
int n;
vector<int> queens;
bool check(int row, int col)
{
    if (a[row][col] == '*')
    {
        return 0;
    }
    for (int prow = 0; prow < row; prow++)
    {
        int pcol = queens[prow];
        if (pcol == col || abs(prow - row) == abs(pcol - col))
        {
            return 0;
        }
    }
    return 1;
}
int cnt = 0;
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
    n = 8;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cin >> a[i][j];
        }
    }
    rec(0);
    cout << cnt;
}
signed main()
{
    solve();
}
