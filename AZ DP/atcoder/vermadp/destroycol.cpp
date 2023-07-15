#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int dp[555][555];
int n;
int arr[555];
int search(int l, int r)
{
    if (r <= l)
        return 1;
    if (dp[l][r] == -1)
    {
        dp[l][r] = 1 << 30;
    }
    else
    {
        return dp[l][r];
    }
    if (arr[l] == arr[r])
    {
        dp[l][r] = search(l + 1, r - 1);
    }
    for (int k = l; k < r; k++)
    {
        dp[l][r] = min(dp[l][r], search(l, k) + search(k + 1, r));
    }
    return dp[l][r];
}
int main()
{
    int t;cin>>t;while(t--){
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = -1;
        }
    }
    cout << search(1, n) << endl;}
}