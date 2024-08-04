class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size(), M = 1e9 + 7;
        vector<vector<int>> hash(n);
        vector<int> powers(201, 0);
        int prime = 31;
        powers[0] = prime;
        for(int i = 1; i < 200; i++){
            powers[i] = (powers[i - 1] * 1LL * prime) % M;
        }
        int mn = strs[0].length();
        for(int i = 0; i < n; i++){
            mn = min(mn, (int)strs[i].length());
            int h = 0; hash[i].resize(strs[i].length());
            for(int j = 0; j < strs[i].length(); j++){
                h = (h + ((strs[i][j] - 'a' + 1) * 1LL * powers[j]) % M) % M;
                hash[i][j] = h;
            }
        }

        auto common = [&](int mid){
            if(mid == 0) return true;
            for(int i = 1; i < n; i++){
                if(hash[i][mid - 1] != hash[i - 1][mid - 1]) return false;
            }
            return true;
        };

        int l = 0, h = mn;
        while(l < h){
            int mid = (l + h + 1) >> 1;
            if(common(mid)) l = mid;
            else h = mid - 1;
        }
        return strs[0].substr(0, l);
    }
};