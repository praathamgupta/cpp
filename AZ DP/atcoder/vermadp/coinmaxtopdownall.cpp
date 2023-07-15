#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> findSubsetsWithSum(vector<int>& arr, int targetSum) {
    vector<vector<vector<int>>> dp(targetSum + 1, vector<vector<int>>());
    dp[0].push_back(vector<int>());

    for (int i = 1; i <= targetSum; i++) {
        for (int j = 0; j < arr.size(); j++) {
            if (i - arr[j] >= 0 && !dp[i - arr[j]].empty()) {
                for (const auto& subset : dp[i - arr[j]]) {
                    vector<int> newSubset = subset;  // Create a new subset
                    newSubset.push_back(arr[j]);     // Append the current element
                    dp[i].push_back(newSubset);      // Add the new subset to dp[i]
                }
            }
        }
    }

    return dp[targetSum];
}

int main() {
    vector<int> arr = {2, 3, 4}; // Example array
    int targetSum = 7;           // Example target sum

    vector<vector<int>> result = findSubsetsWithSum(arr, targetSum);

    // Printing the subsets
    if (result.empty()) {
        cout << "No subsets found with the target sum." << endl;
    } else {
        for (const auto& subset : result) {
            for (const auto& num : subset) {
                cout << num << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
