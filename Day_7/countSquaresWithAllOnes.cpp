class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int ans = 0, n = matrix.size(), m = matrix[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i > 0) matrix[i][j] += matrix[i - 1][j];
                if(j > 0) matrix[i][j] += matrix[i][j - 1];
                if(i > 0 and j > 0) matrix[i][j] -= matrix[i - 1][j - 1];

                for(int k = 1; k <= min(i, j) + 1; k++){
                    int tl_x = i - k, tl_y = j - k;
                    int sum = matrix[i][j];
                    if(tl_x >= 0) sum -= matrix[tl_x][j];
                    if(tl_y >= 0) sum -= matrix[i][tl_y];
                    if(tl_x >= 0 and tl_y >= 0) sum += matrix[tl_x][tl_y];
                    ans += (sum == k * k);
                }
            }
        }
        return ans;
    }
};