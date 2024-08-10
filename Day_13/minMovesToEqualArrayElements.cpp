class Solution {
public:
    int minMoves2(vector<int>& nums) {
        // 1 2 9 10
        // y = summation |x - x1|
        sort(nums.begin(), nums.end());
        int avg = nums[nums.size()/2];
        int ans = 0;
        for(int x : nums) ans += abs(x - avg);
        return ans;
    }
};