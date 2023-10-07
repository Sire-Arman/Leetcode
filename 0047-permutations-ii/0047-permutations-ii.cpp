class Solution {
public:
     void solve (vector<int> nums, set<vector<int>> &ans, map<int,bool> mp, vector<int> temp){
        if(temp.size() == nums.size()){
            ans.insert(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!mp[i]){
                mp[i] = true;
                temp.push_back(nums[i]);
                solve(nums,ans,mp,temp);
                temp.pop_back();
                mp[i] = false;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> ans;
          vector<vector<int>> res;
        vector<int> temp;
        map<int,bool> mp;
        solve(nums,ans,mp,temp);
        for(auto it : ans){
            res.push_back(it);
        }
        return res;
    }
};