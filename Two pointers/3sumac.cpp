#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        
        // Sorting the input vector in ascending order
        sort(nums.begin(), nums.end());
        
        for (int j = 0; j < n; j++) {
            // Skip duplicate values of j
            if (j > 0 && nums[j] == nums[j - 1])
                continue;
            
            int i = j + 1;
            int k = n - 1;

            while (i < k) {
                int sum = nums[i] + nums[j] + nums[k];
                
                if (sum == 0) {
                    result.push_back({nums[i], nums[j], nums[k]});
                    // Skip duplicate values of i and k
                    while (i < k && nums[i] == nums[i + 1])
                        i++;
                    while (i < k && nums[k] == nums[k - 1])
                        k--;
                    i++;
                    k--;
                } else if (sum < 0) {
                    i++;
                } else {
                    k--;
                }
            }
        }
        
        return result;
    }
};



int main()
{
    // Read user input
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    // Find triplets that sum to zero
    Solution solution;
    vector<vector<int>> result = solution.threeSum(nums);

    // Display the result
    cout << "Triplets that sum to zero:" << endl;
    for (const auto &triplet : result)
    {
        for (int num : triplet)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
