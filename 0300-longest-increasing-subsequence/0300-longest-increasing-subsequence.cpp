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
    int solveTab(vector<int>& nums){
        int n = nums.size();
        vector<int> dp(n+1,1);
        for(int i = 1;i<n;i++){
            for(int ans=0;ans<i;ans++){
                if(nums[i] > nums[ans]) { dp[i] = max(dp[i],dp[ans]+1);}
            }
        }            
            return *max_element(dp.begin(),dp.end());
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1, -1));
        return solveTab(nums);
    }
};