class Solution {
public:
    string minWindow(string s, string p) {
        vector<int> freqp(130, 0), freqs(130, 0);
        for(char c : p) freqp[c]++;
        int i = 0, j = 0;
        int ans = INT_MAX;
        int n = s.length();
        int cnt = 0;
        int start = -1, end = 0;
        for(int x : freqp) if(x > 0) cnt++;
        while(j < n){
            while(cnt > 0 and j < n){
                freqs[s[j]]++;
                if(freqs[s[j]] == freqp[s[j]]) cnt--;
                j++;
            }
            while(i < j and cnt == 0){
                if(ans > j - i){
                    ans = j - i;
                    end = j; start = i;
                }
                freqs[s[i]]--;
                if(freqs[s[i]] == freqp[s[i]] - 1) cnt++;
                i++;
            }
        }
        if(start == -1) return "";
        return s.substr(start, end - start);
    }
};