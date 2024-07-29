class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        map<int, int> mp;
        int sum = 0; mp[0]++;
        for(int x : nums){
            sum += x;
            ans += mp[sum - k];
            mp[sum]++;
        }
        return ans;
    }
};