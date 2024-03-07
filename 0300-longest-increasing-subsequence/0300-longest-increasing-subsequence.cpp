class Solution {
public:
    int solve(vector<int>& nums, int i,int ans, vector<vector<int>> &dp){
        if(i == nums.size()){
            return 0;
        }
        
        if(ans != -1 && dp[i][ans] != -1) return dp[i][ans];
        
            int inc = 0,exc =0;
            if(ans == -1 || nums[i] > nums[ans]) { inc = 1 + solve(nums,i+1,i,dp);}
            exc = solve(nums,i+1,ans,dp);
            dp[i][ans==-1?i:ans] = max(inc,exc);
            return dp[i][ans==-1?i:ans];
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1, -1));
        return solve(nums,0,-1,dp);
    }
};