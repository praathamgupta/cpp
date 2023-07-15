#include <bits/stdc++.h>
using namespace std;
using lli = long long int;

struct MinStack
{
    stack<lli> s;
    multiset<lli> m;

    void push(lli x)
    {
        s.push(x);
        m.insert(x);
    }
    void pop()
    {
        if (!s.empty())
        {
            lli t = s.top();
            s.pop();
            m.erase(m.find(t));
        }
    }
    lli top()
    {
        if (!s.empty())
        {
            return s.top();
        }
        else
        {
            return -1;
        }
    }
    lli getMin()
    {
        if (!s.empty())
        {
            return *m.begin();
        }
        else
        {
            return -1;
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin >> q;

    MinStack s;

    while (q--)
    {
        string op;
        cin >> op;

        if (op == "push")
        {
            int x;
            cin >> x;
            s.push(x);
        }
        else if (op == "pop")
        {
            s.pop();
        }
        else if (op == "top")
        {
            cout << s.top() << "\n";
        }
        else if (op == "getMin")
        {
            cout << s.getMin() << "\n";
        }
    }

    return 0;
}