class Solution {
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        
        auto dfs = [&](auto& dfs, int i, int j){
            
            if(i < 0 or i >= n or j < 0 or j >= m) return;
            if(grid[i][j] == '0') return;
            grid[i][j] = '0';
            int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
            int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
            for(int t = 0; t < 8; t++){
                dfs(dfs, i + dx[t], j + dy[t]);
            }
        };
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1') {
                    ans++;
                    dfs(dfs, i, j);
                }
            }
        }
        return ans;
    }
};