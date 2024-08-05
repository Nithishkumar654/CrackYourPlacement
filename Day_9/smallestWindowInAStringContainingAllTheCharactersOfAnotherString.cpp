class Solution {
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p) {
        // Your code here
        vector<int> freqp(26, 0), freqs(26, 0);
        for(char c : p) freqp[c - 'a']++;
        int i = 0, j = 0;
        int ans = INT_MAX;
        int n = s.length();
        int cnt = 0;
        int start = -1, end = 0;
        for(int x : freqp) if(x > 0) cnt++;
        while(j < n){
            while(cnt > 0 and j < n){
                freqs[s[j] - 'a']++;
                if(freqs[s[j] - 'a'] == freqp[s[j] - 'a']) cnt--;
                j++;
            }
            while(i < j and cnt == 0){
                if(ans > j - i){
                    ans = j - i;
                    end = j; start = i;
                }
                freqs[s[i] - 'a']--;
                if(freqs[s[i] - 'a'] == freqp[s[i] - 'a'] - 1) cnt++;
                i++;
            }
        }
        if(start == -1) return "-1";
        return s.substr(start, end - start);
    }
};