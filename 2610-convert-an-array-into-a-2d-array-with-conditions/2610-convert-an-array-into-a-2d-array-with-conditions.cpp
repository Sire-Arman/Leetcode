class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int maxfreq =0;
        map<int,int> mp;
        for(auto it : nums){
            mp[it]++;
            maxfreq = max(maxfreq,mp[it]);
        }
        vector<vector<int>> ans(maxfreq);
        for(auto it: mp){
            int i = it.second-1;
            while(i>=0) ans[i--].push_back(it.first);
        }
        return ans;
    }
};