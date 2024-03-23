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
    int solveTab(int n){
        vector<vector<int>> dp(n+2,vector<int> (n+2,0));
       
        for(int i = n;i>=1;i--){
            for(int j = i;j<=n;j++){
                if(i == j) continue;
                else{int ans = INT_MAX;                
                for(int k = i;k<= j;k++){
                 ans = min(ans, k+max(dp[i][k-1],dp[k+1][j]));   
                }
                dp[i][j] = ans;}
            }
        }
        return dp[1][n];
    }
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solveTab(n);
    }
};