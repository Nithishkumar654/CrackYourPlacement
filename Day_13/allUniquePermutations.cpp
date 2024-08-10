
class Solution {
  public:
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        // code here
        sort(arr.begin(), arr.end());
        set<vector<int>> ans;
        vector<int> perm, vis(n, 0);
        
        auto permute = [&](auto& permute) -> void {
            if(perm.size() == n){
                ans.insert(perm);
                return;
            }
            
            for(int i = 0; i < n; i++){
                if(vis[i]) continue;
                vis[i] = true;
                perm.push_back(arr[i]);
                permute(permute);
                perm.pop_back();
                vis[i] = false;
            }
        };
        
        permute(permute);
        vector<vector<int>> permutations(ans.begin(), ans.end());
        return permutations;
    }
};