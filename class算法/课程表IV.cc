// lc 1462 floyd
class Solution {
public:
  int a[101][101];
  vector<bool> checkIfPrerequisite(int n, vector<vector<int>> &nums,
                                   vector<vector<int>> &b) {
    for (auto num : nums) {
      int l = num[0], r = num[1];
      a[l][r] = 1;
    }
    for (int k = 0; k < n; ++k)
      for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
          if (a[i][k] && a[k][j])
            a[i][j] = 1;

    vector<bool> res;
    for (auto b : b)
      res.push_back(a[b[0]][b[1]]);
    return res;
  }
};