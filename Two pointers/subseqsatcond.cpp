// Input: nums = [3,5,6,7], target = 9
// Output: 4
// Explanation: There are 4 subsequences that satisfy the condition.
// [3] -> Min value + max value <= target (3 + 3 <= 9)
// [3,5] -> (3 + 5 <= 9)
// [3,5,6] -> (3 + 6 <= 9)
// [3,6] -> (3 + 6 <= 9)


#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numSubseq(vector<int> &A, int target)
    {
        sort(A.begin(), A.end());
        int res = 0, n = A.size(), l = 0, r = n - 1, mod = 1e9 + 7;
        vector<int> pows(n, 1);
        for (int i = 1; i < n; ++i)
            pows[i] = pows[i - 1] * 2 % mod;
        while (l <= r)
        {
            if (A[l] + A[r] > target)
            {
                r--;
            }
            else
            {
                res = (res + pows[r - l]) % mod;
                l++;
            }
        }
        return res;
    }
};
