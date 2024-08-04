class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans = 0, n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> grid(n, vector<int>(m, 0));

        auto isSquare = [&](int i, int j, int k){
            int tl_x = i - k, tl_y = j - k;
            int sum = grid[i][j];
            if(tl_x >= 0) sum -= grid[tl_x][j];
            if(tl_y >= 0) sum -= grid[i][tl_y];
            if(tl_x >= 0 and tl_y >= 0) sum += grid[tl_x][tl_y];
            return sum == k * k;
        };

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                grid[i][j] = matrix[i][j] - '0';
                if(i > 0) grid[i][j] += grid[i - 1][j];
                if(j > 0) grid[i][j] += grid[i][j - 1];
                if(i > 0 and j > 0) grid[i][j] -= grid[i - 1][j - 1];

                int l = 0, h = min(i, j) + 1;

                while(l < h){
                    int mid = (l + h + 1) >> 1;
                    if(isSquare(i, j, mid)) l = mid;
                    else h = mid - 1;
                }
                ans = max(ans, l);
            }
        }
        return ans * ans;
    }
};