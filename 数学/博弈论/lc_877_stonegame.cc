/*

	Alice 和 Bob 用几堆石子在做游戏。
	一共有偶数堆石子，排成一行；每堆都有 正 整数颗石子，数目为 piles[i] 。

	游戏以谁手中的石子最多来决出胜负。石子的 总数 是 奇数 ，所以没有平局。

	Alice 和 Bob 轮流进行，Alice 先开始 。 每回合，玩家从行的 开始 或 结束 处取走整堆石头。 这种情况一直持续到没有更多的石子堆为止，此时手中 石子最多 的玩家 获胜 。

	假设 Alice 和 Bob 都发挥出最佳水平，当 Alice 赢得比赛时返回 true ，当 Bob 赢得比赛时返回 false 。




来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/stone-game
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

// [1,3,4,5,4,9,3]

class Solution 
{
public:
	bool stoneGame(vector<int>& p) 
	{
		auto len = p.size();
		vector<vector<int>> dp(len, vector<int>()len, 0);
		
		for (auto i = 0; i < len; ++i)
		{
			dp[i][1] = p[i];
		}
		
		for (auto l = 1; l < len; ++i)
		{
			for (auto i = 0; i + l < len; ++i)
			{
				auto j = i + l;
				for (auto k = i; k < j; ++k)
				{
				
					// dp[i, j] =  max dp ij, dp
				
				}
			}
		}
	
	}
};
















