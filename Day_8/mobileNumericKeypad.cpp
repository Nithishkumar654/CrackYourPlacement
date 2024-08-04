class Solution {
  public:
    long long getCount(int n) {
        // Your code goes here
        vector<vector<vector<long long>>> dp(4, vector<vector<long long>>(4, vector<long long>(n + 1, -1)));
        
        auto solve = [&](auto& solve, int i, int j, int n){
            
            if(n == 1) return 1ll;
            
            if(dp[i][j][n] != -1) return dp[i][j][n];
            
            long long ans = 0;
            if(i < 2 or (i == 2 and j == 1)) ans += solve(solve, i + 1, j, n - 1);
            if(j < 2 and !(i == 3 and j == 1)) ans += solve(solve, i, j + 1, n - 1);
            if(i > 0) ans += solve(solve, i - 1, j, n - 1);
            if(j > 0 and !(i == 3 and j == 1)) ans += solve(solve, i, j - 1, n - 1);
            ans += solve(solve, i, j, n - 1);
            return dp[i][j][n] = ans;
        };
        
        long long ans = 0;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                ans += solve(solve, i, j, n);
            }
        }
        ans += solve(solve, 3, 1, n);
        return ans;
    }
};