// 买卖股票的最佳时机 II

class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int ret = 0;

        auto m = prices[0];

        for (auto i : prices)
        {
            if (m > i)
            {
                m = i;
            }
            else
            {
                ret += (i - m);
                m = i;
            }
        }
        
        return ret; 
    }
};