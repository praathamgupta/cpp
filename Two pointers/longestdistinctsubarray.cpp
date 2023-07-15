#include <bits/stdc++.h>
using namespace std;
int largest_subarray(vector<int> &a, int n)
{
    // Stores index of array elements
    unordered_map<int, int> index;
    int ans = 0;
    for (int i = 0, j = 0; i < n; i++)
    {

        // Update j based on previous
        // occurrence of a[i]
        j = max(index[a[i]], j);

        // Update ans to store maximum
        // length of subarray
        ans = max(ans, i - j + 1);

        // Store the index of current
        // occurrence of a[i]
        index[a[i]] = i + 1;
    }

    // Return final ans
    return ans;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << largest_subarray(a, n) << "\n";
}

int main()
{
    int t;cin>>t;while(t--)
    solve();
   
}
