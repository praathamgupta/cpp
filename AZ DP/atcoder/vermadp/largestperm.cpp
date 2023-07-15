#include <bits/stdc++.h>
using namespace std;

vector<int> largestLexicographicalArray(int n, int b, vector<int>& a) {
    int count = 0;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            count++;
        }
    }

    if (count == n - 1) {
        return a;
    }
    else {
        sort(a.begin(), a.end());
        for (int i = 0; i < min(b, n - 1); i++) {
            swap(a[n - i - 1], a[i]);
        }
        return a;
    }
}

int main() {
    int n, b;
    cin >> n >> b;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> result = largestLexicographicalArray(n, b, a);

    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }

    return 0;
}
