class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int m = 0, p = 0, n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] < 0) m++;
            if(nums[i] > 0) p++;
        }
        if(p == 0 or m == 0) return nums[n - 1] * nums[n - 2] * nums[n - 3];
        int ans = nums[n - 1] * nums[n - 2] * nums[n - 3];
        return max(ans, nums[n - 1] * nums[0] * nums[1]);
    }
};