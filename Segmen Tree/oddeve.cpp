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
        t[index] = val % 2; // updating
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
        // lq<=l<=r<=rq
        return t[index]; // i have to take everything
    }
    lli mid = (l + r) / 2;
    return query(index * 2, l, mid, lq, rq) + query(index * 2 + 1, mid + 1, r, lq, rq);
}

void solve()
{
    lli n;
    cin >> n;

    a.resize(n + 1);
    t.resize(4 * n + 1);

    for (lli i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i] = a[i] % 2;
    }
    lli q;
    cin>>q;
    build(1, 0, n - 1);
    while (q--)
    {
        lli ch;
        cin >> ch;
        if (ch == 0)
        {
            lli x, v;
            cin >> x >> v;
            update(1, 0, n - 1, x - 1, v);
        }
        else
        {
            lli l, r;
            cin >> l >> r;
            if (ch == 1)
            {
                cout << (r - l + 1) - query(1, 0, n - 1, l - 1, r - 1) << "\n";
            }
            else
            {
                cout << query(1, 0, n - 1, l - 1, r - 1) << "\n";
            }
        }
    }
}

int main()
{
    solve();
}