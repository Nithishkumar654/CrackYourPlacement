class NumArray {
    vector<int> pref;
public:
    NumArray(vector<int>& nums) {
        int sum = 0;
        for(int x : nums) sum += x, pref.push_back(sum);
    }
    
    int sumRange(int left, int right) {
        return pref[right] - (left > 0 ? pref[left - 1] : 0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */