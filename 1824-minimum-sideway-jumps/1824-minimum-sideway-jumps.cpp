class Solution {
public:
    int solve(vector<int>& obs, int i, int lane,vector<vector<int>>& dp){
        if( i== obs.size()-1) return 0;
        if(dp[i][lane] != -1) return dp[i][lane];
        if(obs[i+1] != lane) return dp[i][lane] = solve(obs,i+1,lane,dp);
        else{
            int k =INT_MAX;
            for(int j=1;j<=3;j++){
                if(lane != j && obs[i] != j){
                    k = min(k, 1+ solve(obs,i+1,j,dp));  
                }
            }
            return dp[i][lane] = k;
        }
    }
    int solveTab(vector<int> &obs){
        int n = obs.size()-1;
        vector<vector<int>> dp (n+1,vector<int>(4,1e9));
        dp[n][0] = 0;
        dp[n][1] = 0;
        dp[n][2] = 0;
        dp[n][3] = 0;
        
        for(int i=n-1;i>=0;i--){
                for(int j = 1;j<=3;j++){
                    if(obs[i+1] != j) dp[i][j] = dp[i+1][j];
                    else{
                        int k =1e9;
                        for(int l=1;l<=3;l++){
                            if(j != l && obs[i] != l){
                                k = min(k, 1 + dp[i+1][l]);  
                            }
                        }
                        dp[i][j] = k;
                    }
                }
            }
        return min(dp[0][2],min(dp[0][1]+1,dp[0][3]+1));
    }
    int solveSO(vector<int> &obs){
        int n = obs.size()-1;
         vector<int> curr(4,1e9);
         vector<int> next(4,1e9);
        next[0] = 0;
        next[1] = 0;
        next[2] = 0;
        next[3] = 0;
        
        for(int i=n-1;i>=0;i--){
                for(int j = 1;j<=3;j++){
                    if(obs[i+1] != j) curr[j] = next[j];
                    else{
                        int k =1e9;
                        for(int l=1;l<=3;l++){
                            if(j != l && obs[i] != l){
                                k = min(k, 1 + next[l]);  
                            }
                        }
                        curr[j] = k;
                    }
                }
            next = curr;
            }
        return min(curr[2],min(curr[1]+1,curr[3]+1));
    }
    int minSideJumps(vector<int>& obstacles) {
        // int n = obstacles.size();
        // vector<vector<int>> dp(n+1,vector<int> (4,-1));
        return solveTab(obstacles);
    }
};