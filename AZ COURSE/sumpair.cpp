#include <bits/stdc++.h>
using namespace std;

class FindPairswithSum
{
    vector<int> v1,v2;
    map<int,int> freqB;
public:
    //CONSTRUCTOR
    FindPairswithSum(vector<int> &A, vector<int> &B)
    {
        v1=A;
        v2=B;
        for(auto i:B)
        {
            freqB[i]++;
        }
    }

    void add(int index, int val)
    {
        freqB[v2[index]]--;        
        v2[index]+=val;
        freqB[v2[index]]++;
    }

    int count(int total)
    {
        int ans = 0;
        for( auto i:v1)
        {
            if( freqB.find(total - i)!=freqB.end() )
            {
                ans += freqB[total - i];
            }
        }
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, q;
    cin >> n >> m >> q;

    vector<int> A(n), B(m);

    for (auto &i : A)
    {
        cin >> i;
    }

    for (auto &i : B)
    {
        cin >> i;
    }

    FindPairswithSum *obj = new FindPairswithSum(A, B);

    for (int i = 0; i < q; i++)
    {
        string op;
        cin >> op;
        if (op == "add")
        {
            int index, val;
            cin >> index >> val;
            obj->add(index, val);
        }
        else
        {
            int total;
            cin >> total;
            cout << obj->count(total) << '\n';
        }
    }

    return 0;
}