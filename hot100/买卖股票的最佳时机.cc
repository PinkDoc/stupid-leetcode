// 买卖股票的最佳时机
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m = prices[0];
        int ret = 0;
        for (auto i : prices)
        {
            ret = max(ret, i - m);
            m = min(i, m);
        }

        return ret;
    }
};