/*
	小红拿到了一个数组，她想取一些数使得取的数之和尽可能大，但要求这个和必须是 k\k  的倍数。
	你能帮帮她吗？
*/

#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;


int main() {
	int n, k;
	cin >> n >> k;
	
	vector<int> input;
	
	for (auto i = 0 ;  i < n; ++i)
	{
		int temp;
		cin >> temp;
		input.push_back(temp);
	}
    
    input.push_back(0);
	
	vector<vector<int>> dp(n + 1, vector<int>(k, -1));
		
	// i , j 表示 前i个数, 余数为j的最大值
	// dp (i, [a[i] + j] % k) = dp(i, j) + a[i]
	dp[0][0] = 0;
	for (int i = 1; i < n + 1; ++i)
	{
		for (int j = 0; j < k; ++j)
		{
			dp[i][((input[i] + j) % k)] = max(dp[i - 1][j] + input[i], dp[i - 1][((input[i] + j) % k)]);
		}
	}
	
	int temp = -1;
	
	temp = max(temp, dp[n][0]);
    
    if (temp <= 0) temp = -1;
    
	cout << temp;
	
}
