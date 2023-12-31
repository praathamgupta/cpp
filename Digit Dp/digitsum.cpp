#include <bits/stdc++.h>
using namespace std;
#define int long long
// function to convert digit to vector
vector<int> digitToVec(int n)
{
    vector<int> a;
    while (n)
    {
        a.push_back(n % 10);
        n = n / 10;
    }
    reverse(a.begin(), a.end());
    return a;
}

int Y;                     // setting Y as global
int dp[19][2][18 * 9 + 1]; // 3D dp

// Function to count the number of integers with digit sum equal to Y
int func(int ind, int flag, int sum, vector<int> a)
{
    if (ind == a.size())
    {
        if (sum == Y)
            return 1;
        else
            return 0;
    }
    if (dp[ind][flag][sum] != -1)
        return dp[ind][flag][sum];

    // if flag = 0, I know I can only fill from 0 to a[ind]
    // if flag = 1, I have the advantage to fill from 0 to 9
    int limit = 9;
    if (flag == 0)
        limit = a[ind];

    int cnt = 0;
    for (int num = 0; num <= limit; num++)
    {
        // if flag = 0, which means no advantage
        // and I am still filling the same number as a[ind] means giving him no advantage
        // hence the next recursion call flag still stays as 0
        if (flag == 0 && num == a[ind])
        {
            cnt += func(ind + 1, 0, sum + num, a);
        }
        else
        {
            cnt += func(ind + 1, 1, sum + num, a);
        }
    }
    return dp[ind][flag][sum] = cnt;
}

// Intermediate function helping to initialize all values of func()
int ans(int n)
{
    vector<int> a = digitToVec(n);
    memset(dp, -1, sizeof dp); // initializing dp as -1
    return func(0, 0, 0, a);
}

// Function to find the smallest number that satisfies the condition
int findSmallest(int Y)
{
    for (int num = 1; num <= 9 * 18; num++)
    {
        if (ans(num) == 1)
            return num;
    }
    return -1; // If no number satisfies the condition
}
void solve()
{
    int l, r;
    cin >> l >> r >> Y;
    cout << ans(r) - ans(l - 1) << '\n';

    int smallest = findSmallest(Y);

    cout << smallest << '\n';
}
// Driver code
signed main()
{

    solve();
}
