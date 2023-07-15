#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
const lli mod = 1000000007;
const int N = 1000000;
lli Kp[N + 1];
lli inverse[N + 1];

void powers(lli k)
{
    Kp[0] = 1;
    for (int i = 1; i <= N; i++)
    {
        Kp[i] = (Kp[i - 1] * k) % mod;
    }
}
lli mult(lli a, lli b)
{
    lli ans = (a * b) % mod;

    return ans;
}

lli b_e(lli a, lli b)
{
    if (b == 0)
    {
        return 1;
    }
    else if (b == 1)
    {
        return a;
    }
    else if (b % 2 != 0)
    {
        return mult(a, b_e(a, b - 1));
    }
    else
    {
        int temp = b_e(a, b / 2);
        return mult(temp, temp);
    }
}
void inv(lli k)
{
    inverse[N] = b_e(Kp[N], mod - 2);
    for (int i = N - 1; i >= 0; i--)
    {
        inverse[i] = (inverse[i + 1] * k) % mod;
    }
}
int main()
{
    lli n, q, i, k;
    cin >> n >> q >> k;
    lli a[n + 1];
    lli b[n + 1];
    lli p[n + 1];
    lli x = 0;
    lli f = 0;
    a[0] = 0;
    p[0] = 0;
    inv(k);
    powers(k);
    for (i = 1; i <= n; i++)
    {
        cin >> a[i];
        p[i] = ((p[i - 1] + (a[i]) * Kp[i]) % mod) % mod;
    }
    while (q--)
    {
        lli l, r;
        cin >> l >> r;
        lli ans = ((p[r] - p[l - 1]) * inverse[l]) % mod;
        if (((p[r] - p[l - 1]) * inverse[l]) % mod < 0)
        {
            cout << ((p[r] - p[l - 1]) * inverse[l]) % mod + mod;
            cout << "\n";
        }
        else
        {
            cout << ((p[r] - p[l - 1]) * inverse[l]) % mod;
            cout << "\n";
        }
    }
}
// #include<bits/stdc++.h>
// using namespace std;

// using lli = long long int;
// const lli mod = 1000000007;

// const int N=1000000;
// lli Kpowers[N+1];
// lli invKpowers[N+1];

// void powers(lli k)
// {
//     Kpowers[0]=1;
//     for(int i=1;i<=N;i++)
//     {
//         Kpowers[i]= (Kpowers[i-1]*k)%mod;
//     }
// }
// lli Bin_Mul(lli a,lli b)
// {
//     lli ans=1;
//     while(b)
//     {
//         if(b%2==1)
//         {
//             ans = (ans*a)%mod;
//         }
//         a = (a*a)%mod;
//         b/=2;
//     }
//     return ans;
// }
// void inverse(lli k)
// {
//     invKpowers[N]=Bin_Mul(Kpowers[N],mod-2);
//     for(int i=N-1;i>=0;i--)
//     {
//         invKpowers[i]= (invKpowers[i+1]*k)%mod;
//     }
// }

// void solve()
// {
//     lli n,q,k;cin>>n>>q>>k;
//     powers(k);
//     inverse(k);
//     vector<lli> v(n);
//     for(int i=0;i<n;i++)
//     {
//         cin>>v[i];
//     }
//     vector<lli> pref(n+1,0);
//     for(int i=1;i<=n;i++)
//     {
//         pref[i] = (pref[i-1] + (v[i-1]*Kpowers[i])%mod)%mod;
//     }
//     while(q--)
//     {
//         lli l,r;
//         cin>>l>>r;
//         lli ans = ((pref[r]-pref[l-1])*invKpowers[l])%mod;
//         cout<< (ans%mod + mod)%mod<<"\n";
//     }
// }

// int main()
// {
//    /*  ios_base::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);

//     int t;cin>>t;while(t--) */
//     solve();
// }