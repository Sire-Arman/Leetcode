class Solution {
public:
    int solve(string &a, string &b, int i, int j, vector<vector<int>> &dp){
        if(i == a.size() || j == b.size()) return 0;
        int ans = 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(a[i] == b[j]) {
            ans = max(ans , 1+ solve(a,b,i+1,j+1,dp));
        }
        else{
            ans = max(ans, solve(a,b,i+1,j,dp));
            ans = max(ans, solve(a,b,i,j+1,dp));
        }
        return dp[i][j] = ans;
    }
    int solveTab(string &a, string &b){
        int n = a.size(), m = b.size();
        vector<int> curr(m+1,0);
        vector<int> next(m+1,0);
        // vector<vector<int>> dp (n+1, vector<int> (m+1,0));
        
        for(int i = n-1;i>=0;i--){
            for(int j = m-1;j>=0;j--){
                int ans = 0;
                if(a[i] == b[j]) {
                    ans = max(ans , 1+ next[j+1]);
                }
                else{
                    ans = max(ans, next[j]);
                    ans = max(ans, curr[j+1]);
                }
                curr[j] = ans;
            }
            next = curr;
        }
        
        return curr[0];
    }
    int longestCommonSubsequence(string text1, string text2) {
        // int n = text1.size(), m = text2.size();
        // vector<vector<int>> dp (n+1, vector<int> (m+1,-1));
        return solveTab(text1, text2);
    }
};