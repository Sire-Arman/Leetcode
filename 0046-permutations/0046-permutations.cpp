class Solution {
public:
    void solve (vector<int> nums, vector<vector<int>> &ans, map<int,bool> mp, vector<int> temp){
        if(temp.size() == nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!mp[nums[i]]){
                mp[nums[i]] = true;
                temp.push_back(nums[i]);
                solve(nums,ans,mp,temp);
                temp.pop_back();
                mp[nums[i]] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
       vector<vector<int>> ans;
        vector<int> temp;
        map<int,bool> mp;
        solve(nums, ans,mp,temp);
        return ans;
    }
};