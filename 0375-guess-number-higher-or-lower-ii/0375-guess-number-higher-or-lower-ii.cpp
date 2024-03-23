class Solution {
public:
    int solve(int st, int end, vector<vector<int>> &dp){
        if(st>= end) return 0;
        if(dp[st][end] != -1) return dp[st][end];
        int ans = INT_MAX;
        for(int i = st;i<=end;i++){
            ans = min(ans, i+max(solve(st,i-1,dp),solve(i+1,end,dp)));
        }
        return dp[st][end] = ans;
    }
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(0,n,dp);
    }
};