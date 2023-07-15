#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
const lli mod = 1000000007;
int cur_perm = 0;
string perm(int n, int k)
{
    int fact = 1;
    vector<int> numbers;
    for (int i = 1; i <= n; i++)
    {
        fact = fact * i;
        numbers.push_back(i);
    }
    numbers.push_back(n);
    string ans = "";
    k = k - 1;
    while (true)
    {
        ans = ans + to_string(numbers[k / fact]);
        numbers.erase(numbers.begin() + k / fact);
        if (numbers.size() == 0)
        {
            break;
        }
        k = k % fact;
        fact = fact / numbers.size();
    }
    return ans;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = i + 1;
    }
    string p = perm(n, k);
    stringstream ss(p);
    int x;
    while (ss >> x)
    {
        cout << x << " ";
    }
    return 0;
}
