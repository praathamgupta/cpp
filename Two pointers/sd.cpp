#include<bits/stdc++.h>


using namespace std;

int findSubarrays(vector<int> arr, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int minEle = arr[i];
        int maxEle = arr[i];
        for (int j = i + 1; j < n; j++)
        {
            minEle = min(minEle, arr[j]);
            maxEle = max(maxEle, arr[j]);
            if ((minEle * maxEle) % (j - i + 1) == 0)
            {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int count = findSubarrays(arr, n);
        cout << n+ count << endl;
    }
    return 0;
}