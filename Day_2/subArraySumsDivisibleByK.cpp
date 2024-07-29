class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans = 0;
        for(int &x : nums) x = (x + k) % k;
        int sum = 0;
        map<int, int> mp;
        mp[0]++;
        for(int x : nums){
            sum = (sum + x + k) % k;
            ans += mp[sum];
            mp[sum]++;
        }
        return ans;
    }
};