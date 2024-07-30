#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template<class T> using pbds = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ans(nums.size());
        pbds<int> st;
        for(int i = nums.size() - 1; i >= 0; i--){
            st.insert(nums[i]);
            ans[i] = st.order_of_key(nums[i]);
        }
        return ans;
    }
};