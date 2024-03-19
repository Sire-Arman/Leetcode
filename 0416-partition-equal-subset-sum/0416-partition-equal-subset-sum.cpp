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
    bool solvetab(vector<int>& nums,int tot){
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(tot+1,0));
        for(int i=0;i<=n;i++){
            dp[i][0] = 1;
        }
        for(int i=n-1;i>=0;i--){
            for(int tar = 0;tar<=tot/2;tar++){
                    bool ans = false;
                if(tar-nums[i] >=0){
                    ans = ans || dp[i+1][tar-nums[i]];
                }
                    ans = ans || dp[i+1][tar];
                    dp[i][tar] = ans;
            }
        }
        return dp[0][tot/2];
    }
    bool canPartition(vector<int>& nums) {
        
       int target = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        if(target&1) return false;
        // target = target>>1;
        // vector<vector<int>> dp(n+1, vector<int>(target+1,-1));
        return solvetab(nums,target);
    }
};