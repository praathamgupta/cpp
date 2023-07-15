#include <vector>
#include <climits>

class Solution
{
private:
    int maxc(std::vector<int> &nums, std::vector<std::vector<int>> &dp, int i, int j)
    {
        if (i > j)
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int ans = INT_MIN; // Updated initialization
        for (int k = i; k <= j; k++)
        {
            int coins = (nums[i - 1] * nums[k] * nums[j + 1]) + maxc(nums, dp, i, k - 1) + maxc(nums, dp, k + 1, j);
            ans = std::max(ans, coins);
        }
        return dp[i][j] = ans;
    }

public:
    int maxCoins(std::vector<int> &nums)
    {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        //n the given code are modifying the nums vector by adding 
        //elements at the beginning and end of the vector.
        
        std::vector<std::vector<int>> dp(n + 2, std::vector<int>(n + 2, -1)); // Updated initialization
        return maxc(nums, dp, 1, n);
    }
};
