#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
bool isSorted(vector<lli> &arr)
{
    lli n = arr.size();
    for (lli i = 1; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            return false;
        }
    }
    return true;
}
bool isSortedReverse(vector<lli> &arr)
{
    lli n = arr.size();
    for (lli i = 1; i < n; i++)
    {
        if (arr[i] > arr[i - 1])
        {
            return false;
        }
    }
    return true;
}
vector<lli> giveLIS(vector<lli> &nums)
{
    lli n = nums.size();
    vector<lli> lis(n, 1);

    for (lli i = 1; i < n; i++)
    {
        lli canAns = 1;
        for (lli j = i - 1; j >= 0; j--)
        {
            if (nums[j] < nums[i])
                canAns = max(canAns, lis[j] + 1);
        }

        lis[i] = canAns;
    }

    return lis;
}

void minRemovals(vector<lli> &nums, lli n)
{
    vector<lli> lis = giveLIS(nums);

    // find the lds using lis by just reversing
    reverse(nums.begin(), nums.end());
    vector<lli> lds = giveLIS(nums);
    reverse(lds.begin(), lds.end());

    lli maxi = 0;

    // ignoring the edge elements
    for (lli i = 0; i < n; i++)
    {
        // it can't be taken as we don't want the mountain
        // to have a steep
        if (lis[i] == 1 or lds[i] == 1)
            continue;

        maxi = max(maxi, lis[i] + lds[i] - 1);
    }

    // maxi is holding the length of largest bitonic subseq
    // i.e. that the largest length of mountain possible is
    // 'maxi' so the minimum number of pollis removal is
    // "length - maxi"

    lli ans = (n - maxi);

    // Prlli the answer
    cout << ans<<'\n';
}
int main()
{
    lli t;
    cin >> t;
    while (t--)
    {

        lli n;
        cin >> n;

        vector<lli> arr(n);
        for (lli i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
if ((n < 3) || (isSorted(arr)) || isSortedReverse(arr))
    {
        cout << "-1\n";
    }
    else{
        minRemovals(arr, n);}
    }
    return 0;
}