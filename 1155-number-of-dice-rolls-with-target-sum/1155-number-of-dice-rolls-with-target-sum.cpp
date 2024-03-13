class Solution {
public: 
    int MOD = 1e9+7;
    int solve(int n, int k, int target, vector<vector<int>>& dp){
        if(n==0 && target == 0) return 1;
        if(n==0 || target <= 0) return 0;
        if(dp[n][target] != -1) return dp[n][target];
        int ans = 0;
        for(int i=1;i<=k;i++){
            ans = (ans + solve(n-1,k,target-i,dp))%MOD;
        }
        return dp[n][target] = ans;
    }
    int solveTab(int n, int k, int target){
        vector<vector<int>> dp(n+1,vector<int> (target+1,0));
        dp[0][0] = 1;
        for(int i = 1;i<=n;i++){
            for(int j=1;j<=target;j++){
                for(int x=1;x<=k;x++){
                    if(j-x>=0) dp[i][j] = (dp[i][j] + dp[i-1][j-x])%MOD;
                }
            }
        }
        
        return dp[n][target];
    }
    int numRollsToTarget(int n, int k, int target) {
        // vector<vector<int>> dp(n+1,vector<int> (target+1,-1));
        return solveTab(n,k,target);
    }
};