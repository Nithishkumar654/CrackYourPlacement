class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0, j = 0, k = nums.size() - 1;
        while(j <= k){
            
            if(i < j and nums[j] == 0) {
                swap(nums[i], nums[j]);
                i++;
            }
            else if(j < k and nums[j] == 2) {
                swap(nums[k], nums[j]);
                k--;
            }
            else j++;
        }
    }
};