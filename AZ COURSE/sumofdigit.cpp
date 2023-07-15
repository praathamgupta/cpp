#include <iostream>
using namespace std;

int *GetBigInteger(string str)
{
    int x = str.size(), a = 0;
    int *arr = new int[str.size()];
    while (a != x)
    {
        arr[a] = str[a] - '0';
        a++;
    }
    return arr;
}
void solve()
{
    string str;
    cin >> str;
    int sum = 0;
    int *arr = GetBigInteger(str);
    for (int i = 0; i < str.size(); i++)
    {
        sum = sum + arr[i];
    }
    cout << sum;
    cout << "\n";
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}