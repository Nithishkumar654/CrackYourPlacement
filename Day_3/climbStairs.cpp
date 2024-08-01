class Solution {
public:
    int climbStairs(int n) {
        if(n <= 3) return n;
        int a = 1, b = 2;
        int c = a + b;
        n -= 2;
        while(n--){
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};