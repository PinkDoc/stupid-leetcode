// leetcode 516


class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int ret = 1;

        auto size = s.size();

        vector<vector<int>> dp(size, vector<int>(size, 0));

        for (auto i = 0; i < size; ++i)
        {
            dp[i][i] = 1;
        }

        for (int i = size - 2; i >= 0; --i)
        for (auto j = i + 1 ; j < size; ++j)
        {
           
            dp[i][j] = s[i] == s[j] ? dp[i + 1][ j - 1] + 2 : max(dp[i + 1][j], dp[i][j - 1]);
            ret = max(ret, dp[i][j]);
        }


        return ret;
    }
};
