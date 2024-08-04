class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 1e9));
        dp[0][0] = 0;
        for(int i = 0; i <= amount; i++){
            if(i >= coins[0]) dp[0][i] = min(dp[0][i], dp[0][i - coins[0]] + 1);
        }
        for(int i = 1; i < n; i++){
            for(int j = 0; j <= amount; j++){
                dp[i][j] = min(dp[i][j], dp[i - 1][j]);
                if(j - coins[i] >= 0) dp[i][j] = min(dp[i][j], dp[i][j - coins[i]] + 1);
            }
        }
        if(dp[n - 1][amount] == 1e9) return -1;
        return dp[n - 1][amount];
    }
};