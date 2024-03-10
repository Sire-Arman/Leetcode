class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,bool> mp;
        for(auto it : nums1){
            mp[it] = true;
        }
        int cnt =0;
        for(auto &it: nums2){
            if(!mp[it]){
                it = INT_MAX;
            }
            else {cnt++; mp[it] = false;}
        }
        sort(nums2.begin(),nums2.end());
        nums2.resize(cnt);
        return nums2;
    }
};