class Solution {
public:
    const int M = 1e9 + 7;
    int add(int a, int b, int mod){
        a %= mod; b %= mod;
        return (a + 0ll + b) % mod;
    }
    bool check(int i, int j){
        return ((i >= 0 and i < 3 and j >= 0 and j < 3) or (i == 3 and j == 1));
    }
    int solve(int i, int j, int k, vector<vector<vector<int>>>& dp){
        if(k == 0) return 1;
        if(dp[i][j][k] != -1) return dp[i][j][k];
        int ans = 0;
        if(check(i + 1, j + 2)) ans = add(ans, solve(i + 1, j + 2, k - 1, dp), M);
        if(check(i + 1, j - 2)) ans = add(ans, solve(i + 1, j - 2, k - 1, dp), M);
        if(check(i - 1, j + 2)) ans = add(ans, solve(i - 1, j + 2, k - 1, dp), M);
        if(check(i - 1, j - 2)) ans = add(ans, solve(i - 1, j - 2, k - 1, dp), M);

        if(check(i + 2, j + 1)) ans = add(ans, solve(i + 2, j + 1, k - 1, dp), M);
        if(check(i + 2, j - 1)) ans = add(ans, solve(i + 2, j - 1, k - 1, dp), M);
        if(check(i - 2, j + 1)) ans = add(ans, solve(i - 2, j + 1, k - 1, dp), M);
        if(check(i - 2, j - 1)) ans = add(ans, solve(i - 2, j - 1, k - 1, dp), M);

        return dp[i][j][k] = ans;
    }
    int knightDialer(int n) {
        int ans = 0;
        vector<vector<vector<int>>> dp(4, vector<vector<int>>(4, vector<int>(n, -1)));
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                ans = add(ans, solve(i, j, n - 1, dp), M);
            }
        }
        ans = add(ans, solve(3, 1, n - 1, dp), M);
        return ans;
    }
};