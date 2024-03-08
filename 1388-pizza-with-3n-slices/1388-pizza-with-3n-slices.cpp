class Solution {
public:
    int solve(int i, int j, vector<int> &s, int n,vector<vector<int>> &dp){
        if(n == 0 || i > j){
            return 0;
        }
        if(dp[i][n] != -1) return  dp[i][n];
        int tk = s[i] + solve(i+2,j,s,n-1,dp);
        int nt = solve(i+1,j,s,n,dp);
        return dp[i][n] = max(nt,tk);
    }
    int solveTab(vector<int>& s, int st,int end){
        int t = s.size();
        // vector<vector<int>> dp(t+2,vector<int>(t+2,0));
        vector<int> prev(t+2,0);
        vector<int> curr(t+2,0);
        vector<int> next(t+2,0);
        // t /=3;
        for(int i = end;i>=st;i--){
            for(int n = 1;n<=t/3;n++){
                int tk = s[i] + prev[n-1];
                // int tk = 0;
                int nt = curr[n];
                next[n] = max(nt,tk);
            }
            prev = curr;
            curr = next;
        }
        return next[t/3];
    }
    int maxSizeSlices(vector<int>& s) {
        int n = s.size();
        // vector<vector<int>> dp1(n+1,vector<int>(n/3+1,-1));
        // vector<vector<int>> dp2(n+1,vector<int>(n/3+1,-1));
        int a = solveTab(s,0,n-2);
        int b = solveTab(s,1,n-1);
        return max(a,b);
    }
};