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
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp (n+1, vector<int> (m+1,-1));
        return solve(text1, text2 , 0, 0,dp);
    }
};