#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, x;
    cin >> n >> x;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (n < 4)
    {
        cout << "NO" << endl;
        return 0;
    }
    set<int> st;
    st.insert(a[0] + a[1]);
    for (int i = 2; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (st.find(x - a[i] - a[j]) != st.end())
            {
                cout << "YES" << endl;
                return 0;
            }
        }
        for (int j = 0; j < i; j++)
        {
            st.insert(a[i] + a[j]);
        }
    }
    cout << "NO" << endl;
    return 0;
}