#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using lli = long long int;

vector<char> segmentedSieve(lli L, lli R)
{
    // Generate all primes up to sqrt(R)
    lli lim = sqrt(R);
    vector<char> mark(lim + 1, false);
    vector<lli> primes;
    for (lli i = 2; i <= lim; ++i)
    {
        if (!mark[i])
        {
            primes.push_back(i);
            for (lli j = i * i; j <= lim; j += i)
                mark[j] = true;
        }
    }

    vector<char> isPrime(R - L + 1, true);
    for (lli prime : primes)
        for (lli j = max(prime * prime, (L + prime - 1) / prime * prime); j <= R; j += prime)
            isPrime[j - L] = false;
    if (L == 1)
        isPrime[0] = false;
    return isPrime;
}

void printPrimes(lli L, lli R)
{
    lli ans = 0;
    vector<char> isPrime = segmentedSieve(L, R);
    for (lli i = L; i <= R; ++i)
    {
        if (isPrime[i - L])
        {
            ans++;
        }
    }
    cout << ans << "\n";
    for (lli i = L; i <= R; ++i)
    {
        if (isPrime[i - L])
        {
            cout << i << " ";
        }
    }
    cout << "\n";
}

int main()
{
    lli L, R;
    cin >> L >> R;
    printPrimes(L, R);
    return 0;
}
