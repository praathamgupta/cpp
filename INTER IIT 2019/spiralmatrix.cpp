#include <bits/stdc++.h>
using namespace std;
vector<int> spiralOrder(const vector<vector<int>> &A)
{

    int T, B, L, R, dir;
    T = 0;
    B = A.size() - 1;
    L = 0;
    R = A[0].size() - 1;
    dir = 0;
    int i;
    vector<int> ans;

    while (T <= B && L <= R)
    {
        if (dir == 0)
        {
            for (i = L; i <= R; i++)
                ans.push_back(A[T][i]);
            T++;
        }
        else if (dir == 1)
        {
            for (i = T; i <= B; i++)
                ans.push_back(A[i][R]);
            R--;
        }
        else if (dir == 2)
        {
            for (i = R; i >= L; i--)
                ans.push_back(A[B][i]);
            B--;
        }
        else if (dir == 3)
        {
            for (i = B; i >= T; i--)
                ans.push_back(A[i][L]);
            L++;
        }
        dir = (dir + 1) % 4;
    }
    return ans;
}
int findK(int A[][], int n, int m, int k)
{
    if (n < 1 || m < 1)
        return -1;

    /*....If element is in outermost ring ....*/
    /* Element is in first row */
    if (k <= m)
        return A[0][k - 1];

    /* Element is in last row */
    if (k <= (m + n - 1 + m - 1))
        return A[n - 1][m - 1 - (k - (m + n - 1))];
        
    /* Element is in last column */
    if (k <= (m + n - 1))
        return A[(k - m)][m - 1];

    /* Element is in first column */
    if (k <= (m + n - 1 + m - 1 + n - 2))
        return A[n - 1 - (k - (m + n - 1 + m - 1))][0];

    /*....If element is NOT in outermost ring ....*/
    /* Recursion for sub-matrix. &A[1][1] is
    address to next inside sub matrix.*/
    return findK((int(*)[])(&(A[1][1])), n - 2,
                 m - 2, k - (2 * n + 2 * m - 4));
}

void solve()
{
}
int main()
{
    solve();
}