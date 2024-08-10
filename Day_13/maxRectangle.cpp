
class Solution{
    
    int area(vector<int>& v){
        int n = v.size();
        // use stacks
        stack<int> st;
        vector<int> nse(n, n), pse(n, -1);
        for(int i = 0; i < n; i++){
            while(!st.empty() and v[st.top()] >= v[i]) st.pop();
            if(!st.empty()) pse[i] = st.top();
            st.push(i);
        }
        
        while(!st.empty()) st.pop();
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() and v[st.top()] >= v[i]) st.pop();
            if(!st.empty()) nse[i] = st.top();
            st.push(i);
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans = max(ans, (nse[i] - pse[i] - 1) * v[i]);
        }
        return ans;
    }
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for(int j = 0; j < m; j++) dp[0][j] = M[0][j];
        
        int ans = area(dp[0]);
        
        for(int i = 1; i < n; i++){
            for(int j = 0; j < m; j++){
                dp[i][j] = dp[i - 1][j] + 1;
                if(M[i][j] == 0) dp[i][j] = 0;
            }
            ans = max(ans, area(dp[i]));
        }
        return ans;
    }
};