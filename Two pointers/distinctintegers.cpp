#include <bits/stdc++.h>
using namespace std;
using lli = long long;
lli freq[1000001];
lli atmostk(vector<lli> &a, lli n, lli k)
{
    for (lli i = 0; i < n; i++)
        freq[a[i]] = 0;
    lli ans = 0;
    lli i = 0;
    lli j = 0;
    lli cnt = 0;
    // 1 2 3 2 4 2    k = 3
    while (j < n)
    {
        freq[a[j]]++;
        // It increments the frequency of the current element arr[j] by 1.
        if (freq[a[j]] == 1)
        {
            cnt++;
            // If the frequency of arr[j] becomes 1, it means that a new distinct
            //  element is encountered, so the sum variable is incremented by 1.
        }

        while (i <= j and cnt > k)
        {
            // The condition i <= j ensures that the loop continues
            // until the left pointer i is less than or equal to the right pointer j.
            // This condition ensures that the loop runs as long as there are elements within the current subarray.

            // The condition cnt > k checks if the number of distinct elements (sum)
            //  exceeds the maximum allowed distinct elements (k). If this condition is true,
            // it means that the current subarray has more than k distinct elements.
            if (freq[a[i]] == 1)
            {
                cnt--;
            }
            // Inside the loop, the code checks the frequency of the element arr[i]:

            // a. If freq[arr[i]] is equal to 1, it means that
            // the frequency of arr[i] in the current subarray is 1.
            // Therefore, removing this element from the subarray
            // will reduce the count of distinct elements by 1.
            //  Hence, the sum variable is decremented by 1.

            freq[a[i]]--;
            i++;
            // b. Regardless of the frequency of arr[i], the code decrements
            // the frequency of arr[i] in the freq array to reflect the removal of this element from the current subarray.
        }
        ans += (j - i + 1);
        j++;
    }
    return ans;
}
lli exactlyK(vector<lli> &a, lli n, lli k)
{

    // Count of subarrays with exactly k distinct
    // elements is equal to the difference of the
    // count of subarrays with at most K distinct
    // elements and the count of subararys with
    // at most (K - 1) distinct elements
    return (atmostk(a, n, k) - atmostk(a, n, k - 1));
}
void solve()
{
    lli n, k;
    cin >> n >> k;
    vector<lli> a(n);
    for (lli i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << exactlyK(a, n, k) << "\n";
}

int main()
{
    lli t;
    cin >> t;
    while (t--)
        solve();
}
