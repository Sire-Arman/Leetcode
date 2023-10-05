class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int,int> mp;
        vector<int> ans;
        int n = nums.size()/3;
        for(auto it: nums){
            if(mp[it]>=n && mp[it] != -1){
                ans.push_back(it);
                mp[it] = -1;
            }
            else
            mp[it]++;
        }
        return ans;
    }
};