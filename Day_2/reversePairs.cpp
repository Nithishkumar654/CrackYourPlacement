class Solution {
public:

    pair<int, int> floor(int x, vector<int> &a){
    
    //vector a is pre-sorted
        if(x <= 2LL * a[0]) return {INT_MIN, -1};
        
        int l = 0, h = a.size() - 1;
        while(l < h){
            int mid = (l+h+1)/2;
            if(2LL * a[mid] >= x){
                h = mid - 1;
            }else{
                l = mid;
            }
        }
        
        return {a[l], l}; // or return {a[h], h};
    }

    int merge(int l, int mid, int h, vector<int>& nums){
        int i = l, j = mid + 1;
        vector<int> t(h - l + 1);

        int k = 0, inv = 0;
        vector<int> twice(h - j + 1);
        for(int i = j; i <= h; i++) twice[i - j] = nums[i];

        for(int i = l; i <= mid; i++){
            int idx = floor(nums[i], twice).second;
            inv += idx + 1;
        }

        while(i <= mid and j <= h){
            if(nums[i] < nums[j]) t[k] = nums[i], i++;
            else t[k] = nums[j], j++;
            k++;
        }
        while(i <= mid) t[k++] = nums[i++];
        while(j <= h) t[k++] = nums[j++];
        for(int i = l; i <= h; i++) nums[i] = t[i - l];
        return inv;
    }


    int mergeSort(int l, int h, vector<int>&nums){
        if(l >= h) return 0;
        int mid = (l + h)/2;
        int inv = 0;
        inv += mergeSort(l, mid, nums);
        inv += mergeSort(mid + 1, h, nums);
        inv += merge(l, mid, h, nums);
        return inv;
    }


    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergeSort(0, n - 1, nums);
    }
};