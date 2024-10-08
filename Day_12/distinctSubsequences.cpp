class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.length(), m = t.length();
        if(t.length() >= s.length()) return t == s;
        vector<vector<unsigned long long int>> dp(n + 1, vector<unsigned long long int>(m + 1, 0));

        // dp[i][j]: number of subseq = t[0:j] in s[0:i]
        dp[0][0] = 1;
        for(int i = 1; i <= n; i++){
            dp[i][0] = 1;
            for(int j = 1; j <= m; j++){
                if(s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][m];
    }
};