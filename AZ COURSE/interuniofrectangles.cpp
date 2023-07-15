#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x1, y1, x2, y2, x3, y3, x4, y4, x5, x6, y5, y6;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        x5 = max(x1, x3);
        x6 = min(x2, x4);
        y5 = max(y1, y3);
        y6 = min(y2, y4);
        long a_int = 0;
        long a_union = 0;

        if (x5 < x6 && y5 < y6)
        {
            a_int = abs((x6 - x5) * (y5 - y6));
        }

        a_union = abs((x1 - x2) * (y1 - y2)) + abs((x3 - x4) * (y3 - y4)) - a_int;

        cout << a_int << " " << a_union << "\n";
        (y6 - y5);
        // 2*2+2*3
    }
}
