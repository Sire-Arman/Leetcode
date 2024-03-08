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
    int maxSizeSlices(vector<int>& s) {
        int n = s.size();
        vector<vector<int>> dp1(n+1,vector<int>(n/3+1,-1));
        vector<vector<int>> dp2(n+1,vector<int>(n/3+1,-1));
        int a = solve(0,n-2,s,n/3,dp1);
        int b = solve(1,n-1,s,n/3,dp2);
        return max(a,b);
    }
};