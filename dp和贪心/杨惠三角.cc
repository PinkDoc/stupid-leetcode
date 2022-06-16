// lc 118
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        int level = 0;
        while (numRows--)
        {
            ret.emplace_back(++level, 1);
            for (auto i = 1; i < level - 1; ++i)
            {
                ret[level - 1][i] = ret[level-2][i-1] + ret[level - 2][i];
            }
        }

        return ret;
    }
};
