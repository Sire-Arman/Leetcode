class Solution {
public:
     int solve(vector<int> &arr, int i, bool b, int lim, vector<vector<vector<int>>> &dp){
        if(i == arr.size() || lim >=2 ) return 0;
        if(dp[i][b][lim] != -1) return dp[i][b][lim];
        int ans = 0;
        if(b){
            ans = max(ans, solve(arr,i+1,false,lim,dp)-arr[i]);
            ans = max(ans, solve(arr,i+1,true,lim,dp));
        }
        else{
            ans = max(ans, arr[i] + solve(arr,i+1,true,lim+1,dp));
            ans = max(ans, solve(arr, i+1, false,lim,dp));
        }
        return dp[i][b][lim] = ans;
    }
        int solveTab(vector<int> &arr){
        int n = arr.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (3,0)));
        
        for(int i = n-1;i>=0;i--){
            for(int j =0;j<=1;j++){
                for(int k = 0;k<=1;k++){
                    int ans = 0;
                    if(j){
                        ans = max(ans, dp[i+1][0][k] - arr[i]);
                        ans = max(ans, dp[i+1][1][k]);
                    }
                    else{
                        ans = max(ans, arr[i] + dp[i+1][1][k+1]);
                        ans = max(ans, dp[i+1][0][k]);
                    }
                    dp[i][j][k] = ans;
                }
            }
        }
        return dp[0][1][0];
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (2,-1)));
        return solveTab(prices);
    }
};