class Solution {
public:
    int mod = 1e9+7;
    int solve(vector<vector<int>>& dp, int n,int k, int target){
        if(target == 0 && n == 0){
           return 1;
        }
        if(n==0 || target<=0) return 0;
        if(dp[n][target] != -1) return dp[n][target];
        int ways =0;
        for(int i=0;i<k;i++){
            ways = (ways+solve(dp,n-1,k,target-i-1))%mod;
        }
        dp[n][target] = ways %mod;
        return dp[n][target];
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        int ans = solve(dp,n,k,target);
        return ans;
    }
};