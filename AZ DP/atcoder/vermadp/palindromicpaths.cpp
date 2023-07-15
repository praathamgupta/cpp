#include <iostream>
#include <cstring>
using lli = long long int;
const lli mod = 1000000007;
const int MAXN = 501;
lli dp[MAXN][MAXN];
char grid[MAXN][MAXN];
lli n, m;

lli rec(lli i, lli j)
{
    if (i == 1 && j == 1)
    {
        return 1; // Reached the starting point, return 1 as a valid palindromic path
    }

    if (i < 1 || j < 1)
    {
        return 0; // Moved out of the grid boundaries, return 0
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j]; // Return the precalculated result
    }

    lli paths = 0;
    if (grid[i][j] == grid[n - i + 1][m - j + 1])
    {
        paths += rec(i - 1, j); // Move up
        paths += rec(i, j - 1); // Move left
    }

    dp[i][j] = paths % mod; // Save the result for future use
    return paths % mod;
}

void solve()
{
    std::cin >> n >> m;

    // Read the input grid
    for (lli i = 1; i <= n; i++)
    {
        std::string row;
        std::cin >> row;
        for (lli j = 1; j <= m; j++)
        {
            grid[i][j] = row[j - 1];
        }
    }

    // Initialize dp
    memset(dp, -1, sizeof(dp));

    // Call the recursive function
    std::cout << rec(n, m) % mod << "\n";
}

int main()
{
    solve();
    return 0;
}
