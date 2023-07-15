#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> findSubsetsWithSum(vector<int> &arr, int targetSum)
{
    vector<vector<vector<int>>> dp(targetSum + 1, vector<vector<int>>());
    dp[0].push_back(vector<int>());

    for (int i = 1; i <= targetSum; i++)
    {
        for (int j = 0; j < arr.size(); j++)
        {
            if (i - arr[j] >= 0 && !dp[i - arr[j]].empty())
            {
                for (const auto &subset : dp[i - arr[j]])
                {
                    if (subset.empty() || arr[j] >= subset.back())
                    {
                        vector<int> newSubset = subset; // Create a new subset
                        newSubset.push_back(arr[j]);    // Append the current element
                        dp[i].push_back(newSubset);     // Add the new subset to dp[i]
                    }
                }
            }
        }
    }

    return dp[targetSum];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, targetSum, k;
        cin >> n >> k;
        vector<int> arr;         // Example array
        targetSum = (n - k + 1); // Example target sum
        for (int i = 1; i <= targetSum; i++)
        {
            arr.push_back(i);
        }

        vector<vector<int>> result = findSubsetsWithSum(arr, n);
        int count = 0;
        // Printing the subsets
        if (result.empty())
        {
            // cout << "No subsets found with the target sum." << endl;
            cout << "0\n";
        }
        else
        {
            for (const auto &subset : result)
            {
                for (const auto &num : subset)
                {
                    // cout << num << " ";
                }
                // cout << endl;
                if (subset.size() == k)
                {
                    count++;
                }
            }
            cout << count << "\n";
        }
    }

    return 0;
}
