class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz = strs.size();
        vector<vector<int>> v(sz, vector<int>(2, 0));
        for(int i = 0; i < sz; i++){
            for(char c : strs[i]){
                v[i][c - '0']++;
            }
        }
        vector<vector<vector<int>>> dp(sz, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
        // dp[i][j][k] = if it is possible to get atmost j zeros and k ones until index i
        dp[0][0][0] = 0;
        if(v[0][0] <= m and v[0][1] <= n) dp[0][v[0][0]][v[0][1]] = 1;
        for(int i = 1; i < sz; i++){
            for(int j = 0; j <= m; j++){
                for(int k = 0; k <= n; k++){
                    dp[i][j][k] = dp[i - 1][j][k];
                    if(j - v[i][0] >= 0 and k - v[i][1] >= 0){
                        dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - v[i][0]][k - v[i][1]] + 1);
                    }
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < sz; i++){
            for(int j = 0; j <= m; j++){
                ans = max(ans, *max_element(dp[i][j].begin(), dp[i][j].end()));
            }
        }
        return ans;
    }
};