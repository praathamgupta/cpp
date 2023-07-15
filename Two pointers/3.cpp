// Number of Subarray with sum at most K
#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int head = -1, tail = 0, ans = 0, distinct = 0;
        map<int, int> freq;
        while (tail < n)
        {
            while ((head + 1 < n) && ((freq[arr[head + 1]] == 0 && distinct < k) || freq[arr[head + 1]] > 0 && distinct <= k))
            {
                head++;
                if (freq[arr[head]] == 0)
                    distinct++;
                freq[arr[head]]++;
            }
            ans += head - tail + 1; // subarray max size=no. of subarrays with head as the start
            cout << head << " " << tail << " ";
            if (head >= tail)
            {
                freq[arr[tail]]--;
                if (freq[arr[tail]] == 0)
                {
                    distinct--;
                }
                tail++;
            }

            else
            {
                tail++;
                head = tail - 1;
            }
        }
        cout << "\n";
        cout << ans << endl;
    }
}