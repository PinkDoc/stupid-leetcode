// lc 97
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {

        if (s1.size() + s2.size() != s3.size()) return false;

        vector<vector<bool>> dp(s1.size() + 1, vector<bool>(s2.size() + 1, false));
        dp[0][0] = true;
        
        for (auto i = 0; i <= s1.size(); ++i)
        for (auto j = 0; j <= s2.size(); ++j)
        {
            if (i > 0)
            {
                auto ok =  (dp[i-1][j] && s1[i-1] == s3[i+j-1]);
                dp[i][j] = ok ? ok : dp[i][j];
            }
            if (j > 0)
            {
                auto ok =  (dp[i][j-1] && s2[j-1] == s3[j+i-1]);
                dp[i][j] = ok ? ok : dp[i][j];
            }
            
        }

        return dp.back().back();
    }
};
