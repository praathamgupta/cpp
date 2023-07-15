#include <bits/stdc++.h>
using namespace std;
vector<int> prefixlis(vector<int> &arr)
{
    vector<int> temp;
    vector<int> ans;

    for (auto x : arr)
    {
        if (temp.empty() || x > temp.back())
        {
            temp.push_back(x);
        }
        else
        {
            auto it = lower_bound(temp.begin(), temp.end(), x);
            *it = x;
        }

        ans.push_back(temp.size());
    }
    return ans;
}
int main()
{
    string s;
    cin >> s;
    int n = s.size();
    vector<int> asciiNumbers;

    for (char c : s)
    {
        int asciiValue = static_cast<int>(c);
        asciiNumbers.push_back(asciiValue);
    }

    for (int value : asciiNumbers)
    {
        cout << value << " ";
    }
    cout<<"\n";
     auto LIS = prefixlis(asciiNumbers);
    reverse(asciiNumbers.begin(), asciiNumbers.end());
    auto LDS = prefixlis(asciiNumbers);
    reverse(LDS.begin(), LDS.end());
    reverse(asciiNumbers.begin(), asciiNumbers.end());

    int ans = -1;
    for (int i = 0; i < n; i++)
    {
        if ((LDS[i] + LIS[i] - 1) > ans && LDS[i] >= 2 && LIS[i] >= 2)
        {
            ans = LDS[i] + LIS[i]; 
            // By adding LDS[i] and LIS[i] and subtracting 1, 
            //we get the length of the bitonic subsequence
            // that includes the element at index i.
            //  The if condition checks whether this length 
            //is greater than the current maximum ans
        }
    }

    if (ans >= 3)
    {
        cout << (ans) << '\n';
    }
    else
    {
        cout << -1 << '\n';
    }
}