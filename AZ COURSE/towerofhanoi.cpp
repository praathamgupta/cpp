#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
const lli mod = 1000000007;
// Time & Space complexity:  O( log(min(a,b)) )

void moveDisks(int disks, int currentpeg, int moveto, int helper)
{
    if (disks == 0)
    {
        return;
    }
    moveDisks(disks - 1, currentpeg, helper, moveto);
    cout << "Move from " << currentpeg << "to " << moveto << "\n";
    moveDisks(disks - 1, helper, moveto, currentpeg);
}
void moveKth(int disks, int currentpeg, int moveto, int helper, int k)
{
    if (disks == 0)
    {
        return;
    }

    if (k <= ((1 << (disks - 1)) - 1))
    {
        moveKth(disks - 1, currentpeg, helper, moveto, k);   //2^(n-1 )   +1     + 2^(n-1) for 3 disks
    }
    else if (k == ((1 << (disks - 1))))
    {
        cout << "Move disks " << disks << " from " << currentpeg << " to " << moveto << "\n";
    }
    else
    {
        moveKth(disks - 1, helper, moveto, currentpeg,k-((1 << (disks - 1))));
    }
}
void solve()
{
    moveKth(3, 1, 3, 2,4);
    // Moves:  //2^(n-1)
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int t;cin>>t;while(t--)
    solve();
}