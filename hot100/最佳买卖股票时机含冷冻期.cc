// 309. 最佳买卖股票时机含冷冻期
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        auto size = prices.size();
        vector<vector<int>> dp(size, vector<int>(3, 0));

        dp[0][0] = -prices[0];
        
        for (auto i = 1; i < size; ++i)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - prices[i]);
            dp[i][1] = dp[i - 1][0] + prices[i];
            dp[i][2] = max(dp[i - 1][1] , dp[i - 1][2]);
        }

        return max(dp[size - 1][1], dp[size - 1][2]);
    }
};