#include <bits/stdc++.h>
using namespace std;

// Input: nums = [1,1,1], k = 2
// Output: 2
// Example 2:

// Input: nums = [1,2,3], k = 3
// Output: 2
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        int sum = 0;
        map<int, int> mp;
        mp[0]++;
        vector<int> p(n);
        p[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            p[i] = p[i - 1] + nums[i];
        }
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (mp.count(p[i] - k))
            {
                count += mp[p[i] - k];
            }
            mp[p[i]]++;
        }
        return count;
    }
};
