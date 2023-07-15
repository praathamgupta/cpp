#include <bits/stdc++.h>
using namespace std;

// Function to return the minimum number of
// delete operations
int findMinimumDeletion(int l, int r, vector<vector<int>> &dp, string &s)
{

    if (l > r)
        return 0;
    if (l == r)
        return 1;
    if (dp[l][r] != -1)
        return dp[l][r];

    // When a single character is deleted
    int res = 1 + findMinimumDeletion(l + 1, r, dp, s);

    // When a group of consecutive characters
    // are deleted if any of them matches
    for (int i = l + 1; i <= r; ++i)
    {

        // When both the characters are same then
        // delete the letters in between them
        if (s[l] == s[i])
            res = min(res, findMinimumDeletion(l + 1, i, dp, s) + findMinimumDeletion(i + 1, r, dp, s));
    }

    // Memoize
    return dp[l][r] = res;
}

// Driver code
int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    n = s.length();
    vector<vector<int>> dp(501, vector<int>(501, -1));
    cout << findMinimumDeletion(0, n - 1, dp, s);
  
}