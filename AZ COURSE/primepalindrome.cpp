#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
const lli mod = 1000000007;
vector<int> is_prime;
vector<int> v;
// Time & Space complexity:  O( log(min(a,b)) )
void isPrime(int a, int b)
{
    for (int i = 2; i * i <= b; i++)
    {
        lli cur_mul = ((a + i - 1) / i) * i;
        while (cur_mul <= b)
        {
            if (cur_mul != i)
            {
                is_prime[cur_mul - a] = 0;
            }
            cur_mul += i;
        }
    }
    for (int i = 0; i <= b - a; i++)
    {
        if (is_prime[i])
            v.push_back(a + i);
    }
}
bool Palindrome(int n)
{
    int temp = n;
    int rev = 0; // 12345
    while (temp > 0)
    {
        int rem = temp % 10;
        rev = 10 * rev + rem;
        temp /= 10;
    }
    return n == rev;
}
void solve()
{
    int a, b;
    cin >> a >> b;
    lli count = 0;
    is_prime.clear();
    v.clear();

    // initialize is_prime vector
    is_prime.assign(b - a + 1, true);
    isPrime(a, b);
    for (int i = 0; i < v.size(); i++)
    {
        if (Palindrome(v[i]))
        {
            cout << v[i] << " ";
            count++;
        }
    }
    cout << "\n";

    cout << count;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int t;cin>>t;while(t--)
    solve();
}