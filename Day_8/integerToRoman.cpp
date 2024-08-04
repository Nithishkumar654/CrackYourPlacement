class Solution {
public:
    string intToRoman(int num) {
        string ans;
        int rem = num / 1000;
        while(rem--) ans += "M", num -= 1000;
        rem = num / 100;
        if(rem == 9) ans += "CM", num -= 900;
        rem = num / 500;
        while(rem--) ans += "D", num -= 500;
        rem = num / 100;
        if(rem == 4) ans += "CD", num -= 400;
        else while(rem--) ans += "C", num -= 100;
        rem = num / 10;
        if(rem == 9) ans += "XC", num -= 90;
        rem = num / 50;
        while(rem--) ans += "L", num -= 50;
        rem = num / 10;
        if(rem == 4) ans += "XL", num -= 40;
        else while(rem--) ans += "X", num -= 10;
        rem = num / 1;
        if(rem == 9) ans += "IX", num -= 9;
        rem = num / 5;
        while(rem--) ans += "V", num -= 5;
        rem = num / 1;
        if(rem == 4) ans += "IV", num -= 4;
        else while(rem--) ans += "I", num -= 1;
        
        return ans;
    }
};