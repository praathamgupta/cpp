#include <bits/stdc++.h>
using namespace std;
char a[8][8];
vector<int> queens;
int n;
bool check(int row, int col)
{
    if (a[row][col] == '*')
    {
        return 0;
    }
    for (int prow = 0; prow < row; prow++)
    {
        int pcol = queens[prow];
        if (pcol == col || abs(row - prow) == abs(col - pcol) /*diagonal conition*/)
        { // attack cond
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
int main()
{
    n = 8;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    rec(0);
    cout << cnt << "\n";

    return 0;
}