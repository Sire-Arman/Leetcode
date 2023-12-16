class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> m1;
        map<int,int> m2;
        vector<vector<int>> ans(2);
        for(auto it : nums1){
            m2[it]++;
        }
        for(auto it: nums2){
            m1[it]++;
        }
        for(auto it : nums1){
            if(m1[it] == 0){
                ans[0].push_back(it);
                m1[it] = -1;
            }
        }
        for(auto it : nums2){
            if(m2[it] == 0){
                ans[1].push_back(it);
                m2[it] = -1;
            }
        }
        return ans;
    }
};