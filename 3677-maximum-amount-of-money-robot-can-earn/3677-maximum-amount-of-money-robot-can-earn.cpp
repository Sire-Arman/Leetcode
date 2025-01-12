class Solution {
public:
    int helper( vector<vector<int>>& coins, int i, int j, int p,vector<vector<vector<int>>>& dp){
        if(i>=coins.size() || j >= coins[0].size()) return -1e5*5;
        if(i==coins.size()-1 && j == coins[0].size()-1) {
            if(coins[i][j] <0 && p) return 0;
            else return coins[i][j];
        }
        if(dp[i][j][p] != INT_MIN) return dp[i][j][p];

        int ans =INT_MIN;
    int val = coins[i][j];
    if(val <0 && p){
        ans = max(ans,0+helper(coins,i+1,j,p-1,dp));
        ans = max(ans,0+helper(coins,i,j+1,p-1,dp));
    }
        ans = max(ans, coins[i][j] + helper(coins,i+1,j,p,dp));
        ans = max(ans, coins[i][j] + helper(coins,i,j+1,p,dp));
        return dp[i][j][p] = ans;
    }
    int maximumAmount(vector<vector<int>>& coins) {
        vector<vector<vector<int>>> dp(coins.size(),vector<vector<int>>(coins[0].size(),vector<int>(3,INT_MIN)));
        return helper(coins,0,0,2,dp);
    }
};