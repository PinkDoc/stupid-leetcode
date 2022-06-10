class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;
        int n = s.length();
        vector<int> dp(n + 1, 1);
        vector<int> last(26, -1);

        for (int i = 0; i < n; ++i) {
            int x = s[i] - 'a';
            dp[i + 1] = dp[i] * 2 % MOD;
            if (last[x] >= 0) dp[i + 1] -= dp[last[x]];
            dp[i + 1] %= MOD;
            last[x] = i;
        }

        --dp[n];
        return (dp[n] < 0) ? (dp[n] + MOD) : dp[n];
    }
};
