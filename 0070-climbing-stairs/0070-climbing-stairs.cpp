class Solution {
public:
int helper(int n,vector<int>& dp ){
    if(n == 0) return 1;
    if(n < 0) return 0;
    if(dp[n] != -1) return dp[n];
    int a1 = helper(n-1,dp);
    int a2 = helper(n-2,dp);
    return dp[n] = a1+a2;
}
    int helperTab(int n){
        // if(n<=1) return 1;
        vector<int> dp(n+1,0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2;i<=n;i++){
             dp[i] = dp[i-1] + dp[i-2];
        }
    return dp[n];
}
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return helperTab(n);
    }
};