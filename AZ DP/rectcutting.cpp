#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int a, b;
    cin >> a >> b;
    int dp[a + 1][b + 1];
    for (int height = 1; height <= a; height++)
    {
        for (int width = 1; width <= b; width++)
        {
            if (height == width)
            {
                dp[height][width] = 0;
            }
            else
            {
                dp[height][width] = 1e8; // Initialize to a large value
                for (int i = 1; i < width; i++)
                {
                    dp[height][width] = min(dp[height][width], 1 + dp[height][width - i] + dp[height][i]);
                }
                for (int i = 1; i < height; i++)
                {
                    dp[height][width] = min(dp[height][width], 1 + dp[height - i][width] + dp[i][width]);
                }
            }
        }
    }
    cout << dp[a][b] << "\n";
}

int main()
{
    solve();
    return 0;
}
