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
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (2,-1)));
        return solve(prices,0,true,0,dp);
    }
};