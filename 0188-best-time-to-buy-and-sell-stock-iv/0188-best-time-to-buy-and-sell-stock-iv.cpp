class Solution {
public:
//     using operation/transaction no.
    int solve(vector<int>& arr, int i, int on, int k, vector<vector<int>>& dp){
        if(i == arr.size() || on == 2*k){
            return 0;
        }
        if(dp[i][on] != -1) return dp[i][on];
        int ans =0;
        if(on&1){
            ans = max(ans, arr[i]+solve(arr,i+1,on+1,k,dp));
            ans = max(ans, solve(arr,i+1,on,k,dp));
        }
        else{
            ans = max(ans, solve(arr,i+1,on+1,k,dp)-arr[i]);
            ans = max(ans, solve(arr,i+1,on,k,dp));
        }
        return dp[i][on] = ans;
    }
    
//     Tabulation
    int solveTab(vector<int>& arr, int k){
        int n = arr.size();
        vector<int> curr(2*k+1,0);
        vector<int> prev(2*k+1,0);
        
        // vector<vector<int>> dp(n+1, vector<int> (2*k+1, 0));
        for(int i= n-1;i>= 0;i--){
            for(int on = 2*k-1;on>=0;on--){
                int ans =0;
                if(on&1){
                    ans = max(ans, arr[i]+prev[on+1]);
                    ans = max(ans, prev[on]);
                }
                else{
                    ans = max(ans, prev[on+1]-arr[i]);
                    ans = max(ans, prev[on]);
                }
                curr[on] = ans;
            }
            prev = curr;
        }
        return curr[0];
        
    }
    
    // int solve(vector<int> &arr, int i, bool b, int lim, vector<vector<vector<int>>> &dp,int k){
    //     if(i == arr.size() || lim >= k ) return 0;
    //     if(dp[i][b][lim] != -1) return dp[i][b][lim];
    //     int ans = 0;
    //     if(b){
    //         ans = max(ans, solve(arr,i+1,false,lim,dp,k)-arr[i]);
    //         ans = max(ans, solve(arr,i+1,true,lim,dp,k));
    //     }
    //     else{
    //         ans = max(ans, arr[i] + solve(arr,i+1,true,lim+1,dp,k));
    //         ans = max(ans, solve(arr, i+1, false,lim,dp,k));
    //     }
    //     return dp[i][b][lim] = ans;
    // }
    int maxProfit(int k, vector<int>& prices) {
         int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int> (2*k,-1));
        // vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (k+1,-1)));
        return solveTab(prices, k);
    }
};