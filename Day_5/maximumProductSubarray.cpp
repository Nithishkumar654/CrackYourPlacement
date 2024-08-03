class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        long long int p = 1; long long int mxp = INT_MIN, mxs = INT_MIN;
        for(int i = 0; i < n; i++){
            if(p == 0) p = 1;
            p *= nums[i];
            mxp = max(mxp, p);
        }
        p = 1;
        for(int i = n - 1; i >= 0; i--) {
            if(p == 0) p = 1;
            p *= nums[i];
            mxs = max(mxs, p);
        }
        return max(mxp, mxs);
    }
};