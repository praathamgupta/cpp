// https://www.learning.algozenith.com/problems/Grading-System-AZ101-324
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        /* code */

        int mt, ft, mu;
        cin >> mt >> ft >> mu;
        if (mt == -1 || ft == -1)
        {
            cout << "F\n";
        }
        else
        {
            if (mt + ft >= 80)
            {
                cout << "A\n";
            }
            else if (mt + ft < 80 && mt + ft >= 65)
            {
                cout << "B\n";
            }
            else if (mt + ft < 65 && mt + ft >= 50)
            {
                cout << "C\n";
            }

            else if (mt + ft < 50 && mt + ft >= 30)
            {
                if (mu >= 50)
                {
                    cout << "C\n";
                }
                else
                {
                    cout << "D\n";
                }
            }
            else
            {
                cout << "F\n";
            }
        }
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}