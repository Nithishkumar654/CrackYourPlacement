class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast = nums[nums[0]], slow = nums[0];
        while(fast != slow){
            fast = nums[nums[fast]];
            slow = nums[slow];
        }
        slow = 0;
        while(fast != slow){
            fast = nums[fast];
            slow = nums[slow];
        }
        return slow;
    }
};