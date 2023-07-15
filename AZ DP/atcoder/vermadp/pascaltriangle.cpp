class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex+1), prev(rowIndex+1);

        for (int i=0; i<=rowIndex; i++) {
            for (int j=0; j<=i; j++)
                // calculation for the current row
                if (j==0 or j==i) ans[j] = 1;
                else ans[j] = prev[j] + prev[j-1]; 
                
            prev = ans; // update previous with current value in ans
        }

        return ans;
    }
};


class Solution {
 public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans;

    for (int i = 0; i < numRows; ++i)
      ans.push_back(vector<int>(i + 1, 1));

    for (int i = 2; i < numRows; ++i)
      for (int j = 1; j < ans[i].size() - 1; ++j)
        ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];

    return ans;
  }
};