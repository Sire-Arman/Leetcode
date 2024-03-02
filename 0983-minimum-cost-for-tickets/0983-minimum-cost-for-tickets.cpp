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
    int tab(vector<int>& days, vector<int>& costs, int i){  
        int n = days.size();
        vector<int> dp(n+1,INT_MAX);
        dp[n] = 0;
        
        for(int i=n-1;i>=0;i--){
            dp[i] = min(dp[i],costs[0] + dp[i+1]);
            int j;
        for(j=i;j<days.size() && days[j]< days[i]+7;j++);
        
        dp[i] = min(dp[i],costs[1] + dp[j]);
        
        for(j=i;j<days.size() && days[j]< days[i]+30;j++);
        
        dp[i] = min(dp[i],costs[2] + dp[j]);
        }
        return dp[0];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        return tab(days,costs,0);
    }
};