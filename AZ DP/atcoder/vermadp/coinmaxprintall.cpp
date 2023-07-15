#include <iostream>
#include <vector>
using namespace std;

void maxcoin(vector<int> &a, int n, int sum, vector<int> &current, vector<vector<int>> &result)
{
    if (sum == 0)
    {
        result.push_back(current);
        return;
    }
    if (n == 0)
    {
        return;
    }
    if (a[n - 1] <= sum)
    {
        maxcoin(a, n - 1, sum, current, result);
        current.push_back(a[n - 1]);
        maxcoin(a, n, sum - a[n - 1], current, result);
        current.pop_back();
    }
    else
    {
        maxcoin(a, n - 1, sum, current, result);
    }
}

void solve()
{
    int n, sum, k;
    cin >> sum >> k;

    // Initialize 'n' based on the sum and k
    n = sum - k + 1;

    vector<int> a;
    for (int i = 1; i <= n; i++)
    {
        a.push_back(i);
    }

    vector<int> current;
    vector<vector<int>> result;
    maxcoin(a, n, sum, current, result);

    int count = 0;
    for (const auto &subarray : result)
    {
        if (subarray.size() == k)
        {
            count++;
        }
    }

    cout << count << "\n";
}

int main()
{
    solve();
    return 0;
}
