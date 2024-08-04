class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        auto solve = [&](auto& solve, int i, int j) -> int {
            if(i == m - 1 and j == n - 1) return 1;
            if(i >= m or i < 0 or j < 0 or j >= n) return 0;
            if(dp[i][j] != -1) return dp[i][j];
            return dp[i][j] = solve(solve, i, j + 1) + solve(solve, i + 1, j);
        };
        
        return solve(solve, 0, 0);
    }
};