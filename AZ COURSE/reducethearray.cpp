#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
const lli mod = 1000000007;

//arr[i] = *(arr+i)

void solve()
{
    lli n;
    cin >> n;
    multiset<lli> ms;
    vector<lli> b;
    for (lli i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        ms.insert(x);
    }
    if(n==1)
    {
        cout<<*ms.begin()<<'\n';
    }
    else
    { 
        do
        {
            lli a1=*ms.begin();
            ms.erase(ms.begin());

            lli a2=*ms.begin();
            ms.erase(ms.begin());

            ms.insert(a1+a2);
            
            b.push_back(a1+a2);
        } while (ms.size() != 1);

        lli ans=0;
        for (auto x1 : b)
        {
            ans+=x1;
        }
        cout<<ans<<'\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;cin>>t;while(t--)
    solve();
}