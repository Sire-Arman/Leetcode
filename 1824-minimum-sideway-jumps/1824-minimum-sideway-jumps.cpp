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
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<vector<int>> dp(n+1,vector<int> (4,-1));
        return solve(obstacles, 0,2,dp);
    }
};