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
        if(n<=1) return 1;
        // vector<int> dp(n+1,0);
        int a =1,b=1,c=0;
        for(int i = 2;i<=n;i++){
             c = b + a;
                a=b;
                b=c;
        }
    return c;
}
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return helperTab(n);
    }
};