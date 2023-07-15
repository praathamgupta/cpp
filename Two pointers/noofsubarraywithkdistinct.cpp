//Given an array of N integers,
// find the number of subarrays with at most K distinct elements.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll freq[1000001];
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll testcases;
    cin >> testcases;
    while (testcases--)
    {
        ll n, k;
        cin >> n >> k;
        ll arr[n];
        for (ll i = 0; i < n; i++)
            cin >> arr[i], freq[arr[i]] = 0;
        ll ans = 0;
        ll i = 0;
        ll j = 0;
        ll sum = 0;
        while (j < n)
        {
            freq[arr[j]]++;
//It increments the frequency of the current element arr[j] by 1.
            if (freq[arr[j]] == 1)
            {
                sum++;
//If the frequency of arr[j] becomes 1, it means that a new distinct
// element is encountered, so the sum variable is incremented by 1.
            }

            while (i <= j and sum > k)
            {
//The condition i <= j ensures that the loop continues 
//until the left pointer i is less than or equal to the right pointer j. 
//This condition ensures that the loop runs as long as there are elements within the current subarray.

//The condition sum > k checks if the number of distinct elements (sum)
// exceeds the maximum allowed distinct elements (k). If this condition is true, 
//it means that the current subarray has more than k distinct elements.
                if (freq[arr[i]] == 1)
                {
                    sum--;
                }
//Inside the loop, the code checks the frequency of the element arr[i]:
//a. If freq[arr[i]] is equal to 1, it means that 
//the frequency of arr[i] in the current subarray is 1. 
//Therefore, removing this element from the subarray 
//will reduce the count of distinct elements by 1.
// Hence, the sum variable is decremented by 1.

                freq[arr[i]]--;
                i++;
//b. Regardless of the frequency of arr[i], the code decrements 
//the frequency of arr[i] in the freq array to reflect the removal of this element from the current subarray.
            }
            ans += (j - i + 1);
            j++;
        }
        cout << ans << "\n";
    }
}