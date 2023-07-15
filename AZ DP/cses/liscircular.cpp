int lis(vector<int>& a, int start, int end) {
    vector<int> ans;
    ans.push_back(a[start]);
    
    for (int i = start + 1; i <= end; i++) {
        if (a[i] > ans.back()) {
            ans.push_back(a[i]);
        } else {
            int index = lower_bound(ans.begin(), ans.end(), a[i]) - ans.begin();
            ans[index] = a[i];
        }
    }
    
    return ans.size();
}

int lisInCircularManner(int n, vector<int>& arr) {
    n = arr.size();
    arr.resize(2 * n);
    for (int i = n; i < 2 * n; i++) {
        arr[i] = arr[i - n];
    }
    
    int res = -1;
    for (int i = 0; i < n; i++) {
        res = max(res, lis(arr, i, i + n - 1));
    }
 
    return res;
}
