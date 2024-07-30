class NumArray {
    vector<int> segTree, v; int n;

    void build(int idx, int l, int h){
        if(l == h){
            segTree[idx] = v[l];
            return;
        }
        int mid = (l + h) / 2;
        build(2 * idx + 1, l, mid);
        build(2 * idx + 2, mid + 1, h);
        segTree[idx] = segTree[2 * idx + 1] + segTree[2 * idx + 2];
    }

    void update(int idx, int l, int h, int index, int val){
        if(l == h){
            segTree[idx] = val;
            return;
        }
        int mid = (l + h) / 2;
        if(index <= mid) update(2 * idx + 1, l, mid, index, val);
        else update(2 * idx + 2, mid + 1, h, index, val);
        segTree[idx] = segTree[2 * idx + 1] + segTree[2 * idx + 2];
    }


    int rangeQuery(int idx, int l, int h, int left, int right){
        if(l > h) return 0;
        if(l >= left and h <= right) return segTree[idx];
        if(h < left or l > right) return 0;
        if(l == h) return segTree[idx];
        int mid = (l + h) / 2;
        int _l = rangeQuery(2 * idx + 1, l, mid, left, right);
        int _r = rangeQuery(2 * idx + 2, mid + 1, h, left, right);
        return _l + _r;
    }

public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        v = nums;
        segTree.resize(4 * n, 0);
        build(0, 0, n - 1);
    }
    
    void update(int index, int val) {
        update(0, 0, n - 1, index, val);
    }
    
    int sumRange(int left, int right) {
        return rangeQuery(0, 0, n - 1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */