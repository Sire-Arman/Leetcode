class Solution {
public:
    bool solve(vector<int>& nums, int i, int target, int sum, vector<vector<int>> &dp){
        if(i == nums.size() && sum == target) return true;
        if(i == nums.size() || sum > target) return false;
        if(dp[i][sum] != -1) return dp[i][sum];
        bool ans = false;
        ans = ans || solve(nums,i+1,target,sum+nums[i],dp);
        ans = ans || solve(nums,i+1, target,sum,dp);
        
        return dp[i][sum] = ans;
    }
    bool canPartition(vector<int>& nums) {
        
       int target = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        if(target&1) return false;
        target = target>>1;
        vector<vector<int>> dp(n+1, vector<int>(target+1,-1));
        return solve(nums,0,target,0,dp);
    }
};