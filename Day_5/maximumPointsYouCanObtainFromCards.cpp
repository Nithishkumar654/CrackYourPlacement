class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int ans = 0;
        int n = cardPoints.size();
        k = n - k;
        vector<int> prefix(n, 0), suffix(n, 0);
        int p = 0, s = 0;
        for(int i = 0; i < n; i++){
            p += cardPoints[i];
            s += cardPoints[n - i - 1];
            prefix[i] = p;
            suffix[n - i - 1] = s;
        }
        ans = max(prefix[n - 1 - k], suffix[k]);
        for(int i = k; i < n - 1; i++){
            ans = max(ans, prefix[i - k] + suffix[i + 1]);
        }
        return ans;
    }
};