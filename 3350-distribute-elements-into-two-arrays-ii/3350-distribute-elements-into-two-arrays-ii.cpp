#include <ext/pb_ds/assoc_container.hpp> // For PBDS
using namespace __gnu_pbds;
typedef tree<
    pair<int,int>,
    null_type,
    less<pair<int,int>>,
    rb_tree_tag,
    tree_order_statistics_node_update>
ordered_set;
class Solution {
public:
// Define ordered_set


void solve(vector<int> &nums, ordered_set &s1, ordered_set &s2, vector<int> &a1) {
    int n = nums.size();
    vector<int> a2;
    // Insert first two elements
    s1.insert({nums[0],0});
    a1.push_back(nums[0]);
    s2.insert({nums[1],1});
    a2.push_back(nums[1]);

    for (int i = 2; i < n; i++) {
        int a = s1.size() - s1.order_of_key({nums[i] + 1,-1}); // Elements >= nums[i]
        int b = s2.size() - s2.order_of_key({nums[i] + 1,-1});

        if (a < b) {
            s2.insert({nums[i],i});
            a2.push_back(nums[i]);
        } else if (a > b) {
            s1.insert({nums[i],i});
            a1.push_back(nums[i]);
        } else {
            if (a1.size() <= a2.size()) {
                s1.insert({nums[i],i});
                a1.push_back(nums[i]);
            } else {
                s2.insert({nums[i],i});
                a2.push_back(nums[i]);
            }
        }
    }

    // Push elements from s1 and s2 into the result
    for (auto &it : a2) {
        a1.push_back(it);
    }
}
    vector<int> resultArray(vector<int>& nums) {
        vector<int> res;
        ordered_set s1,s2;
        
        solve(nums,s1,s2,res);
        return res;
    }
};