class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = nums[0];
        int c = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == ans) c++;
            else {
                c--;
                if(c == 0){
                    ans = nums[i];
                    c = 1;
                }
            }
        }
        return ans;
    }
};