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
    
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        int n = satisfaction.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
         return solve(satisfaction,0,0, dp);
    }
};