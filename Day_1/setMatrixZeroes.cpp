class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int row = 0, col = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 0){
                    if(i == 0) row = 1;
                    if(j == 0) col = 1;
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if(matrix[0][j] == 0 or matrix[i][0] == 0) matrix[i][j] = 0;
            }
        }
        if(row){
            for(int i = 0; i < m; i++) matrix[0][i] = 0;
        }
        if(col){
            for(int i = 0; i < n; i++) matrix[i][0] = 0;
        }
    }
};