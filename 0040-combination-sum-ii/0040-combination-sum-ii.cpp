class Solution {
public:
     void helper(int ind,int n,vector<int> &temp,vector<int> &nums,int target, vector<vector<int>> &ans){
            if(target==0){
                 ans.push_back(temp);
                return;
            }
        for(int i=ind;i<nums.size();i++){
            if(i>ind && nums[i]==nums[i-1]) continue;
            if(nums[i]>target) break;
        temp.push_back(nums[i]);
        helper(i+1,n,temp,nums,target-nums[i],ans);
        temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        sort(c.begin(),c.end());
        vector<vector<int>> ans;
        // set<vector<int>> ans;
        vector<int> temp;
        int n = c.size();
        helper(0,n,temp,c,target,ans);
        // for(auto it:ans){
        //     res.push_back(it);
        // }
        return ans;
    }
};