class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length(), m = needle.length();
        for(int i = 0; i <= n - m; i++){
            int l = 0;
            for(int j = 0; j < m; j++){
                if(needle[j] != haystack[i + j]) break;
                l++;
            }
            if(l == m) return i;
        }
        return -1;
    }
};