#include <bits/stdc++.h>
using namespace std;

// Prints sums of all subsets of array
void subsetSums(int arr[], int l, int r, int sum = 0)
{
    // Print current subset
    if (l > r)
    {
        cout << sum << " ";
        return;
    }

    // Subset including arr[l]
    subsetSums(arr, l + 1, r, sum + arr[l]);

    // Subset excluding arr[l]
    subsetSums(arr, l + 1, r, sum);

    // cout << sum << " ";
}

// Driver code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        int count = 0;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        if (subsetSums(arr, 0, n - 1, x) <= x)
        {
            count++;
        }

        cout << count << "\n";
    }
    return 0;
}