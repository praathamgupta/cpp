#include <iostream>
#include <vector>
#include <deque>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int k;
    cin >> k;
    int i = 0, j = 0;
    int sum = 0;
    int maxlen = -1e9;
    while (j < n)
    {
        sum += a[j];
        if (sum < k)
        {
            j++;
        }
        else if (sum == k)
        {
            maxlen = max(maxlen, j - i + 1);
            j++;
        }
        else if (sum > k)
        {
            while (sum > k)
            {
                sum -= a[i];
                i++;
                if (sum == k)
                {
                    maxlen = max(maxlen, (j - i + 1));
                   
                }
                j++;
            }
        }
    }
    cout << maxlen << "\n";
}

int main()
{
    solve();
    return 0;
}
