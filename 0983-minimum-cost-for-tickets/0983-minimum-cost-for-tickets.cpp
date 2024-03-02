class Solution {
public:
    int op[3] = {0,6,29};
    int solve(vector<int>& days, vector<int>& costs, int i,vector<int> &dp){
        if(i >= days.size()) {
            return 0;
        }
        if(dp[i] != -1) return dp[i];
        int mini = INT_MAX;
        mini = min(mini, costs[0] + solve(days,costs,i+1,dp));
        int j;
        for(j=i;j<days.size() && days[j]< days[i]+7;j++);
        
        mini = min(mini,costs[1] +solve(days,costs,j,dp));
        
        for(j=i;j<days.size() && days[j]< days[i]+30;j++);
        
        mini = min(mini,costs[2] +solve(days,costs,j,dp));
        
       
        dp[i] = mini;
        return dp[i];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n+1,-1);
        return solve(days,costs,0,dp);
    }
};