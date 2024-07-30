class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size(), n = matrix[0].size();
        int rb = 0, re = m - 1, cb = 0, ce = n - 1;
        int c = 0;
        while(c < m * n){
            for(int i = cb; i <= ce; i++) ans.push_back(matrix[rb][i]), c++;
            rb++;
            if(c == m * n) break;
            for(int i = rb; i <= re; i++) ans.push_back(matrix[i][ce]), c++;
            ce--;
            if(c == m * n) break;
            for(int i = ce; i >= cb; i--) ans.push_back(matrix[re][i]), c++;
            re--;
            if(c == m * n) break;
            for(int i = re; i >= rb; i--) ans.push_back(matrix[i][cb]), c++;
            cb++;
            if(c == m * n) break;
        }
        return ans;
    }
};