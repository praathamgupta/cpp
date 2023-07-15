#include <iostream>
#include <vector>
using lli=long long int;
using namespace std;

vector<lli> karatsuba(vector<lli> &a, vector<lli> &b)
{
    lli n = a.size();
    vector<lli> result(2 * n);

    if (n <= 32)
    { // base case
        for (lli i = 0; i < n; i++)
        {
            for (lli j = 0; j < n; j++)
            {
                result[i + j] += a[i] * b[j];
            }
        }
        return result;
    }

    lli k = n / 2;

    vector<lli> a0(a.begin(), a.begin() + k);
    vector<lli> a1(a.begin() + k, a.end());
    vector<lli> b0(b.begin(), b.begin() + k);
    vector<lli> b1(b.begin() + k, b.end());

    vector<lli> c0 = karatsuba(a0, b0);
    vector<lli> c1 = karatsuba(a1, b1);

    for (lli i = 0; i < k; i++)
    {
        a1[i] += a0[i];
        b1[i] += b0[i];
    }

    vector<lli> c2 = karatsuba(a1, b1);
    for (lli i = 0; i < n; i++)
    {
        c2[i] -= c0[i] + c1[i];
    }

    for (lli i = 0; i < n; i++)
    {
        result[i] += c0[i];
        result[i + n] += c1[i];
        result[i + k] += c2[i];
    }

    return result;
}

int main()
{
    lli t;
    cin >> t;
    while (t--)
    {
        lli n;
        cin >> n;

        vector<lli> a(n + 1);
        vector<lli> b(n + 1);

        for (lli i = 0; i <= n; i++)
        {
            cin >> a[i];
        }

        for (lli i = 0; i <= n; i++)
        {
            cin >> b[i];
        }

        vector<lli> c = karatsuba(a, b);
        for (lli i = 0; i <= 2 * n; i++)
        {
            cout << c[i] << " ";
        }
        cout << endl;

    }
    return 0;
}