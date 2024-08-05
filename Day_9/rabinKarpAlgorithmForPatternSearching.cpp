
int mul(int a, int b, int m){ a %= m; b %= m; return (a * 1LL * b) % m; }
int sub(int a, int b, int m){ a %= m; b %= m; return ((a + 0ll - b) % m + m) % m; }
int add(int a, int b, int m){ a %= m; b %= m; return (a + 0ll + b) % m; }

class Solution {
    public:
        vector <int> search(string pattern, string text) {
            //code here.
            // Hashing hp(pattern), ht(text);
            vector<int> ans;
            int m = pattern.length(), n = text.length(), prime = 31;
            
            int hash = 0, mod = 1e9 + 7;
            vector<int> powers(max(m, n), 0);
            powers[0] = 1;
            for(int i = 1; i < max(m, n); i++){
                powers[i] = mul(powers[i - 1], prime, mod);
            }
            for(int i = 0; i < m; i++){
                hash = add(hash, mul(pattern[i] - 'a' + 1, powers[i], mod), mod);
            }
            int h = 0;
            vector<int> pfx(n, 0);
            for(int i = 0; i < n; i++){
                h = add(h, mul(text[i] - 'a' + 1, powers[i], mod), mod);
                pfx[i] = h;
            }
            
            
            for(int i = 0; i <= n - m; i++){
                int pf = pfx[i + m - 1];
                if(i > 0) pf = sub(pf, pfx[i - 1], mod);
                if(mul(hash, powers[i], mod) == pf) ans.push_back(i + 1);
            }
            return ans;
        }
     
};