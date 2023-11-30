class Solution {
public:
    void helper(int ind,int n,vector<int> &temp,vector<int> nums,int target, vector<vector<int>> &ans){
        if(ind == n){
            if(target==0){
                 ans.push_back(temp);
            }
            return;
        }
        if(target>=nums[ind]){
        temp.push_back(nums[ind]);
        helper(ind,n,temp,nums,target-nums[ind],ans);
        temp.pop_back();
        }
        helper(ind+1,n,temp,nums,target,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& c, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = c.size();
        helper(0,n,temp,c,target,ans);
        return ans;
    }
};