#include <bits/stdc++.h>
using namespace std;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int testcases;
    cin >> testcases;
    int freq[1000001] = {0};
    while (testcases--)
    {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int ans = k;
        int i = 0;
        int j = 0;
        int currSum = 0;
        while (j < n)
        {
            if (freq[arr[j]] == 0)
                currSum++;
            freq[arr[j]]++;
            if (j >= k)
            {
                freq[arr[j - k]]--;
                if (freq[arr[j - k]] == 0)
                    currSum--;
            }
            if (j >= k - 1)
                ans = min(ans, currSum);
            j++;
        }
        for (int i = n - k; i < n; i++) // only the frequency of last d element is set, so for next testcase making it zero.
            freq[arr[i]]--;
        cout << ans << "\n";
    }
}