class Solution {
public:
    bool validPalindrome(string s) {
        int i = 0, j = s.length() - 1;
        while(i < j and s[i] == s[j]) i++, j--;
        int a = i, b = j;
        i++;
        while(i < j and s[i] == s[j]) i++, j--;
        if(i >= j) return true;
        i = a; j = b;
        j--;
        while(i < j and s[i] == s[j]) i++, j--;
        return i >= j; 
    }
};