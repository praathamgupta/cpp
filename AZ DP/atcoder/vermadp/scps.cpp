#include <bits/stdc++.h>
using namespace std;

string printShortestSuperSeq(string X, string Y)
{
    int m = X.length();
    int n = Y.length();
    int dp[m + 1][n + 1];

    for (int i = 0; i < m + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            if (i == 0)
                dp[i][j] = j;
            else if (j == 0)
                dp[i][j] = i;
            else if (X[i - 1] == Y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    string str;

    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (X[i - 1] == Y[j - 1])
        {
            str.push_back(X[i - 1]);
            i--, j--;
        }

        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            str.push_back(Y[j - 1]);
            j--;
        }
        else
        {
            str.push_back(X[i - 1]);

            i--;
        }
    }
    while (i > 0)
    {
        str.push_back(X[i - 1]);
        i--;
    }

    while (j > 0)
    {
        str.push_back(Y[j - 1]);
        j--;
    }

    reverse(str.begin(), str.end());
    return str;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string a, b;
        cin >> a >> b;
        cout << printShortestSuperSeq(a, b) << "\n";
    }
    return 0;
}
