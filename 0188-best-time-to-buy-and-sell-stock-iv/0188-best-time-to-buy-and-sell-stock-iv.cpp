class Solution {
public:
    int solve(vector<int> &arr, int i, bool b, int lim, vector<vector<vector<int>>> &dp,int k){
        if(i == arr.size() || lim >= k ) return 0;
        if(dp[i][b][lim] != -1) return dp[i][b][lim];
        int ans = 0;
        if(b){
            ans = max(ans, solve(arr,i+1,false,lim,dp,k)-arr[i]);
            ans = max(ans, solve(arr,i+1,true,lim,dp,k));
        }
        else{
            ans = max(ans, arr[i] + solve(arr,i+1,true,lim+1,dp,k));
            ans = max(ans, solve(arr, i+1, false,lim,dp,k));
        }
        return dp[i][b][lim] = ans;
    }
    int maxProfit(int k, vector<int>& prices) {
         int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (k+1,-1)));
        return solve(prices, 0,true,0,dp,k);
    }
};