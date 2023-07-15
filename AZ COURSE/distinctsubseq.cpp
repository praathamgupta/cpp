#include <bits/stdc++.h>
using namespace std;
int mergeElements(const vector<int> &A,int n)
{

    vector<vector<int>> C(n, vector<int>(n));
    vector<vector<int>> V(n, vector<int>(n));

    for (int i = 0; i < n; ++i)
    {
        V[i][i] = A[i];
    }

    for (int length = 2; length <= n; ++length)
    {
        for (int i = 0; i < n - length + 1; ++i)
        {
            int j = i + length - 1;
            V[i][j] = (V[i][i] + V[i + 1][j]) % 100;
            C[i][j] = 1e9;
            for (int k = i; k < j; ++k)
            {
                int cost = C[i][k] + C[k + 1][j] + V[i][k] * V[k + 1][j];
                if (cost < C[i][j])
                {
                    C[i][j] = cost;
                }
            }
        }
    }

    return C[0][n - 1];
}

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    int minimum_cost = mergeElements(A,n);
    cout << minimum_cost << endl;
}
