class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        string s;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        auto dfs = [&](auto&dfs, int i, int j, int k) -> bool {
            if(k == word.size()) return true;
            if(i < 0 or i >= n or j < 0 or j >= m) return false;
            if(vis[i][j]) return false;
            if(board[i][j] != word[k]) return false;
            vis[i][j] = true;
            int dx[] = {-1, 0, 0, 1};
            int dy[] = {0, -1, 1, 0};
            for(int t = 0; t < 4; t++){
                if(dfs(dfs, i + dx[t], j + dy[t], k + 1)) {
                    vis[i][j] = false;
                    return true;
                }
            }
            vis[i][j] = false;
            return false;
        };

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == word[0] and dfs(dfs, i, j, 0)) return true;
            }
        }

        return false;
    }
};