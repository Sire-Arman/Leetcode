int MOD = 1e9+7;
class Solution {
public:
    
    int solve(int n, int a, int l,vector<vector<vector<int>>>& dp){
        if(n <= 0) return 1;
        if(dp[n][a][l] != -1) return dp[n][a][l];
        int ans =0;
        if(l){
            ans = (ans+solve(n-1,a,l-1,dp))%MOD;
        }
        if(a){
            ans = (ans+solve(n-1,a-1,2,dp))%MOD;
        }
        ans =  (ans+solve(n-1,a,2,dp))%MOD;
        return dp[n][a][l] = ans;
    }
    int solveTab(int n){
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        for(int i=0;i<2;i++){
            for(int j=0;j<3;j++){
                dp[0][i][j]=1;
            }
        }
        for(int i =1;i<=n;i++){
            for(int a =0;a<2;a++){
                for(int l=0;l<3;l++){
                     int ans =0;
                    if(l){
                        ans = (ans+dp[i-1][a][l-1])%MOD;
                    }
                    if(a){
                        ans = (ans+dp[i-1][a-1][2])%MOD;
                    }
                    ans =  (ans+dp[i-1][a][2])%MOD;
                    dp[i][a][l] = ans;
                }
            }
        }
        return dp[n][1][2];
    }
    int checkRecord(int n) {
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        // return solve(n,1,2,dp);
        return solveTab(n);
    }
};