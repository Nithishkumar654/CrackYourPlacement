class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mp;
        for(auto &s : strs){
            string str = s;
            sort(str.begin(), str.end());
            mp[str].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto &[k, v] : mp) ans.push_back(v);
        return ans;
    }
};