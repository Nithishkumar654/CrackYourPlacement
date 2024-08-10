class Solution{
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat) {
        // code here
        
        auto dfs = [&](auto&dfs, int i, int j){
            if(i < 0 or i >= n or j < 0 or j >= m) return;
            if(mat[i][j] != 'O') return;
            mat[i][j] = '1';
            dfs(dfs, i + 1, j);
            dfs(dfs, i - 1, j);
            dfs(dfs, i, j + 1);
            dfs(dfs, i, j - 1);
        };
        
        for(int i = 0; i < n; i++){
            if(mat[i][0] == 'O') dfs(dfs, i, 0);
            if(mat[i][m - 1] == 'O') dfs(dfs, i, m - 1);
        }
        
        for(int j = 0; j < m; j++){
            if(mat[0][j] == 'O') dfs(dfs, 0, j);
            if(mat[n - 1][j] == 'O') dfs(dfs, n - 1, j);
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 'O') mat[i][j] = 'X';
                if(mat[i][j] == '1') mat[i][j] = 'O';
            }
        }
        return mat;
    }
};