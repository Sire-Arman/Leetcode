class Solution {
public:
    int solve(vector<int>& nums, int t, int i,vector<vector<int>>& dp){
        if(t == 0) return 0;
        if(t<0 || i>=nums.size()) return -1;
        if(dp[i][t] != INT_MIN) return dp[i][t];
        int ans = -1;
        int skip = solve(nums,t,i+1,dp);
        int take = solve(nums,t-nums[i],i+1,dp);
        if(skip != -1) ans = max(skip,ans);
        if(take != -1) ans = max(take+1,ans);
        return dp[i][t] = ans;

    }
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        vector<vector<int>> dp(nums.size()+1,vector<int>(target+1,INT_MIN));
        return solve(nums,target,0,dp);
    }
};