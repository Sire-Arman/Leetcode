class Solution {
public:
    int solve(vector<int> &arr, int i, bool b, vector<vector<int>> &dp){
        if(i == arr.size()) return 0;
        if(dp[i][b] != -1) return dp[i][b];
        int ans = 0;
        if(b){
            ans = max(ans, solve(arr,i+1,false,dp)-arr[i]);
            ans = max(ans, solve(arr,i+1,true, dp));
        }
        else{
            ans = max(ans, arr[i] + solve(arr,i+1,true,dp));
            ans = max(ans, solve(arr, i+1, false,dp));
        }
        return dp[i][b] = ans;
    }
    int solveTab(vector<int> &arr){
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int> (2,0));
        
        for(int i = n-1;i>=0;i--){
            for(int j =0;j<=1;j++){
                    int ans = 0;
                    if(j){
                        ans = max(ans, dp[i+1][0]-arr[i]);
                        ans = max(ans, dp[i+1][1]);
                    }
                    else{
                        ans = max(ans, arr[i] + dp[i+1][1]);
                        ans = max(ans, dp[i+1][0]);
                    }
                dp[i][j] = ans;
            }
        }
        return dp[0][1];
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp (n+1, vector<int>(2, -1));
        return solveTab(prices);
    }
};