// this is the code for updating the values from l to r  and finding the sum from l to r

#include <bits/stdc++.h>
using namespace std;
using lli = long long;
vector<lli> a;
vector<lli> t;

void build(lli index, lli l, lli r)
{
    if (l == r)
    {
        t[index] = a[l]; // leaf node
        return;
    }
    lli mid = (l + r) / 2;
    build(index * 2, l, mid);         // left tree
    build(index * 2 + 1, mid + 1, r); // right tree
    t[index] = t[2 * index] + t[2 * index + 1];
}

void update(lli index, lli l, lli r, lli pos, lli val)
{
    if (pos < l || pos > r)
    {
        return;
    }
    if (l == r)
    {
        t[index] = val; // updating
                        //   a[l - 1] = val;
        return;
    }
    lli mid = (l + r) / 2;
    update(index * 2, l, mid, pos, val);
    update(index * 2 + 1, mid + 1, r, pos, val);
    t[index] = t[2 * index] + t[2 * index + 1];
}

lli query(lli index, lli l, lli r, lli lq, lli rq)
{
    if (l > rq || lq > r)
    {
        return 0;
    }
    if (lq <= l && r <= rq)
    {
        map<int, int> freq;
        freq[t[index]]++; // Count the frequency of the element at the current node
        
        // Merge the frequencies of the left and right child nodes
        if (l != r) {
            freq += freq[t[2 * index]];
            freq += freq[t[2 * index + 1]];
        }
        
        lli count = 0;
        for (const auto& [element, frequency] : freq) {
            if (frequency % 2 != 0) {
                count++;
            }
        }
        
        return count;
    }
    
    lli mid = (l + r) / 2;
    lli leftCount = query(index * 2, l, mid, lq, rq);
    lli rightCount = query(index * 2 + 1, mid + 1, r, lq, rq);
    return leftCount + rightCount;
}



void solve()
{
    lli n, q;
    cin >> n >> q;
    a.resize(n + 1);
    t.resize(4 * n + 1);

    for (lli i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    build(1, 0, n - 1);
    while (q--)
    {
        lli ch;
        cin >> ch;
        if (ch == 1)
        {
            lli x, v;
            cin >> x >> v;
            update(1, 0, n - 1, x - 1, v);
        }
        else
        {
            lli l, r;
            cin >> l >> r;
             lli oddCount = 0;
            lli result = query(1, 0, n - 1, l - 1, r - 1);
            cout << result << endl;
        }
    }
}

int main()
{
    solve();
}