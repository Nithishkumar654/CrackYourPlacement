class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 0;
        while(j < nums.size()){
            nums[i] = nums[j];
            while(j < nums.size() and nums[j] == nums[i]) j++;
            i++;
        }
        return i;
    }
};