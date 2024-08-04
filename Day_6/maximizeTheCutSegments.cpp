class Solution
{
    public:
    
    int solve(int n, vector<int>& v, vector<int>& dp){

        if(dp[n] != -1) return dp[n];
        
        int ans = 0;
        
        for(auto &x : v){
            ans = max(ans, (int)(n == x));
            if(n <= x) continue;
            int c1 = solve(x, v, dp);
            int c2 = solve(n - x, v, dp);
            if(c1 == 0 or c2 == 0) continue;
            ans = max(ans, c1 + c2);
        }
        
        return dp[n] = ans;
    }
    
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z) {
        //Your code here
        vector<int> dp(n + 1, -1);
        vector<int> v = {x, y, z};
        int ans = solve(n, v, dp);
        return ans;
    }
};