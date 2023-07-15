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
    deque<int> dq;
    int i = 0, j = 0;
    vector<int> res;
    while (j < n)
    {
        while (!dq.empty() && dq.back() < a[j])
        {
            dq.pop_back();
        }
        dq.push_back(a[j]);
        if ((j - i + 1) < k)
        {
            j++;
        }
        else if ((j - i + 1) == k) // Corrected condition
        {
            res.push_back(dq.front());
            if (dq.front() == a[i])
            {
                dq.pop_front();
            }
            i++;
            j++;
        }
    }
    for (auto x : res)
    {
        cout << x << " ";
    }
}

int main()
{
    solve();
    return 0;
}
