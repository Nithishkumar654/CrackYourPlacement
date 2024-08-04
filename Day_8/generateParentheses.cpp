class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        string s;
        auto solve = [&](auto& solve, int open, int close){
            if(close == n){
                ans.push_back(s);
                return;
            }
            if(open < n){
                s += "(";
                solve(solve, open + 1, close);
                s.pop_back();
            }
            if(open > close){
                s += ")";
                solve(solve, open, close + 1);
                s.pop_back();
            }
        };
        solve(solve, 0, 0);
        return ans;
    }
};