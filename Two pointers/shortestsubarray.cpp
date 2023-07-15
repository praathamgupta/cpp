#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
typedef long long LL;

void solve()
{
  int n, k;
  cin >> n;
  vector<int> arr(n);
  map<int, int> mp;
  set<int> s;
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
    mp[arr[i]] = 0;
    s.insert(arr[i]);
  }
  k = (int)s.size();

  long long int ans = 1e18;
  long long int head = -1;
  long long int tail = 0;
  long long int cnt = 0;

  while (tail < n)
  {
    while ((head + 1 < n) && ((cnt + 1 <= k)))
    {
      head++;
      mp[arr[head]]++;
      if (mp[arr[head]] == 1)
      {
        cnt++;
      }
    }
    if (cnt == k)
    {
      ans = min(ans, (head - tail + 1));
    }

    if (tail <= head)
    {
      mp[arr[tail]]--;
      if (mp[arr[tail]] == 0)
      {
        cnt--;
      }
      tail++;
    }
    else
    {
      tail++;
      head = tail - 1;
    }
  }

  cout << ans << endl;
}
signed main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}