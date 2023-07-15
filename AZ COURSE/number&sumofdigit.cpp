#include <bits/stdc++.h>
using namespace std;
bool check(int mid){
    
}
void solve()
{
    int n, s;
    cin >> n >> s;
    int lo = 0;
    int hi = n - 1;
    int ans = 0;
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (check(mid) == 0)
        {
            ans = mid;
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }
    cout<<ans<<"\n";
}
int main()
{

    // int t;cin>>t;while(t--)
    solve();
}