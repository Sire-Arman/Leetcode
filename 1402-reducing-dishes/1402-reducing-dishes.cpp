class Solution {
public:
    int solve(vector<int> &sat, int i, int time,vector<vector<int>> &dp){
        if(i == sat.size()){
           return 0;
        }
        if(dp[i][time] != -1) return dp[i][time];
        int inc = sat[i]*(time+1) + solve(sat,i+1,time+1,dp);
        int exc = solve(sat,i+1,time,dp);
        return dp[i][time] = max(inc,exc);
    }
     int solveTab(vector<int> &sat){
         int n = sat.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
         for(int i = n-1;i>=0;i--){
             for(int j=i;j>=0;j--){
                int inc = sat[i]*(j+1) + dp[i+1][j+1];
                int exc = dp[i+1][j];
                dp[i][j] = max(inc , exc);
             }
         }
         return dp[0][0];
    }
    int solveSO(vector<int> &sat){
         int n = sat.size();
        vector<int> curr(n+1,0);
        vector<int> next(n+1,0);
         for(int i = n-1;i>=0;i--){
             for(int j=i;j>=0;j--){
                int inc = sat[i]*(j+1) + next[j+1];
                int exc = next[j];
                curr[j] = max(inc , exc);
             }
             next = curr;
         }
         return curr[0];
    }
    
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        int n = satisfaction.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
         return solveSO(satisfaction);
    }
};