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
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp (n+1, vector<int>(2, -1));
        return solve(prices, 0, true,dp);
    }
};