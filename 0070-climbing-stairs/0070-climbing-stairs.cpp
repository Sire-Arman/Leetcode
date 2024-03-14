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
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return helper(n,dp);
    }
};