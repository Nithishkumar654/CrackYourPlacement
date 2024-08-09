class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        map<string, vector<string>> mp;
        for(auto &s : string_list){
            string str = s;
            sort(str.begin(), str.end());
            mp[str].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto &it : mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};