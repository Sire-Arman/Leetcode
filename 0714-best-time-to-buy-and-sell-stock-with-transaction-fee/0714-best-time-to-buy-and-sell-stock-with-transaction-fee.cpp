class Solution {
public:
    int solve(vector<int> &arr, int i, bool b,int fee, vector<vector<int>> &dp){
        if(i == arr.size()) return 0;
        if(dp[i][b] != -1) return dp[i][b];
        int ans = 0;
        if(b){
            ans = max(ans, solve(arr,i+1,false,fee,dp)-arr[i]);
            ans = max(ans, solve(arr,i+1,true,fee,dp));
        }
        else{
            ans = max(ans, arr[i] + solve(arr,i+1,true,fee,dp)-fee);
            ans = max(ans, solve(arr, i+1, false,fee,dp));
        }
        return dp[i][b] = ans;
    }
    int solveTab(vector<int>& arr, int fee){
        int n = arr.size();
        vector<int> curr(3,0);
        vector<int> prev(3,0);
        
        for(int i = n-1;i>=0;i--){
            for(int on = 0;on<=1;on++){
                int ans =0;
                if(!(on&1)){
                    ans = max(ans , prev[on+1]-arr[i]);
                    ans = max(ans, prev[on]);
                }
                else{
                    ans = max(ans, prev[on+1]+arr[i]-fee);
                    ans = max(ans, prev[on]);
                } 
                curr[on] = ans;
            }
            prev = curr;
        }
        
        return curr[1] ;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int> (2,-1));
        return solve(prices,0,true,fee,dp);
    }
};