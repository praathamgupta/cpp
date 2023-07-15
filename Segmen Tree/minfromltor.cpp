#include <bits/stdc++.h>
using namespace std;
using lli = long long;
vector<lli> a;
vector<lli> t;
node t[400000];
struct node
{
    int mini;
    int cnt;
    node(int m = 1e9, int c = 0)
    {
        mini = m;
        cnt = c;
    }
};

node merge(node a, node b)
{
    if (a.mini = b.mini)
    {
        return node(a.mini, a.cnt + b.cnt);
    }
    else if (a.mini < b.mini)
    {
        return a;
    }
    else{
        return b;
    }
}
void build(lli index, lli l, lli r)
{
    if (l == r)
    {
        t[index] = node(a[l], 1); // leaf node
        return;
    }
    lli mid = (l + r) / 2;
    build(index * 2, l, mid);         // left tree
    build(index * 2 + 1, mid + 1, r); // right tree
    t[index] = merge(t[2 * index] + t[2 * index + 1]);
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
        // lq<=l<=r<=rq
        return t[index]; // i have to take everything
    }
    lli mid = (l + r) / 2;
    return query(index * 2, l, mid, lq, rq) + query(index * 2 + 1, mid + 1, r, lq, rq);
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
            cout << query(1, 0, n - 1, l - 1, r - 1) << "\n";
        }
    }
}

int main()
{
    solve();
}