#include <bits/stdc++.h>
using namespace std;
int dp[1000][1000];
void printsubset(int n, vector<int> arr)
{
    int i, currSum;

    // Finding sum of array elements
    int sum = accumulate(arr.begin(), arr.end(), 0);
    if (sum & 1)
    {
        cout << "-1";
        return;
    }
    int k = sum >> 1;
    vector<int> set1, set2;
    i = n;

    currSum = k;
    while (i > 0 && currSum >= 0)
    {

        // If current element does not
        // contribute to k, then it belongs
        // to set 2.
        if (dp[i - 1][currSum])
        {
            i--;
            set2.push_back(arr[i]);
        }

        // If current element contribute
        // to k then it belongs to set 1.
        else if (dp[i - 1][currSum - arr[i - 1]])
        {
            i--;
            currSum -= arr[i];
            set1.push_back(arr[i]);
        }
    }

    // Print elements of both the sets.
    cout << "Set 1 elements: ";
    for (i = 0; i < set1.size(); i++)
        cout << set1[i] << " ";
    cout << "\nSet 2 elements: ";
    for (i = 0; i < set2.size(); i++)
        cout << set2[i] << " ";
}
bool subsetsum(vector<int> a, int n, int sum)
{
    int i, currSum;

    if (n == 0 && sum != 0)
    {
        return 0;
    }
    if (sum == 0)
    {
        return 1;
    }
    if (dp[n][sum] != -1)
    {
        return dp[n][sum];
    }
    if (a[n - 1] > sum)
    {
        return dp[n][sum] = subsetsum(a, n - 1, sum);
    }
    if (a[n - 1] <= sum)
    {
        return dp[n][sum] = subsetsum(a, n - 1, sum - a[n - 1]) || (a, n - 1, sum);
    }
}
bool findpartition(vector<int> a, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + a[i];
    }
    if (sum % 2 != 0)
    {
        return 0;
    }
    else
    {
        return subsetsum(a, n / 2, sum);
    }
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int sum;
    memset(dp, -1, sizeof(dp));
    if (findpartition(a, n))
    {
        cout << "YES\n";
        printsubset(n, a);
    }
    else
    {
        cout << "NO\n";
    }
}
int main()
{
    solve();
}