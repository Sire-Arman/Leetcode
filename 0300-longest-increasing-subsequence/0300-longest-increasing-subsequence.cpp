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
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i = n-1;i>=0;i--){
            for(int ans=i-1;ans>=-1;ans--){
                int inc = 0,exc =0;
                if(ans == -1 || nums[i] > nums[ans]) { inc = 1 + dp[i+1][i+1];}
                exc = dp[i+1][ans+1];
                dp[i][ans+1] = max(inc,exc);
            }
        }            
            return dp[0][0];
    }
    int solveSO(vector<int>& nums){
        int n = nums.size();
        vector<int> curr(n+1,0);
        vector<int> next(n+1,0);
        // vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i = n-1;i>=0;i--){
            for(int ans=i-1;ans>=-1;ans--){
                int inc = 0,exc =0;
                if(ans == -1 || nums[i] > nums[ans]) { inc = 1 + next[i+1];}
                exc = next[ans+1];
                curr[ans+1] = max(inc,exc);
            }
            next = curr;
        }            
            return curr[0];
    }
    int binaryDP(vector<int>& nums){
        int n =nums.size();
        if(n == 0) return 0;
        vector<int> ref;
        ref.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i] > ref.back()){
                ref.push_back(nums[i]);
            }
            else{
                int ind = lower_bound(ref.begin(),ref.end(), nums[i]) - ref.begin();
                ref[ind] = nums[i];
            }
        }
        return ref.size();
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1, -1));
        return binaryDP(nums);
    }
};